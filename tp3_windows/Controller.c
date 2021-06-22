#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int response=-1;

	FILE* f=NULL;

	if(path!=NULL && pArrayListEmployee!=NULL){
		f=fopen(path,"r");
		if(f==NULL){
			printf("Error al intentar abrir el archivo\n");
			system("pause");
			exit(1);
		}
		else{
			if(!parser_EmployeeFromText(f, pArrayListEmployee)){
				response=0;
			}
		}
	}

	fclose(f);

    return response;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int response=-1;
	FILE* f=NULL;

	if(path!=NULL && pArrayListEmployee!=NULL){
		f=fopen(path,"rb");
		if(f!=NULL){
			if(!parser_EmployeeFromBinary(f, pArrayListEmployee)){
				response=0;
			}
		}
		else{
			printf("Error al intentar abrir el archivo\n");
			system("pause");
			exit(1);
		}
	}
	fclose(f);

    return response;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
	int response=-1;
	Employee* auxEmp=NULL;

	int option;
	char auxSueldo[40];
	char auxHoras[40];
	char auxId[40];
	char bufferNombre[128];
	float bufferSueldo;
	int bufferHoras;
	int newId;

	if(pArrayListEmployee){
		auxEmp=employee_new();
		if(auxEmp!=NULL){
			if(!utn_getNombre(bufferNombre,128,"Ingrese nombre empleado: \n","\nDato ingresado no es valido\n",5) &&
			   !utn_getNumeroFlotante(&bufferSueldo,"Ingrese sueldo: \n","\nDato ingresado no es valido\n",1,500000,5) &&
			   !utn_getNumero(&bufferHoras,"Ingrese horas trabajadas: \n","\nDato ingresado no es valido\n",1,500,5)){
					sprintf(auxSueldo,"%f",bufferSueldo);
					sprintf(auxHoras,"%d",bufferHoras);
					newId=*pId;
					newId++;
					sprintf(auxId,"%d",newId);
					auxEmp=employee_newParametros(auxId,bufferNombre,auxHoras,auxSueldo);
					printf("ID    Nombre Sueldo Horas\n");
					printf("------------------------------------\n");
					employee_printEmployee(auxEmp);
					if(!utn_getNumero(&option,"Ingrese [1] para CONFIRMAR ALTA o [2] para CANCELAR\n","Dato no valido",1,2,3)){
						if(option==1){
							ll_add(pArrayListEmployee,auxEmp);
							*pId=newId;
							response=0;
						}
						else{
							printf("Alta cancelada\n");
							auxEmp=NULL;
						}
					}
			}
		}
	}
    return response;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int response=-1;

	int auxId;
	int index;

	if(pArrayListEmployee!=NULL){
		if(!utn_getNumero(&auxId,"\nIngrese ID: ","\nDato no valido\n",1,10000,3)){
			index=employee_findById(pArrayListEmployee,auxId);
			if(index>=0){
				if(!employee_updateEmployee(pArrayListEmployee,index)){
					printf("Fin modificacion\n");
				}
			}
		}

	}

	return response;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int option;
    int indexDelete;
    int auxId;

    if(pArrayListEmployee){
    	//controller_ListEmployee(pArrayListEmployee);
    	if(!utn_getNumero(&auxId,"\nIngrese ID: ","\nDato no es valido\n",1,10000,5)){
			indexDelete=employee_findById(pArrayListEmployee,auxId);
			if(indexDelete>=0 &&
			   !utn_getNumero(&option,"Ingrese [1] para CONFIRMAR BAJA o [2] para CANCELAR\n","Dato no valido",1,2,3) &&
			   option==1){
				if(!employee_deleteIndex(pArrayListEmployee,indexDelete)){
					printf("Baja exitosa");
					response=0;
				}
				else{
					printf("Baja cancelada\n");
				}
			}
    	}
    }
    return response;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int response=-1;

    Employee* auxEmp=NULL;
    int flag=0;

    if(pArrayListEmployee!=NULL){
    	printf("ID - Nombre - Sueldo - Horas Trabajadas\n---------------------------------------------------------\n");
    	for(int i=0;i<ll_len(pArrayListEmployee);i++){
    		auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
    		if(auxEmp!=NULL){
    			employee_printEmployee(auxEmp);
    			flag=1;
    		}
    	}
    	if(flag==0){
    		printf("No hay empleados para mostrar\n");
    	}
    	response=0;
    }

    return response;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int response=-1;

    int option;

    if(pArrayListEmployee!=NULL){
    	if(!utn_getNumero(&option,"\nOrdenar por:\n[1] ID - [2] Nombre - [3] Sueldo - [4] Horas Trabajadas\n","Dato no es valido\n",1,4,5)){
    		switch(option){
				case 1:
					ll_sort(pArrayListEmployee,employee_cmpId,1);
					//controller_listEmployee(pArrayListEmployee);
					break;
				case 2:
					ll_sort(pArrayListEmployee,employee_cmpNombre,1);
					//controller_listEmployee(pArrayListEmployee);
					break;
				case 3:
					ll_sort(pArrayListEmployee,employee_cmpSueldo,1);
					//controller_listEmployee(pArrayListEmployee);
					break;
				case 4:
					ll_sort(pArrayListEmployee,employee_cmpHoras,1);
					//controller_listEmployee(pArrayListEmployee);
					break;
    		}
    		response=0;
    	}
    }
    return response;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int response=-1;

    int auxId;
    char auxNombre[128];
    int auxHoras;
    float auxSueldo;
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmp=NULL;
    FILE* f=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL){
    	f=fopen(path,"w");
    	if(f!=NULL){
    		response=0;
    		for(int i=0;i<len;i++){
    			auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
    			if(auxEmp!=NULL){
    				if(!employee_getId(auxEmp,&auxId) &&
    				   !employee_getNombre(auxEmp,auxNombre) &&
					   !employee_getHorasTrabajadas(auxEmp,&auxHoras) &&
    				   !employee_getSueldo(auxEmp,&auxSueldo)){
    						fprintf(f,"%d,%s,%d,%f\n",auxId,auxNombre,auxHoras,auxSueldo);
					   }
    			}
    		}
        	fclose(f);
    	}

    }
    return response;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int response=-1;
    int cant;
    int len=ll_len(pArrayListEmployee);
    FILE* f;

    if(pArrayListEmployee!= NULL && path != NULL ){
        f =fopen(path,"wb");
        if(f==NULL){
            printf("Ocurrio un problema\n");
        }
        else{
			for(int i=0;i<len;i++){
				cant=fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,f);
				if(cant<1){
					response=0;
				}
			}
        }
        fclose(f);
    }
    return response;
}


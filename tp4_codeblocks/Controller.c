#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_validaciones.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListEmployee)
{
    int response=-1;
    char pathIngresado[128];
    FILE* f=NULL;

    if(pArrayListEmployee!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .csv que desea cargar: \nSi no recuerda el path puede ingresar el archivo predeterminado data.csv\n","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"r");
            if(f==NULL){
                printf("No se encontro el archivo %s\n\n",pathIngresado);
            }
            else{
                if(!parser_EmployeeFromText(f,pArrayListEmployee)){
                    response=0;
                }
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
int controller_loadFromBinary(LinkedList* pArrayListEmployee)
{
	int response=-1;
	char pathIngresado[128];
	FILE* f=NULL;

	if(pArrayListEmployee!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .bin que desea cargar: \nSi no recuerda el path puede ingresar el archivo predeterminado data.bin\n","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"rb");
            if(f==NULL){
                printf("No se encontro el archivo %s\n",pathIngresado);
            }
            else{
                if(!parser_EmployeeFromBinary(f, pArrayListEmployee)){
                    response=0;
                }
                else{
                    printf("No se pudo abrir el archivo\n");
                }
            }
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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int response=-1;
    Employee* auxEmp=NULL;
    int newId;
    char nombre[128];
    int horas;
    float sueldo;

    if(pArrayListEmployee!=NULL){
        //employee_findNextId(pArrayListEmployee,&newId);
        newId=employee_readLastId();
        printf("ID NUEVO EMPLEADO: %d\n",newId);
        if(!utn_getNombre(nombre,128,"Ingrese nombre empleado: \n","\nDato ingresado no es valido\n",5) &&
           !utn_getNumeroFlotante(&sueldo,"Ingrese sueldo: \n","\nDato ingresado no es valido\n",1,500000,5) &&
           !utn_getNumero(&horas,"Ingrese horas trabajadas: \n","\nDato ingresado no es valido\n",1,500,5)){
               auxEmp=employee_new();
               if(!employee_setId(auxEmp,newId) &&
                  !employee_setNombre(auxEmp,nombre) &&
                  !employee_setHorasTrabajadas(auxEmp,horas) &&
                  !employee_setSueldo(auxEmp,sueldo)){
                    if(!ll_add(pArrayListEmployee,auxEmp)){
                        newId++;
                        employee_saveLastId(&newId);
                        printf("Nuevo Empleado: \n");
                        employee_printEmployee(auxEmp);
                        printf("\n");
                        response=0;
                    }
                  }
                else{
                    employee_delete(auxEmp);
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
        if(!utn_getNumero(&auxId,"Ingrese ID: ","\nDato no valido\n",1,10000,5)){
            index=employee_findById(pArrayListEmployee,auxId);
            if(index>=0){
                if(!employee_updateEmployee(pArrayListEmployee,index)){
                    printf("Modificacion terminada\n");
                    response=0;
                }
            }
            else{
                printf("No se encontro un empleado con el ID %d\n",auxId);
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
    Employee* auxEmp;
    int auxId;

    if(pArrayListEmployee!=NULL){
        if(!utn_getNumero(&auxId,"Ingrese ID: ","\nDato no valido\n",1,10000,5)){
            indexDelete=employee_findById(pArrayListEmployee,auxId);
            if(indexDelete>=0){
               auxEmp=(Employee*)ll_get(pArrayListEmployee,indexDelete);
               printf("ID   Nombre  Sueldo  Horas\n");
               employee_printEmployee(auxEmp);
               if(!utn_getNumero(&option,"\n[1] Confimar Baja Empleado\n[2] Cancelar\n","\nDato no valido\n",1,2,5) && option==1){
                    if(!employee_deleteIndex(pArrayListEmployee,indexDelete)){
                        printf("Baja exitosa\n");
                        response=0;
                    }
               }
            }
            else{
                printf("No se encontro un empleado con el ID %d\n",auxId);
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
        printf("\n");
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

        if(!utn_getNumero(&option,"Ordenar por: \n[1] ID - [2] Nombre - [3] Sueldo - [4] Horas Trabajadas\n","Dato no es valido\n",1,4,5)){
            switch(option){
                    case 1:
                        ll_sort(pArrayListEmployee,employee_cmpId,1);
                        printf("Empleados ordenados por ID\n");
                        break;
                    case 2:
                        ll_sort(pArrayListEmployee,employee_cmpNombre,1);
                        printf("Empleados ordenados por Nombre\n");
                        break;
                    case 3:
                        ll_sort(pArrayListEmployee,employee_cmpSueldo,1);
                        printf("Empleados ordenados por Sueldo\n");
                        break;
                    case 4:
                        ll_sort(pArrayListEmployee,employee_cmpHoras,1);
                        printf("Empleados ordenados por Horas Trabajadas\n");
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
int controller_saveAsText(LinkedList* pArrayListEmployee)
{
    int response=-1;
    char pathIngresado[128];
    int auxId;
    char auxNombre[128];
    int auxHoras;
    float auxSueldo;
    int confirma=1;
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmp=NULL;
    FILE* f=NULL;

    if(pArrayListEmployee!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .bin que desea guardar: ","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"r");
            if(f!=NULL){
                printf("Cuidado el archivo %s existe y se va a sobrescribir\n",pathIngresado);
                utn_getNumero(&confirma,"[1] Confirmar [2] Cancelar\n","\nError dato no valido\n",1,2,3);
            }
            fclose(f);
            if(confirma==2){
                printf("Save as binary cancelado\n");
                response=1;
            }
            else if(confirma){
                f=fopen(pathIngresado,"w");
                if(f==NULL){
                    printf("No se pudo abrir el archivo\n");
                }
                else{
                    for(int i=0;i<len;i++){
                        auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                        if(auxEmp!=NULL){
                            if(!employee_getId(auxEmp,&auxId) &&
                               !employee_getNombre(auxEmp,auxNombre) &&
                               !employee_getHorasTrabajadas(auxEmp,&auxHoras) &&
                               !employee_getSueldo(auxEmp,&auxSueldo)){
                                    fprintf(f,"%d,%s,%d,%f\n",auxId,auxNombre,auxHoras,auxSueldo);
                                    response=0;
                            }
                        }
                    }
                }
            }
        }
        fclose(f);
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
int controller_saveAsBinary(LinkedList* pArrayListEmployee)
{
    int response=-1;
    char pathIngresado[128];
    int cant;
    int confirma=1;
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmp;
    FILE* f;

    if(pArrayListEmployee!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .bin que desea guardar: ","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"rb");
            if(f!=NULL){
                printf("Cuidado el archivo %s existe y se va a sobrescribir\n",pathIngresado);
                utn_getNumero(&confirma,"[1] Confirmar [2] Cancelar\n","\nError dato no valido\n",1,2,3);
            }
            fclose(f);
            if(confirma==2){
                printf("Save as binary cancelado\n");
                response=1;
            }
            else if(confirma){
                f=fopen(pathIngresado,"wb");
                if(f==NULL){
                    printf("No se pudo abrir el archivo\n");
                }
                else{
                    for(int i=0;i<len;i++){
                        auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                        if(auxEmp!=NULL){
                            cant=fwrite(auxEmp,sizeof(Employee),1,f);
                            if(cant<1){
                                response=1;
                                break;
                            }
                            response=0;
                        }
                    }
                }
            }
            fclose(f);
        }
    }
    return response;
}


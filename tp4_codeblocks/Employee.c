#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn_validaciones.h"

/** \brief Constructor de nuevo empleado
 *
 * \return Employee* devuelve el nuevo empleado
 *
 */
Employee* employee_new()
{
	Employee* newEmp=(Employee*)malloc(sizeof(Employee));

    if(newEmp!=NULL){
    	newEmp->id=0;
        strcpy(newEmp->nombre," ");
        newEmp->horasTrabajadas=0;
        newEmp->sueldo=0;
    }
    return newEmp;
}

/** \brief Crea un nuevo empleado a partir de su constructor y carga sus campos con los datos ingresados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* nuevo empleado creado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* newEmp=employee_new();

    if(newEmp!=NULL){
    	if(!(!employee_setId(newEmp, atoi(idStr)) &&
             !employee_setNombre(newEmp, nombreStr) &&
             !employee_setHorasTrabajadas(newEmp, atoi(horasTrabajadasStr)) &&
             !employee_setSueldo(newEmp, atof(sueldoStr)))
             ){
        	    employee_delete(newEmp);
                newEmp=NULL;
             }
    }

    return newEmp;
}

/** \brief Elimina empleado y libera espacio
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
	if(this!=NULL){
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
    int response=-1;
    if(this!=NULL && id>=0){
        this->id=id;
        response=0;
    }
    return response;
}

int employee_getId(Employee* this,int* id)
{
    int response=-1;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        response=0;
    }
    return response;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        if(esNombre(nombre,128)){
            strncpy(this->nombre,nombre,128);
            response=0;
        }
    }
    return response;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        strncpy(nombre,this->nombre,128);
        response=0;
    }
    return response;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int response=-1;

    if(this!=NULL && horasTrabajadas>=0){
        this->horasTrabajadas=horasTrabajadas;
        response=0;
    }
    return response;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int response=-1;

    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        response=0;
    }
    return response;
}

int employee_setSueldo(Employee* this,float sueldo)
{
    int response=-1;

    if(this!=NULL && sueldo>=0){
        this->sueldo=sueldo;
        response=0;
    }
    return response;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int response=-1;

    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        response=0;
    }
    return response;
}

/** \brief Imprimir un empleado con sus campos
 *
 * \param pEmp Employee*
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int employee_printEmployee(Employee* pEmp)
{
    int response=-1;

    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;

    if(pEmp!=NULL &&
       !employee_getId(pEmp, &id) &&
       !employee_getNombre(pEmp, nombre) &&
       !employee_getSueldo(pEmp, &sueldo)&&
       !employee_getHorasTrabajadas(pEmp, &horasTrabajadas)){
            printf("%d %10s $%.2f %d\n",id,nombre,sueldo,horasTrabajadas);
             response=0;
    }
    return response;
}

/** \brief Busca un elemento en la lista por campo ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int -1 (Error) o i (indice encontrado si pudo hallarlo)
 *
 */
int employee_findById(LinkedList* pArrayListEmployee,int id)
{
	int response=-1;

	int len=ll_len(pArrayListEmployee);
	Employee* auxEmp=NULL;

    if(pArrayListEmployee!=NULL && len>0 && id>=0){
        for(int i=0;i<len;i++){
        	auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
            if(auxEmp->id==id){
                response=i;
                break;
            }
        }
    }
	return response;
}

/** \brief Elimina el index y remueve el empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int -1 (Error) o (Exito)
 *
 */
int employee_deleteIndex(LinkedList* pArrayListEmployee, int index)
{
    int response=-1;
    Employee* auxEmp=NULL;
    int len=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL && index>=0 && index<len){
    	auxEmp=(Employee*)ll_get(pArrayListEmployee,index);
    	if(auxEmp!=NULL){
    		ll_remove(pArrayListEmployee,index);
    		response=0;
    	}
    }

    return response;
}

/** \brief Comparar el campo id de dos elementos
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int 0 (Error) -1 (emp1 menor id a emp2) 1 (emp1 mayor sueldo a emp2)
 *
 */
int employee_cmpId(void* emp1, void* emp2)
{
	int response=0;

	Employee* auxEmp1=NULL;
	Employee* auxEmp2=NULL;

	if(emp1!=NULL && emp2!=NULL){
		auxEmp1=(Employee*)emp1;
		auxEmp2=(Employee*)emp2;
		if(auxEmp1->id>auxEmp2->id){
			response=1;
		}
		if(auxEmp1->id<auxEmp2->id){
			response=-1;
		}
	}
	return response;
}

/** \brief Comparar el campo nombre de dos elementos
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int el resultado devuelto por la funcion strcmp
 *
 */
int employee_cmpNombre(void* emp1, void* emp2)
{
	int response;

	Employee* auxEmp1=NULL;
	Employee* auxEmp2=NULL;

	if(emp1!=NULL && emp2!=NULL){
		auxEmp1=(Employee*)emp1;
		auxEmp2=(Employee*)emp2;
		response=strcmp(auxEmp1->nombre,auxEmp2->nombre);
	}
	return response;
}

/** \brief Comparar el campo sueldo de dos elementos
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int 0 (Error) -1 (emp1 mayor sueldo a emp2) 1 (emp1 menor sueldo a emp2)
 *
 */
int employee_cmpSueldo(void* emp1, void* emp2)
{
	int response=0;

	Employee* auxEmp1=NULL;
	Employee* auxEmp2=NULL;

	if(emp1!=NULL && emp2!=NULL){
		auxEmp1=(Employee*)emp1;
		auxEmp2=(Employee*)emp2;
		if(auxEmp1->sueldo<auxEmp2->sueldo){
			response=1;
		}
		if(auxEmp1->sueldo>auxEmp2->sueldo){
			response=-1;
		}
	}
	return response;
}

/** \brief Comparar el campo horas trabajadas de dos elementos
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int 0 (Error) -1 (emp1 menor horas a emp2) 1 (emp1 mayor horas a emp2)
 *
 */
int employee_cmpHoras(void* emp1, void* emp2)
{
	int response=0;

	Employee* auxEmp1=NULL;
	Employee* auxEmp2=NULL;

	if(emp1!=NULL && emp2!=NULL){
		auxEmp1=(Employee*)emp1;
		auxEmp2=(Employee*)emp2;
		if(auxEmp1->horasTrabajadas>auxEmp2->horasTrabajadas){
			response=1;
		}
		if(auxEmp1->horasTrabajadas<auxEmp2->horasTrabajadas){
			response=-1;
		}
	}
	return response;
}

/** \brief Permite encontrar el siguiente ID a ser utilizado, recorre un array de elementos y obtiene el mayor ID
 *
 * \param lista LinkedList*
 * \param id int*
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int employee_findNextId(LinkedList* lista, int* id)
{
    int todoOk=-1;
    Employee* auxEmp=NULL;
    int mayor;
    if(lista!=NULL){

        for(int i=0;i<ll_len(lista);i++){
            auxEmp=(Employee*)ll_get(lista,i);
            if(i==0 || auxEmp->id>mayor){
                mayor=auxEmp->id;
            }
        }
        *id=mayor+1;
        todoOk=0;
    }
    return todoOk;
}


/** \brief Despliega un menu de opciones para editar y modificar los campos de un empleado seleccionado
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int employee_updateEmployee(LinkedList* pArrayListEmployee, int index)
{
	int response=-1;

	int option;
	char auxNombre[128];
	float auxSueldo;
	int auxHoras;
	Employee* auxEmp=NULL;

	auxEmp=(Employee*)ll_get(pArrayListEmployee,index);
    if(auxEmp!=NULL){
         do{
              system("cls");
              printf("\n***** EMPLEADO SELECCIONADO: *****\n");
              printf("ID   Nombre  Sueldo  Horas\n");
              employee_printEmployee(auxEmp);
              printf("\nSeleccione el campo que desea modificar o 4 para Terminar:\n");
              if(!utn_getNumero(&option,"\n[1] Nombre - [2] Sueldo - [3] Horas Trabajadas - [4] Terminar\n","\nDato no valido",1,4,5)){
                switch(option){
                    case 1:
                        if(!utn_getNombre(auxNombre,128,"Ingrese nombre: \n","\nDato no es valido\n",5)){
                            employee_setNombre(auxEmp,auxNombre);
                            printf("Informacion Actualizada. Nombre: %s\n",auxEmp->nombre);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(!utn_getNumeroFlotante(&auxSueldo,"Ingrese el sueldo: \n","\nDato no valido\n",1,500000,5)){
                            employee_setSueldo(auxEmp,auxSueldo);
                            printf("Informacion Actualizada. Sueldo: %.2f\n",auxEmp->sueldo);
                            system("pause");
                        }
                        break;
                    case 3:
                        if(!utn_getNumero(&auxHoras,"Ingrese las horas trabajadas: \n","\nDato no valido\n",1,1000,5)){
                            employee_setHorasTrabajadas(auxEmp,auxHoras);
                            printf("Informacion Actualizada. Horas Trabajadas: %d\n",auxEmp->horasTrabajadas);
                            system("pause");
                        }
                        break;
                }
                response=0;
            }
         }while(option!=4);
    }
    return response;
}

/** \brief Recorre un array lista e imprime sus elementos (empleados)
 *
 * \param lista LinkedList*
 * \return int -1 (Error) o 0 (Exito)
 *
 */
int mostrarEmpleados(LinkedList* lista)
{
    int response=-1;
    Employee* auxEmp=NULL;
    if(lista!=NULL){
        printf("ID   Nombre Sueldo Horas\n");
        for(int i=0;i<ll_len(lista);i++){
            auxEmp=(Employee*)ll_get(lista,i);
            employee_printEmployee(auxEmp);
        }
        response=0;
    }
    return response;
}

int employee_saveLastId(int* id)
{
    int response=-1;
    FILE* f=fopen("lastId.txt","w");
    if(f!=NULL){
        fprintf(f,"%d",*id);
            response=0;
    }
    fclose(f);
    return response;
}

int employee_readLastId()
{
    int response=-1;
    int cant;
    char auxCad[10];
    int auxId;
    FILE* f=fopen("lastId.txt","r");
    if(f!=NULL){
        cant=fscanf(f,"%s",auxCad);
        if(cant){
            auxId=atoi(auxCad);
            response=auxId;
        }
    }
    fclose(f);
    return response;
}

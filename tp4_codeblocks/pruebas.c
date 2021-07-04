#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pruebas.h"
#include "utn_validaciones.h"
#include "Employee.h"

int prueba_llpush(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int auxId;
    int newId;
    int index;

    Employee* auxEmp=NULL;
    auxEmp=employee_new();

    if(pArrayListEmployee!=NULL){
        if(!utn_getNumero(&auxId,"Ingrese la posicion (ID de un empleado activo) en el que desea insertar elemento: ","\nDato no valido\n",0,10000,3)){
            employee_findNextId(pArrayListEmployee,&newId);
            index=employee_findById(pArrayListEmployee,auxId);
            auxEmp->id=newId;
            strcpy(auxEmp->nombre,"Push");
            auxEmp->horasTrabajadas=45;
            auxEmp->sueldo=1500;
            ll_push(pArrayListEmployee,index,auxEmp);
            response=0;
        }
    }
    return response;
}

int prueba_llset(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int auxId;
    int newId;
    int index;

    Employee* auxEmp=NULL;
    auxEmp=employee_new();

    if(pArrayListEmployee!=NULL){
        if(!utn_getNumero(&auxId,"Ingrese la posicion (ID de un empleado activo) en el que desea insertar elemento: ","\nDato no valido\n",0,10000,3)){
            employee_findNextId(pArrayListEmployee,&newId);
            index=employee_findById(pArrayListEmployee,auxId);
            auxEmp->id=newId;
            strcpy(auxEmp->nombre,"Set");
            auxEmp->horasTrabajadas=55;
            auxEmp->sueldo=4500;
            ll_set(pArrayListEmployee,index,auxEmp);
            response=0;
        }
    }
    return response;
}

int prueba_llpop(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int auxId;
    int index;

    if(pArrayListEmployee!=NULL){
        if(!utn_getNumero(&auxId,"Ingrese la posicion (ID de un empleado activo) que desea eliminar: ","\nDato no valido\n",0,10000,3)){
            index=employee_findById(pArrayListEmployee,auxId);
            ll_pop(pArrayListEmployee,index);
            response=0;
        }
    }
    return response;
}

int prueba_llindexOf(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int resultado;
    int index;
    int auxId;
    Employee* auxEmp=NULL;

    if(pArrayListEmployee!=NULL){
        if(!utn_getNumero(&auxId,"Ingrese el ID de un empleado activo: ","\nDato no valido\n",0,10000,3)){
            resultado=employee_findById(pArrayListEmployee,auxId);
            auxEmp=(Employee*)ll_get(pArrayListEmployee,resultado);
            index=ll_indexOf(pArrayListEmployee,auxEmp);
            employee_printEmployee(auxEmp);
            printf("Index en lista: %d\n",index);
            response=0;
        }

    }

    return response;
}

int prueba_llcontains(LinkedList* pArrayListEmployee)
{
    int response=-1;
    int auxId;
    int index;
    Employee* auxEmp=NULL;
    auxEmp=employee_new();

    if(pArrayListEmployee!=NULL){
        auxEmp->id=9999;
        strcpy(auxEmp->nombre,"Juan Carlos");
        auxEmp->horasTrabajadas=55;
        auxEmp->sueldo=4500;
        printf("\nSe genero un nuevo empleado de prueba no incluido en la lista para verificar\n\n");
        printf("ID   Nombre  Sueldo  Horas\n");
        employee_printEmployee(auxEmp);
        if(!ll_contains(pArrayListEmployee,auxEmp)){
            printf("\nNo se encontro el empleado %s en la lista\n\n",auxEmp->nombre);
            employee_delete(auxEmp);
            auxEmp=NULL;
        }

        if(!utn_getNumero(&auxId,"Ingrese ID de un empleado activo para verificar si se encuentra en lista: ","\nDato no valido\n",0,10000,3)){
            index=employee_findById(pArrayListEmployee,auxId);
            auxEmp=(Employee*)ll_get(pArrayListEmployee,index);
            printf("\n");
            if(ll_contains(pArrayListEmployee,auxEmp)){
                employee_printEmployee(auxEmp);
                printf("Se encuentra en la lista\n");
            }
        }

        response=0;
    }


    return response;

}

int prueba_llfunctions(LinkedList* pArrayListEmployee)
{
    int response=-1;
    LinkedList* listaPrueba=ll_newLinkedList();
    LinkedList* listaClon=ll_newLinkedList();
    if(listaPrueba==NULL){
		printf("Ocurrio un error al intentar crear LinkedList\n");
		system("pause");
		exit(1);
    }
    if(pArrayListEmployee!=NULL && listaPrueba!=NULL && listaClon!=NULL){
        printf("Se genera una nueva LinkedList y se verifica que esta vacia\n");
        if(ll_isEmpty(listaPrueba)){
            printf("La lista de prueba no contiene elementos\n");
        }
        printf("\nSe le asignan elementos de la lista principal a la lista de prueba generando una sublista\n");
        listaPrueba=ll_subList(pArrayListEmployee,25,40);
        mostrarEmpleados(listaPrueba);
        printf("\nSe comprueba que la lista principal contiene los elementos de la lista de prueba\n");
        if(ll_containsAll(pArrayListEmployee,listaPrueba)){
            printf("Contiene los elementos\n");
        }
        system("pause");

        printf("\n\nSe genera un la lista clon de la lista de prueba\n");
        listaClon=ll_clone(listaPrueba);
        mostrarEmpleados(listaClon);
        printf("\n");
        system("pause");

        printf("\n\nSe borran todos los elementos de la lista de prueba y de la lista clon\n");
        ll_clear(listaPrueba);
        ll_clear(listaClon);

        system("pause");

        printf("\n\nFinalmente se eliminan las LinkedList de lista de prueba y lista clon\n\n");
        ll_deleteLinkedList(listaPrueba);
        ll_deleteLinkedList(listaClon);
        response=0;
    }
    return response;
}

int prueba_llisEmpty(LinkedList* pArrayListEmployee)
{
    int response=-1;

    if(pArrayListEmployee!=NULL){
        if(!ll_isEmpty(pArrayListEmployee)){
            printf("La lista contiene elementos\n");
        }
        else{
            printf("La lista no contiene elementos\n");
        }
        response=0;
    }
    return response;
}


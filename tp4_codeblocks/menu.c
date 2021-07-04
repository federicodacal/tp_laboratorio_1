#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn_validaciones.h"

int menu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****SISTEMA DE GESTION*****\n");
    printf("------------------------------------------\n");
    printf("[1] Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("[2] Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("[3] Alta de Empleado\n");
    printf("[4] Modificar Datos De Empleado\n");
    printf("[5] Baja de empleado\n");
    printf("[6] Listar Empleados\n");
    printf("[7] Ordenar Empleados\n");
    printf("[8] Guardar los datos de los empleados en el archivo data.csv\n");
    printf("[9] Guardar los datos de los empleados en el archivo data.bin\n");
    printf("[10] SUBMENU PRUEBAS LinkedList\n");
    printf("------------------------------------------\n");
    printf("[11] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,11,5)==0){
        response=optionAux;
    }

    return response;
}

int submenuPruebas()
{
    int response=-1;
    int optionAux;

    system("cls");
    printf("\n*****PRUEBAS LINKEDLIST*****\n");
    printf("(las funciones ll_get, ll_sort, ll_add, ll_newLinkedList, ll_remove, ll_len fueron demostradas en el ABM)");
    printf("------------------------------------------\n");
    printf("[1] ll_push \n");
    printf("[2] ll_set \n");
    printf("[3] ll_pop\n");
    printf("[4] ll_indexOf\n");
    printf("[5] ll_isEmpty\n");
    printf("[6] ll_contains\n");
    printf("[7] ll_containsAll, ll_sublist, ll_clone, ll_clear, ll_deleteLinkedList\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,7,5)==0){
        response=optionAux;
    }

    return response;
}

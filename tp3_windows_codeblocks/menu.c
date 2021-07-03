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
    printf("------------------------------------------\n");
    printf("[10] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,10,10)==0){
        response=optionAux;
    }

    return response;
}

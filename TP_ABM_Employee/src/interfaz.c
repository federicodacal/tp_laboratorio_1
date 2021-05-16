#include <stdio.h>
#include <stdlib.h>
#include "utn_validaciones.h"
#include "interfaz.h"

/** \brief Menu Principal
 *
 * \return int -1 (Error) 0 (Ok)
 *
 */
int menu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****SISTEMA DE GESTION DE EMPLEADOS*****\n");
    printf("------------------------------------------\n");
    printf("[1] ALTA Empleado\n");
    printf("[2] MODIFICAR Empleado\n");
    printf("[3] BAJA Empleado\n");
    printf("[4] INFOMRES\n");
    printf("------------------------------------------\n");
    printf("[5] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,5,10)==0){
        response=optionAux;
    }

    return response;
}

/** \brief Menu de informes
 *
 * \return int -1 (Error) 0 (Ok)
 *
 */
int listsMenu()
{
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****INFORMES*****\n");
    printf("------------------------------------------\n");
    printf("[1] LISTAR EMPLEADOS POR APELLIDO Y SECTOR\n");
    printf("[2] SALARIOS\n");
    printf("------------------------------------------\n");
    printf("[3] Volver\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,3,10)==0){
        response=optionAux;
    }

    return response;
}


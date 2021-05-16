/*
 ============================================================================
 Name        : TP_ABM_Employee.c
 Author      : Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"
#include "sector.h"
#include "datawarehouse.h"

#define EMPLOYEES_LEN 1000
#define SECTORS_LEN 5

int menu();
int listsMenu();

int main()
{
	setbuf(stdout, NULL);

    int option;
    int option2;
    int option3;
    char exit='n';
    int nextId=1;
    int responseAdd;
    int resposeRemove;
    int responseUpdate;
    int flag=0;

    Sector sectors[SECTORS_LEN]={
    {500, "Sistemas"},
    {501, "Legales"},
    {502, "RRHH"},
    {503, "Gestion"},
    {504, "Ventas"}
    };

    Employee list[EMPLOYEES_LEN];
    initEmployees(list, EMPLOYEES_LEN);

    hcodeEmployees(list, EMPLOYEES_LEN, 20, &nextId);

    do{
        option=menu();
        if(option!=-1){
            switch(option){
                case 1:
                    system("cls");
                    printf("\n*****GESTIONAR ALTA de EMPLEADO*****\n");
                    printf("-------------------------------------\n");
                    responseAdd=addEmployee(list, EMPLOYEES_LEN, sectors, SECTORS_LEN, &nextId);
                    if(!responseAdd){
                        printf("ALTA EXITOSA\n\n");
                        flag=1;
                    }
                    else{
                        printf("No se realizó la alta\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(flag){
                        system("cls");
                        printf("\n*****GESTIONAR MODIFICACION de EMPLEADO*****\n");
                        printf("-------------------------------------\n");
                        responseUpdate=updateEmployee(list, EMPLOYEES_LEN, sectors, SECTORS_LEN);
                        if(!responseUpdate){
                            printf("Modificacion exitosa\n\n");
                        }
                        else{
                            printf("Ocurrio un problema\n\n");
                        }
                    }
                    else{
                        printf("\nPrimero debes realizar la carga de un empleado\n\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(flag){
                        system("cls");
                        printf("\n*****GESTIONAR BAJAR de EMPLEADO*****\n");
                        printf("-------------------------------------\n");
                        resposeRemove=removeEmployee(list, EMPLOYEES_LEN, sectors, SECTORS_LEN);
                        if(!resposeRemove){
                            printf("BAJA EXITOSA\n\n");
                        }
                        else{
                            printf("No se realizo la baja\n\n");
                        }
                    }
                    else{
                        printf("\nPrimero debes realizar la carga de un empleado\n\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(flag){
                        option2=listsMenu();
                        if(option2!=-1){
                            switch(option2){
                                case 1:
                                    system("cls");
                                    printf("\n***** EMPLEADOS POR APELLIDO Y SECTOR*****\n");
                                    printf("-------------------------------------------\n");
                                    utn_getNumero(&option3,"[1] Para listar por orden A-Z - [2] Para listar por orden Z-A - [3] Para listar por Sector\n","Dato no valido",1,3,5);

                                    break;
                                case 2:
                                    system("cls");
                                    printf("\n*****INFORMES SALARIOS*****\n");
                                    printf("-------------------------------------------\n");
                                    getTotalSalaries(list, EMPLOYEES_LEN);
                                    getAvgSalary(list, EMPLOYEES_LEN);
                                    getEmployeesAboveAvgSalary(list, EMPLOYEES_LEN);
                                    break;
                                case 3:
                                    printf("Regresar al menu principal\n");
                                    break;
                                }
                        }

                    }
                    else{
                        printf("\nPrimero debes realizar la carga de un empleado\n\n");
                    }
                    system("pause");
                    break;
                case 5:
                    printf("Confirmar salida: s/n");
                    fflush(stdin);
                    exit=getchar();
                    break;
                }
        }
    }while(exit!='s');

    return 0;
}


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

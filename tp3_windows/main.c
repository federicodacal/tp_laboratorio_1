#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
	setbuf(stdout, NULL);

	int option;
	char salir='n';
	int nextId=1000;
	int flag=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados==NULL){
		printf("Ocurrio un error al intentar crear LinkedList\n");
		system("pause");
		exit(1);
    }
	do{
		option=menu();
		if(option!=-1){
			switch(option)
			{
				case 1:
					if(!controller_loadFromText("data.csv",listaEmpleados)){
						printf("Empleados fueron cargados con exito\n");
						flag=1;
					}
					else{
						printf("Ocurrio un problema\n");
					}
					break;
				case 2:
					if(!controller_loadFromBinary("data.bin",listaEmpleados)){
						printf("Empleados fueron cargados con exito\n");
						flag=1;
					}
					else{
						printf("Ocurrio un problema\n");
					}
					break;
				case 3:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_addEmployee(listaEmpleados, &nextId);
					}
					break;
				case 4:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_editEmployee(listaEmpleados);
					}
					break;
				case 5:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_removeEmployee(listaEmpleados);
					}
					break;
				case 6:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");

					}
					else{
						system("cls");
						controller_ListEmployee(listaEmpleados);
						system("pause");
					}
					break;
				case 7:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_sortEmployee(listaEmpleados);
					}
					break;
				case 8:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_saveAsText("data.csv", listaEmpleados);
					}
					break;
				case 9:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_saveAsBinary("data.bin", listaEmpleados);
					}
					break;
				case 10:
                    printf("Confirmar salida: s/n ");
                    fflush(stdin);
                    salir=getchar();
                    break;
			}
		}
	}while(salir!='s');
    return 0;
}

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


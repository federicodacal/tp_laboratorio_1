#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "pruebas.h"
#include "utn_validaciones.h"

int main()
{
	int option;
	int option2;
	char salir='n';
	int flag=0;
	int flagBin=0;

    LinkedList* listaEmpleados=ll_newLinkedList();

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
					if(!controller_loadFromText(listaEmpleados)){
						printf("Empleados fueron cargados con exito\n\n");
						flag=1;
					}
					else{
						printf("Ocurrio un problema\n");
					}
					system("pause");
					break;
				case 2:
				    if(!flagBin){
                        printf("Para cargar el archivo desde bin primero debe guardalo como .bin\n");
				    }
				    else{
                        if(!controller_loadFromBinary("data.bin",listaEmpleados)){
                            printf("Empleados fueron cargados con exito\n");
                        }
                        else{
                            printf("Ocurrio un problema\n");
                        }
				    }
				    system("pause");
					break;
				case 3:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_addEmployee(listaEmpleados);
					}
					system("pause");
					break;
				case 4:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_editEmployee(listaEmpleados);
					}
					system("pause");
					break;
				case 5:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_removeEmployee(listaEmpleados);
					}
					system("pause");
					break;
				case 6:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");

					}
					else{
						system("cls");
						controller_ListEmployee(listaEmpleados);
					}
                    system("pause");
					break;
				case 7:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						controller_sortEmployee(listaEmpleados);
					}
					system("pause");
					break;
				case 8:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						if(!controller_saveAsText("data.csv", listaEmpleados)){
                            printf("La lista se guardo exitosamente en el archivo data.csv\n");
						}
					}
					system("pause");
					break;
				case 9:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						if(!controller_saveAsBinary("data.bin", listaEmpleados)){
                            printf("La lista se guardo exitosamente en el archivo data.bin\n");
                            flagBin=1;
						}
					}
                    system("pause");
					break;
                case 10:
                    option2=submenuPruebas();
                    switch(option2){
                    case 1:
                        if(!prueba_llpush(listaEmpleados)){
                            printf("ll_push exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 2:
                        if(!prueba_llset(listaEmpleados)){
                            printf("ll_set exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 3:
                        if(!prueba_llpop(listaEmpleados)){
                            printf("ll_pop exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 4:
                        if(!prueba_llindexOf(listaEmpleados)){
                            printf("ll_indexOf exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 5:
                        if(!prueba_llisEmpty(listaEmpleados)){
                            printf("ll_isEmpty exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 6:
                        if(!prueba_llcontains(listaEmpleados)){
                            printf("ll_contains exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    case 7:
                        if(!prueba_llfunctions(listaEmpleados)){
                            printf("ll_containsAll exitoso\n");
                        }
                        else{
                            printf("Hubo un error\n");
                        }
                        system("pause");
                        break;
                    }
                    break;
                case 11:
                    printf("Confirmar salida: s/n ");
                    fflush(stdin);
                    salir=getchar();
                    break;
			}
		}
	}while(salir!='s');
    return 0;
}

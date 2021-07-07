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
	//int flagBin=0;
    int flagWarning=0;

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
				    if(flag){
                        printf("Ya hay un archivo cargado\n");
				    }
				    else{
                        if(!controller_loadFromText(listaEmpleados)){
                            printf("Empleados fueron cargados con exito\n\n");
                            flag=1;
                        }
                        else{
                            printf("Ocurrio un problema\n");
                        }
				    }
					system("pause");
					break;
				case 2:
				    if(flag){
                        printf("Ya hay un archivo cargado\n");
				    }
				    else{
                        if(!controller_loadFromBinary(listaEmpleados)){
                            printf("Empleados fueron cargados con exito\n\n");
                            flag=1;
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
						if(!controller_addEmployee(listaEmpleados)){
                            flagWarning=1;
						}
					}
					system("pause");
					break;
				case 4:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						if(!controller_editEmployee(listaEmpleados)){
                            flagWarning=1;
						}
					}
					system("pause");
					break;
				case 5:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						if(!controller_removeEmployee(listaEmpleados)){
                            flagWarning=1;
						}
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
						if(!controller_saveAsText(listaEmpleados)){
                            printf("La lista se guardo exitosamente en el archivo .csv\n");
                            flagWarning=0;
						}
					}
					system("pause");
					break;
				case 9:
					if(!flag){
						printf("Primero debe cargar el archivo de empleados\n");
					}
					else{
						if(!controller_saveAsBinary(listaEmpleados)){
                            printf("La lista se guardo exitosamente en el archivo .bin\n");
                            flagWarning=0;
						}
					}
                    system("pause");
					break;
                case 10:
                    if(!flag){
                        printf("Primero debe cagar el archivo de empleados\n");
                    }
                    else{
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
                                printf("Prueba exitosa\n");
                            }
                            else{
                                printf("Hubo un error\n");
                            }
                            system("pause");
                            break;
                        }
                    }
                    break;
                case 11:
                    if(flagWarning){
                        printf("Quedaron cambios sin guardar. Esta seguro que desea salir?\nConfirmar salida: s/n\n\n");
                        fflush(stdin);
                        salir=getchar();
                    }
                    else{
                        printf("Confirmar salida: s/n ");
                        fflush(stdin);
                        salir=getchar();
                    }
                    break;
			}
		}
	}while(salir!='s');
    return 0;
}

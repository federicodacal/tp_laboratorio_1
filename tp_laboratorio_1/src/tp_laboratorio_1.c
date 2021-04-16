/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utndacal_operaciones.h"
#include "utndacal_interfaz.h"
#include "utndacal_validaciones.h"

int main(void)
{
	setbuf(stdout,NULL);

    int x;
    int y;
    char salida='n';
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    int factorialA;
    int factorialB;
    int flagNum1=0;
    int flagNum2=0;
    int flagOperaciones=0;

    do{
        switch(menu(&flagNum1, &flagNum2, x, y)){
        case 1:
            if(flagOperaciones==0){
                system("cls");
                printf("\n1.Ingresar 1er operando (a=x):\n");
                while(getNumero(&x,"\nEl valor ingresado no es valido\n\n",-100000,100000)!=0){
                    system("cls");
                    printf("\n1.Ingresar 1er operando (a=x):\n");
                }
            flagNum1=1;
            }
            else{
                system("cls");
                printf("\nLas operaciones ya fueron realizadas, antes de cambiar los valores se deben mostrar los resultados\n\n");
                system("pause");
            }
            break;
        case 2:
            if(flagOperaciones==0){
                if(flagNum1==1){
                    system("cls");
                    printf("\n2.Ingresar 2do operando (b=y):\n");
                    while(getNumero(&y,"\nEl valor ingresado no es valido\n\n",-100000,100000)!=0){
                        system("cls");
                        printf("\n2.Ingresar 2do operando (b=y):\n");
                }
                flagNum2=1;
            }
                else{
                    system("cls");
                    printf("\nPara poder ingresar el 2do operando es necesario que antes se ingrese el 1ero\n\n");
                    system("pause");
                }
            }
            else{
                system("cls");
                printf("\nLas operaciones ya fueron realizadas, antes de cambiar los valores se deben mostrar los resultados\n\n");
                system("pause");
            }

            break;
        case 3:
            if(flagNum2==1){
                sumarInt(x,y,&resultadoSuma);
                restarInt(x,y,&resultadoResta);
                dividirInt(x,y,&resultadoDivision);
                multiplicarInt(x,y,&resultadoMultiplicacion);
                factorialInt(x, &factorialA);
                factorialInt(y, &factorialB);
                system("cls");
                printf("\nSe realizaron las siguientes operaciones:\n\n");
                printf("a)Calcular la suma (%d+%d)\nb)Calcular la resta (%d-%d)\nc)Calcular la division (%d/%d)\nd)Calcular la multiplicacion (%d*%d)\ne)Calcular el factorial (%d!, %d!)\n\n",x,y,x,y,x,y,x,y,x,y);
                system("pause");
                flagOperaciones=1;
            }
            else{
                system("cls");
                printf("\nAntes de realizar las operaciones se deben ingresar ambos operandos\n\n");
                system("pause");
            }
            break;
        case 4:
            if(flagOperaciones==1){
                mostrarResultados(x,y,resultadoSuma,resultadoResta,resultadoDivision,resultadoMultiplicacion,factorialA,factorialB);
                resetFlags(&flagNum1,&flagNum2,&flagOperaciones);
            }
            else{
                system("cls");
                printf("\nPara mostrar los resultados primero es necesario realizar las operaciones\n\n");
                system("pause");
            }
            break;
        case 5:
            system("cls");
            printf("\nPara confirmar salida ingrese 's' o ingrese otro caracter para regresar al menu: \n\n");
            salida=getchar();
            system("pause");
            break;
        }
    }while(salida!='s');

	return EXIT_SUCCESS;
}

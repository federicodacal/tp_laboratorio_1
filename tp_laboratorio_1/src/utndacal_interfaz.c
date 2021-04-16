#include <stdio.h>
#include <stdlib.h>
#include "utndacal_operaciones.h"
#include "utndacal_validaciones.h"

int resetFlags(int* pFlag1, int* pFlag2, int* pFlag3)
{
    int function_success=-1;
    if(pFlag1!=NULL && pFlag2!=NULL && pFlag3!=NULL){
        *pFlag1=0;
        *pFlag2=0;
        *pFlag3=0;
        function_success=0;
    }
    return function_success;
}


int menu(int* pFlag1, int* pFlag2, int a, int b)
{
    int respuesta;

    system("cls");
    printf("\t*****MENU DE OPCIONES*****\n");
    printf("\t _____________________ \n");
    printf("\t|  _________________  |\n");
    printf("\t| |                 | |\n");
    printf("\t| |_________________| |\n");
    printf("\t|  ___ ___ ___   ___  |\n");
    printf("\t| | 7 | 8 | 9 | | + | |\n");
    printf("\t| |___|___|___| |___| |\n");
    printf("\t| | 4 | 5 | 6 | | - | |\n");
    printf("\t| |___|___|___| |___| |\n");
    printf("\t| | 1 | 2 | 3 | | x | |\n");
    printf("\t| |___|___|___| |___| |\n");
    printf("\t| | ! | 0 | = | | / | |\n");
    printf("\t| |___|___|___| |___| |\n");
    printf("\t|_____________________|\n");
    if(*pFlag2==0 && *pFlag1==1){
        printf("\n1.Ingresar 1er operando (a=%d)\n2.Ingresar 2do operando (b=y)\n3.Calcular todas las operaciones\n\ta)Calcular la suma (%d+b)\n\tb)Calcular la resta (%d-b)\n\tc)Calcular la division (%d/b)\n\td)Calcular la multiplicacion (%d*b)\n\te)Calcular el factorial (%d!, b!)\n4.Informar resultados\n5.Salir\n", a,a,a,a,a,a);
    }
    else if(*pFlag2==1 && *pFlag1==1){
        printf("\n1.Ingresar 1er operando (a=%d)\n2.Ingresar 2do operando (b=%d)\n3.Calcular todas las operaciones\n\ta)Calcular la suma (%d+%d)\n\tb)Calcular la resta (%d-%d)\n\tc)Calcular la division (%d/%d)\n\td)Calcular la multiplicacion (%d*%d)\n\te)Calcular el factorial (%d!, %d!)\n4.Informar resultados\n5.Salir\n", a,b,a,b,a,b,a,b,a,b,a,b);
    }
    else{
        printf("\n1.Ingresar 1er operando (a=x)\n2.Ingresar 2do operando (b=y)\n3.Calcular todas las operaciones\n\ta)Calcular la suma (a+b)\n\tb)Calcular la resta (a-b)\n\tc)Calcular la division (a/b)\n\td)Calcular la multiplicacion (a*b)\n\te)Calcular el factorial (a!, b!)\n4.Informar resultados\n5.Salir\n");
    }

    printf("\nIngrese una opcion: \n");

    getNumero(&respuesta,"\nEl valor ingresado no es valido\n\n",1,5);
    return respuesta;
}

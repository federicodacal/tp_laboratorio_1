#include <stdio.h>
#include <stdlib.h>
#include "utndacal_interfaz.h"
#include "utndacal_validaciones.h"

int sumarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a+b;
        function_success=0;
    }
    return function_success;
}

int restarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a-b;
        function_success=0;
    }
    return function_success;
}

int dividirInt(int a,int b,float* resultado)
{
    int function_success=-1;
    if(resultado!=NULL && b!=0){
        *resultado=(float)a/b;
        function_success=0;
    }
    return function_success;
}

int multiplicarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a*b;
        function_success=0;
    }
    return function_success;
}

int factorialInt(int a, int* factorial)
{
    int function_success=-1;
    *factorial=1;
    if(factorial!=NULL && a>0 && a<17){
        for(int i=1;i<=a;i++){
            *factorial*=i;
        }
        function_success=0;
    }
    return function_success;
}

void mostrarResultados(int a, int b, int suma, int resta, float division, int multiplicacion, int factorialX, int factorialY)
{
    system("cls");
    printf("\na) El resultado de %d+%d es: %d",a,b,suma);
    printf("\nb) El resultado de %d-%d es: %d",a,b,resta);
    if(b==0){
        printf("\nc) No se pudo completar la operacion. La division por 0 no esta definida");
    }
    else{
        printf("\nc) El resultado de %d/%d es: %.2f",a,b,division);
    }
    printf("\nd) El resultado de %d*%d es: %d",a,b,multiplicacion);
    if(a<17 && a>0){
        printf("\ne) El factorial de %d es: %d",a,factorialX);
    }
    else if(a<0){
        printf("\ne)No se pudo completar el factorial de %d. No es posible realizar el factorial de un numero negativo.",a);
    }
    else{
        printf("\ne) No se pudo completar el factorial de %d. El mayor factorial soportado es el de 16.",a);
    }
    if(b<17 && b>0){
        printf("\nEl factorial de %d es: %d",b,factorialY);
    }
    else if(b<0){
        printf("\nNo se pudo completar el factorial de %d. No es posible realizar el factorial de un numero negativo.",b);
    }
    else{
        printf("\n No se pudo completar el factorial de %d. El mayor factorial soportado es el de 16.",b);
    }
    printf("\n\n");
    system("pause");
}


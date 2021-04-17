#include <stdio.h>
#include <stdlib.h>
#include "utndacal_interfaz.h"
#include "utndacal_validaciones.h"

/** \brief sumarInt funcion que toma dos numeros enteros (a y b) y realiza la suma a+b.
 *
 * \param a int primer entero recibido
 * \param b int segundo entero recibido
 * \param resultado int* puntero que guarda en direccion de memoria el resultado de la operacion
 * \return int function_success=0 en caso de completar la operacion satisfactoriamente o function_success=-1 si no pudo completarse correctamente
 */
int sumarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a+b;
        function_success=0;
    }
    return function_success;
}

/** \brief restarInt funcion que toma dos numeros enteros (a y b) y realiza la resta a-b.
 *
 * \param a int primer entero recibido
 * \param b int segundo entero recibido
 * \param resultado int* puntero que guarda en direccion de memoria el resultado de la operacion
 * \return int function_success=0 en caso de completar la operacion satisfactoriamente o function_success=-1 si no pudo completarse correctamente
 */
int restarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a-b;
        function_success=0;
    }
    return function_success;
}

/** \brief dividirInt funcion que toma dos numeros enteros (a y b) y realiza la division a/b.
 *
 * \param a int primer entero recibido
 * \param b int segundo entero recibido
 * \param resultado float* puntero que guarda en direccion de memoria el resultado de la operacion
 * \return int function_success=0 en caso de completar la operacion satisfactoriamente o function_success=-1 si no pudo completarse correctamente
 */
int dividirInt(int a,int b,float* resultado)
{
    int function_success=-1;
    if(resultado!=NULL && b!=0){
        *resultado=(float)a/b;
        function_success=0;
    }
    return function_success;
}

/** \brief dividirInt funcion que toma dos numeros enteros (a y b) y realiza la multiplicacion a*b.
 *
 * \param a int primer entero recibido
 * \param b int segundo entero recibido
 * \param resultado int* puntero que guarda en la direccion de memoria el resultado de la operacion
 * \return int function_success=0 en caso de completar la operacion satisfactoriamente o function_success=-1 si no pudo completarse correctamente
 */
int multiplicarInt(int a,int b,int* resultado)
{
    int function_success=-1;
    if(resultado!=NULL){
        *resultado=a*b;
        function_success=0;
    }
    return function_success;
}

/** \brief factorialInt funcion que calcula el factorial de un numero entero a!
 *
 * \param a int entero que recibe y sobre el cual se calcula el factorial
 * \param factorial int* puntero que guarda en direccion de memoria el resultado de la operacion
 * \return int function_success=0 en caso de completar la operacion satisfactoriamente o function_success=-1 si no pudo completarse correctamente
 */
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

/** \brief mostrarResultadoSuma funcion que muestra el resultado de la suma de dos numeros enteros
 *
 * \param a int primero entero recibido
 * \param b int segundo entero recibido
 * \param int suma el resultado de la suma previamente realizada
 * \return void
 *
 */
void mostrarResultadoSuma(int a, int b, int suma)
{
    printf("\na) El resultado de %d+%d es: %d",a,b,suma);
}

/** \brief mostrarResultadoResta funcion que muestra el resultado de la resta de dos numeros enteros
 *
 * \param a int primero entero recibido
 * \param b int segundo entero recibido
 * \param int resta el resultado de la resta previamente realizada
 * \return void
 *
 */
void mostrarResultadoResta(int a, int b, int resta)
{
    printf("\nb) El resultado de %d-%d es: %d",a,b,resta);
}

/** \brief mostrarResultadoDivision funcion que muestra el resultado de la division de dos numeros enteros
 *
 * \param a int primero entero recibido
 * \param b int segundo entero recibido
 * \param float division el resultado de la division previamente realizada
 * \return void
 *
 */
void mostrarResultadoDivision(int a, int b, float division)
{
    if(b==0){
        printf("\nc) No se pudo completar la operacion. La division por 0 no esta definida");
    }
    else{
        printf("\nc) El resultado de %d/%d es: %.2f",a,b,division);
    }
}

/** \brief mostrarResultadoMultiplicacion funcion que muestra el resultado de la multiplicacion de dos numeros enteros
 *
 * \param a int primero entero recibido
 * \param b int segundo entero recibido
 * \param int multiplicacion el resultado de la multiplicacion previamente realizada
 * \return void
 *
 */
void mostrarResultadoMultiplicacion(int a, int b, int multiplicacion)
{
    printf("\nd) El resultado de %d*%d es: %d",a,b,multiplicacion);
}


/** \brief mostrarResultadoFactorial funcion que muestra el resultado de la operacion factorial realizado sobre un numero entero
 *
 * \param a int entero recibido (sobre el que se realizo el factorial)
 * \param factorialX int resultado del factorial
 * \return void
 *
 */
void mostrarResultadoFactorial(int a, int factorialX)
{
    if(a<17 && a>=0){
        printf("\ne) El factorial de %d es: %d",a,factorialX);
    }
    else if(a<0){
        printf("\ne) No se pudo completar el factorial de %d. No es posible realizar el factorial de un numero negativo.",a);
    }
    else{
        printf("\ne) No se pudo completar el factorial de %d. El mayor factorial soportado es el de 16.",a);
    }
}




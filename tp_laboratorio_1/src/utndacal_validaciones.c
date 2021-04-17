#include <stdio.h>
#include <stdlib.h>
#include "utndacal_interfaz.h"
#include "utndacal_operaciones.h"

/** \brief getNumero funcion que permite la validacion de un numero entero ingresado. En caso de no ser un dato valido muestra un mensaje de error.
 *
 * \param pResultado int* puntero que guarda en la direccion de memoria el dato ingresado en caso de ser valido
 * \param mensajeError char* mensaje de error mostrado en caso de ingresar un dato no valido.
 * \param minimo int el numero de valor minimo permitido
 * \param maximo int el numero de valor maximo permitido
 * \return int function_success=-1 en caso de no haber podido obtener un numero valido, function_success=0 si pudo obtenerlo de manera correcta
 *
 */
int getNumero(int* pResultado, char* mensajeError, int minimo, int maximo)
{
	int function_success=-1;
	int buffer;	// Area de intercambio con usuario

	if(pResultado!=NULL && mensajeError!=NULL && minimo<=maximo){

        scanf("%d", &buffer);

        if(buffer>=minimo && buffer<=maximo){
            *pResultado=buffer;
            function_success=0;
        }
        else{
            printf("%s", mensajeError);
            system("pause");
        }
        fflush(stdin);
	}
	return function_success;
}

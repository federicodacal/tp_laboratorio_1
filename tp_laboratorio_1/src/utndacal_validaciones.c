#include <stdio.h>
#include <stdlib.h>
#include "utndacal_interfaz.h"
#include "utndacal_operaciones.h"

int getNumero(int* pResultado, char* mensajeError, int minimo, int maximo)
{
	int function_success=-1; // Valor de retorno (cargada con 'error' -1, en este caso significa que no obtuvo el numero)
	int buffer;	// Area de intercambio con usuario

	if(pResultado!=NULL && mensajeError!=NULL && minimo<=maximo){

        scanf("%d", &buffer);

        if(buffer>=minimo && buffer<=maximo){
            *pResultado=buffer;
            function_success=0; // Perfecto!
        }
        else{
            printf("%s", mensajeError);
            system("pause");
        }
        fflush(stdin);
	}
	return function_success;
}

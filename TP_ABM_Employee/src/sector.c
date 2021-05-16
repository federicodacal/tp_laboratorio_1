#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "sector.h"

int cargarDescripcionSector(int id, Sector sectors[], int secLen, char descrip[])
{
    int function_success=0;

    if(id>=500 && id<=504 && sectors!=NULL && secLen>0 && descrip!=NULL){
        for (int i=0;i<secLen;i++){
            if(sectors[i].id==id){
                strcpy(descrip,sectors[i].description);
                function_success=1;
                break;
            }
        }

    }
    return function_success;
}

int printSectors(Sector sectors[], int secLen)
{
    int response=-1;
    printf("    *****LISTA DE SECTORES*****\n");
    printf("        id  Descripcion\n");
    if(sectors!=NULL && secLen>0){
        for(int i=0;i<secLen;i++){
            printSector(sectors[i]);
        }
    printf("\n");
    response=0;
    }
    return response;
}

void printSector(Sector sec)
{
    printf("        %d  %10s\n", sec.id, sec.description);
}


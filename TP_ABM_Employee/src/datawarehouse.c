#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char names[20][20]={
    "Donato",
    "Carmen",
    "Chepi",
    "Alex",
    "German",
    "Maria",
    "Damian",
    "Daniel",
    "Andrea",
    "Candela",
    "Dario",
    "Camila",
    "Cecilia",
    "Alan",
    "Gaston",
    "Mariana",
    "David",
    "Roberto",
    "Anna",
    "Lucrecia"
};

char lastNames[20][20]={
    "De Sanctis",
    "Miranda",
    "Viaggi",
    "Caniggia",
    "Martin",
    "Rosas",
    "Betular",
    "Araoz",
    "Rincon",
    "Vetrano",
    "Rodriguez",
    "Rossellini",
    "Torres",
    "Carter",
    "Gunther",
    "Martinez",
    "Di Leo",
    "Gomez",
    "Martel",
    "Arendt"
};


float salaries[20]={1000,1000,1420,1350,2000,1950,2150,1060,1742,1800,1000,1000,1420,1350,2000,1950,2150,1060,1742,1800};

int idSectors[20]={500,504,501,501,502,503,502,504,502,500,500,504,501,501,502,503,502,504,502,500};

int ids[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

/** \brief Carga una lista predeterminada a lista de employees
 *
 * \param list[] Employee
 * \param len int
 * \param qty int
 * \param pId int*
 * \return int Lugares ocupados
 *
 */
int hcodeEmployees(Employee list[], int len, int qty, int* pId)
{
    int places=0;

    if(list!=NULL && len>0 && qty>=0 && qty<=len && pId!=NULL){
        for(int i=0;i<qty;i++){
            list[i].id=*pId;
            (*pId)++;
            strncpy(list[i].name, names[i],sizeof(list[i].name));
            strncpy(list[i].lastName, lastNames[i],sizeof(list[i].lastName));
            list[i].salary=salaries[i];
            list[i].idSector=idSectors[i];
            list[i].isEmpty=0;
            places++;
        }
    }

    return places;
}

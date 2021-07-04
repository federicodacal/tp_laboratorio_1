#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int response=-1;
    Employee* auxEmp=NULL;
    char auxBuffer[4][128];
    int cant;

    if(pFile!=NULL && pArrayListEmployee!=NULL){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3]);
        while(!feof(pFile)){
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%s", auxBuffer[0], auxBuffer[1], auxBuffer[2], auxBuffer[3]);
            if(cant==4){
                auxEmp=employee_newParametros(auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3]);
                if(auxEmp!=NULL){
                    ll_add(pArrayListEmployee,auxEmp);
                    response=0;
                }
            }
        }
    }
    return response;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int response=-1;
	Employee* auxEmp=NULL;
	int cant;

	if(pFile!=NULL && pArrayListEmployee!=NULL){
		while(!feof(pFile)){
			auxEmp=employee_new();
			if(auxEmp!=NULL){
				cant=fread(auxEmp,sizeof(Employee),1,pFile);
				if(cant==1){
					ll_add(pArrayListEmployee,auxEmp);
					response=0;
				}
				else{
					employee_delete(auxEmp);
				}
			}
		}
	}
	return response;
}

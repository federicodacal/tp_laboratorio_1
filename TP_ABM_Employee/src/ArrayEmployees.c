#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "datawarehouse.h"
#include "sector.h"
#include "utn_validaciones.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int response=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            list[i].isEmpty=1;
        }
        response=0;
    }
    return response;
}


/** \brief add in a existing list of employees the received employee in the first empty id position
 *
 * \param list[] Employee
 * \param len int
 * \param sectors[] Sector
 * \param secLen int
 * \param pId int*
 * \return int -1 (Error) 0 (OK)
 *
 */
int addEmployee(Employee list[], int len, Sector sectors[], int secLen, int* pId)
{
    int response=-1;
    Employee newEmployee;
    int index;
    int idSector;

    printf("\nID: %d\n",*pId);

    if(list!=NULL && len>0 && pId!=NULL){
        index=findEmptyIndex(list,len);
        if(index==-1){
            printf("No hay lugar disponible en el sistema\n\n");
            response=1;
        }
        else{
            utn_getNombre(newEmployee.name,NAME_LEN,"\nIngrese Nombre: ","\nError dato no valido",10);
            utn_getNombre(newEmployee.lastName,LASTNAME_LEN,"\nIngrese Apellido: ","\nError dato no valido",10);
            utn_getNumeroFlotante(&newEmployee.salary,"\nIngrese Salario: $","\nError dato no valido",0,100000,10);

            printSectors(sectors, secLen);

            utn_getNumero(&idSector,"\nSeleccione ID: ","\nError dato no valido\n",500,504,10);

            newEmployee.idSector=idSector;
            newEmployee.id=*pId;
            (*pId)++;
            newEmployee.isEmpty=0;
            list[index]=newEmployee;
            response=0;
        }
    }
    return response;
}

/** \brief Busca en la lista de empleados un indice disponible
 *
 * \param list[] Employee
 * \param len int
 * \return int -1 (Error) o indice disponible
 *
 */
int findEmptyIndex(Employee list[], int len)
{
    int index=-1;
    if(list!=NULL && len>0){
        for(int i=0; i<len;i++){
            if(list[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}

/** \brief Imprime en pantalla un employee y sus campos
 *
 * \param emp Employee
 * \param sectors[] Sector
 * \param secLen int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int printEmployee(Employee emp, Sector sectors[], int secLen)
{
    int response=-1;
    char description[20];
    if(sectors!=NULL && secLen>0){
        if(cargarDescripcionSector(emp.idSector, sectors, secLen, description)){
            printf("%02d  %10s    %10s  %8.2f    %d - %s\n",
               emp.id,
               emp.name,
               emp.lastName,
               emp.salary,
               emp.idSector,
               description
               );
        }
        response=0;
    }
    return response;
}


/** \brief Imprime en pantalla la lista de todos los employees cargados
 *
 * \param list[] Employee
 * \param len int
 * \param sectors[] Sector
 * \param secLen int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int printEmployees(Employee list[], int len, Sector sectors[], int secLen)
{
    int response=-1;
    int flag=1;
    if(list!=NULL && len>0 && sectors!=NULL && secLen>0){
        printf("\n\t\t*****LISTADO DE EMPLEADOS******\n");
        printf("-------------------------------------------------------------------------\n");
        printf("ID      Nombre      Apellido   Salario       Sector\n");
        for(int i=0;i<len;i++){
            if(!list[i].isEmpty){
                printEmployee(list[i], sectors, secLen);
                flag=0;
            }
        }
        if(flag){
            printf("\n\tNo hay empleados que mostrar\n");
        }
    response=0;
    printf("\n\n");
    }
    return response;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len, int id)
{
    int index=-1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++)
            if(list[i].id==id && list[i].isEmpty==0){
                index=i;
            }
    }
    return index;
}

/** \brief Remueve el employee seleccionado del array de manera logica
 *
 * \param list[] Employee
 * \param len int
 * \param sectors[] Sector
 * \param secLen int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int removeEmployee(Employee list[], int len, Sector sectors[], int secLen)
{
    int response=-1;

    int id;
    int index;
    int confirm;

    printEmployees(list,len,sectors,secLen);
    utn_getNumero(&id,"\nIngrese el ID: ","Dato no valido",1,1000,10);
    index=findEmployeeById(list,len,id);

    if(index==-1){
        printf("No hay empleado registrado con el ID %d\n",id);
    }
    else{
        printEmployee(list[index],sectors,secLen);
        utn_getNumero(&confirm,"\n[1] Confirmar baja\n[2] Cancelar\n","\nDato no valido",1,2,10);
        if(confirm){
            list[index].isEmpty=1;
            response=0;
        }
        else{
            printf("Baja cancelada\n");
            response=1;
        }
    }
    return response;
}

/** \brief Actualiza los campos del employee
 *
 * \param list[] Employee
 * \param len int
 * \param sectors[] Sector
 * \param secLen int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int updateEmployee(Employee list[], int len, Sector sectors[], int secLen)
{
    int response=-1;
    Employee auxEmp;
    int id;
    int index;
    int idSector;
    int option;

    printEmployees(list,len,sectors,secLen);
    utn_getNumero(&id,"Ingrese el ID: ","\nDato no valido",1,1000,10);
    index=findEmployeeById(list,len,id);


    if(index==-1){
        printf("No hay empleado registrado con el ID %d\n",id);
    }
    else{
        do{
        system("cls");
        printf("\nSeleccione el campo que desea modificar o 5 para Terminar:\n");
        utn_getNumero(&option,"\n[1] Nombre - [2] Apellido - [3] Salario - [4] Sector - [5] Terminar\n","\nDato no valido",1,5,10);
            switch(option){
                case 1:
                    utn_getNombre(auxEmp.name,NAME_LEN,"\nIngrese Nombre: ","\nError dato no valido",10);
                    strcpy(list[index].name,auxEmp.name);
                    printf("Informacion Actualizada\n\n");
                    system("pause");
                    break;
                case 2:
                    utn_getNombre(auxEmp.lastName,LASTNAME_LEN,"\nIngrese Apellido: ","\nError dato no valido",10);
                    strcpy(list[index].lastName,auxEmp.lastName);
                    printf("Informacion Actualizada\n\n");
                    system("pause");
                    break;
                case 3:
                    utn_getNumeroFlotante(&auxEmp.salary,"\nIngrese Salario: $","\nError dato no valido",0,100000,10);
                    list[index].salary=auxEmp.salary;
                    printf("Informacion Actualizada\n\n");
                    system("pause");
                    break;
                case 4:
                    printSectors(sectors, secLen);
                    utn_getNumero(&idSector,"\nSeleccione ID: ","\nError dato no valido\n",500,504,10);
                    list[index].idSector=idSector;
                    printf("Informacion Actualizada\n\n");
                    system("pause");
                    break;
            }
        }while(option!=5);
        printf("\nDatos Actualizados:\n");
        printEmployee(list[index],sectors,secLen);
        printf("---------------------------------------------------------------\n\n");
        response=0;
    }
    return response;
}

/** \brief Calcula el salario total de los empleados
 *
 * \param list[] Employee
 * \param len int
 * \return int -1 (Error) 0 (OK)
 *
 */
int getTotalSalaries(Employee list[], int len)
{
    int response=-1;
    float totalSalaries=0;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty==0){
                totalSalaries+=list[i].salary;
            }
        }
        printf("Salarios Totales: $%.2f\n",totalSalaries);
        response=0;
    }
    return response;
}

/** \brief Calcula el salario promedio entre todos los empleados
 *
 * \param list[] Employee
 * \param len int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int getAvgSalary(Employee list[], int len)
{
    int response=-1;
    float totalSalaries=0;
    int employeeQty=0;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty==0){
                totalSalaries+=list[i].salary;
                employeeQty++;
            }
        }
        printf("Salario Promedio: $%.2f\n",totalSalaries/employeeQty);
        response=0;
    }
    return response;
}

/** \brief Encuentra la cantidad de empleados que tienen mayor salario que el salario promedio
 *
 * \param list[] Employee
 * \param len int
 * \return int -1 (Error) 0 (Ok)
 *
 */
int getEmployeesAboveAvgSalary(Employee list[], int len)
{
    int response=-1;
    float totalSalaries=0;
    int employeeQty=0;
    float avgSalary;
    int employeeAboveAvg=0;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty==0){
                totalSalaries+=list[i].salary;
                employeeQty++;
            }
        }
        avgSalary=totalSalaries/employeeQty;
        for(int i=0;i<len;i++){
            if(list[i].isEmpty==0 && list[i].salary>avgSalary){
                employeeAboveAvg++;
            }
        }
        printf("Empleados con sueldo por sobre el promedio: %d\n\n",employeeAboveAvg);
        response=0;
    }

    return response;
}


/** \brief Ordena los empleados en cada sector por apellido
 *
 * \param list[] Employee
 * \param len int
 * \param order int
 * \return int -1 (Error) 0 (OK)
 *
 */
int sortEmployeesLastName(Employee list[], int len, int order)
{
    int response=-1;
    Employee auxEmp;

    if(list!=NULL && len>0){
        for(int i=0; i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(order==1 && (list[i].idSector>list[j].idSector ||
                  (list[i].idSector==list[j].idSector && strcmpi(list[i].lastName,list[j].lastName)>0))){
                    auxEmp=list[i];
                    list[i]=list[j];
                    list[j]=auxEmp;
                }
            response=0;
            }
        }
    }
    return response;
}

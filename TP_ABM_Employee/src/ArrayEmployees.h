#include "sector.h"

#define NAME_LEN 51
#define LASTNAME_LEN 51

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[NAME_LEN];
    char lastName[LASTNAME_LEN];
    float salary;
    int isEmpty;
    int idSector;
}Employee;

int printEmployee(Employee emp, Sector sectors[], int secLen);
int printEmployees(Employee list[], int len, Sector sectors[], int secLen);
int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, Sector sectors[], int secLen, int* pId);
int findEmptyIndex(Employee list[], int len);
int removeEmployee(Employee list[], int len, Sector sectors[], int secLen);
int findEmployeeById(Employee list[], int len, int id);
int updateEmployee(Employee list[], int len, Sector sectors[], int secLen);
int getTotalSalaries(Employee list[], int len);
int getAvgSalary(Employee list[], int len);
int getEmployeesAboveAvgSalary(Employee list[], int len);
int sortEmployeesLastName(Employee list[], int len, int order);

#endif // ARRAYEMPLOYEES_H_INCLUDED

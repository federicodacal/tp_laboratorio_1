#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_printEmployee(Employee* pEmp);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_findNextId(LinkedList* lista, int* id);
int employee_findById(LinkedList* pArrayListEmployee,int id);
int employee_deleteIndex(LinkedList* pArrayListEmployee, int index);

int employee_updateEmployee(LinkedList* pArrayListEmployee, int index);

int employee_cmpId(void* emp1, void* emp2);
int employee_cmpNombre(void* emp1, void* emp2);
int employee_cmpSueldo(void* emp1, void* emp2);
int employee_cmpHoras(void* emp1, void* emp2);

int mostrarEmpleados(LinkedList* lista);
#endif // employee_H_INCLUDED

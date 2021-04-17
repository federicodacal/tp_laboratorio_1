#ifndef UTNDACAL_OPERACIONES_H_INCLUDED
#define UTNDACAL_OPERACIONES_H_INCLUDED

int sumarInt(int a,int b,int* resultado);
int restarInt(int a,int b,int* resultado);
int dividirInt(int a,int b,float* resultado);
int multiplicarInt(int a,int b,int* resultado);
void mostrarResultados(int a, int b, int suma, int resta, float division, int multiplicacion, int factorialX, int factorialY);
int factorialInt(int a, int* factorial);
void mostrarResultadoSuma(int a, int b, int suma);
void mostrarResultadoResta(int a, int b, int resta);
void mostrarResultadoDivision(int a, int b, float division);
void mostrarResultadoMultiplicacion(int a, int b, int multiplicacion);
void mostrarResultadoFactorial(int a, int factorialX);

#endif // UTNDACAL_OPERACIONES_H_INCLUDED

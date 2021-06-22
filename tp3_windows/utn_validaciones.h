#ifndef UTN_VALIDACIONES_H_INCLUDED
#define UTN_VALIDACIONES_H_INCLUDED

int validarSexo(char* str);
int validarRodados(float* rodado);
int validarFecha(int dia, int mes);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getSexo(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getChar(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getRodado(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esNombre(char* cadena,int longitud);
int esNumerica(char* cadena, int limite);
int esFlotante(char* cadena);

#endif // UTN_VALIDACIONES_H_INCLUDED

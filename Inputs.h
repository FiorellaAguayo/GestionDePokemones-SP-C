#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

int validarEntero(char enteroAValidar[]);
int pedirEntero(int* enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo);
int pedirCadena(char* cadenaValidada, char mensaje[], char mensajeError[], int maximo);
int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar);
int pedirArchivoCSV(char* cadena, char* mensaje, char* mensajeError);

#endif // INPUTS_H_INCLUDED

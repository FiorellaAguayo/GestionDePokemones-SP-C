#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "Inputs.h"

int menu()
{
	int opcion;

	printf("\n\n\n      ***  MENU  ***     \n\n");
	printf("1) Cargar archivo pokemones.\n");
	printf("2) Modificar valor ataque.\n");
	printf("3) Imprimir Pokemones.\n");
	printf("4) Filtrar tipo Fuego.\n");
	printf("5) Filtrar Extra Grandes de tipo Veneno.\n");
	printf("6) Mapear ataque cargado.\n");
	printf("7) Batalla pokemon:.\n");
	printf("8) Salir.\n");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 8);

	return opcion;
}

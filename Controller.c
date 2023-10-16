#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Parser.h"
#include "Pokemon.h"
#include "Inputs.h"

int controller_cargarArchivoDesdeTexto(char* path, LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	FILE* pFile;

	if(path != NULL && pArrayListPokemon != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			parser_PokemonesDesdeTexto(pFile, pArrayListPokemon);
			todoOk = 1;
		}
	}
	fclose(pFile);
	return todoOk;
}

int controller_listarPokemones(LinkedList* pArrayListPokemon)
{
    int todoOk = 0;
    ePokemon* unPokemon;
    if(pArrayListPokemon != NULL)
    {
        int tam = ll_len(pArrayListPokemon);
        if(tam > 0)
        {
            pokemon_mostrarEncabezado();
            for(int i = 0; i < tam; i++)
            {
                unPokemon = ll_get(pArrayListPokemon, i);
                pokemon_mostrarUnPokemon(unPokemon);
            }
        }
        printf("\n---------------------------------------------------------------------------------------------------------------");
        todoOk = 1;
    }
    return todoOk;
}

int controller_modificarValorAtaque(LinkedList* pArrayListPokemon)
{
    int todoOk = 0;
    int numero;
    int indice;
    int valorAtaque;
    char respuesta;
    ePokemon* unPokemon;
    if(pArrayListPokemon != NULL)
    {
        controller_listarPokemones(pArrayListPokemon);
        pedirEntero(&numero, "\nIngrese el numero del pokemon que desea modificar: ", "\nEl numero ingresado no es valido. Reingrese: ", 1, 151);

        indice = buscarPokemonPorNumero(pArrayListPokemon, numero);
        if(indice == -1)
        {
            printf("\nEl pokemon con ese numero no existe.");
        }
        else
        {
            unPokemon = ll_get(pArrayListPokemon, indice);
            pokemon_mostrarEncabezado();
            pokemon_mostrarUnPokemon(unPokemon);
            pedirCaracter(&respuesta, "\n\nEstas seguro de modificar este pokemon? (s = si | n = no): ", "\nEl caracter ingresado no es valido. Reingrese: ", 's', 'n');
            if(respuesta == 's')
            {
                if(unPokemon != NULL)
                {
                    pedirEntero(&valorAtaque, "\nIngrese el nuevo valor ataque: ", "\nEl valor ingresado no es valido. Reingrese: ", 1, 100);
                    pokemon_setValorAtaque(unPokemon, valorAtaque);
                    todoOk = 1;
                }
            }
            else
            {
                printf("\nSe cancela la modificacion.");
            }
        }
    }
    return todoOk;
}

int buscarPokemonPorNumero(LinkedList* pArrayListPokemon, int numero)
{
    int indice = -1;
    int numeroComparar;
    ePokemon* unPokemon;
    if(pArrayListPokemon != NULL && numero > 0)
    {
        int tam = ll_len(pArrayListPokemon);
        for(int i = 0; i < tam; i++)
        {
            unPokemon = ll_get(pArrayListPokemon, i);
            if(unPokemon != NULL)
            {
                pokemon_getNumero(unPokemon, &numeroComparar);
                if(numero == numeroComparar)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

int controller_cargarArchivo(char* path, LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	FILE* pFile;
	ePokemon* unPokemon;
	int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;

	if(path != NULL && pArrayListPokemon != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile == NULL)
		{
			printf("\nHubo al abrir el archivo.csv.\n");
		}
		else
		{
			unPokemon = pokemon_new();

			fprintf(pFile,"numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor");

			int tam = ll_len(pArrayListPokemon);
			for(int i = 0; i < tam; i++)
			{
				unPokemon = (ePokemon*)ll_get(pArrayListPokemon, i);

				if(unPokemon != NULL)
				{
					pokemon_getNumero(unPokemon, &numero);
					pokemon_getNombre(unPokemon, nombre);
					pokemon_getTipo(unPokemon, tipo);
					pokemon_getTamanio(unPokemon, tamanio);
					pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
					pokemon_getValorAtaque(unPokemon, &valorAtaque);
					pokemon_getEsVarioColor(unPokemon, &esVarioColor);

					fprintf(pFile, "\n%d,%s,%s,%s,%s,%d,%d", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVarioColor);
					todoOk = 0;
				}
				else
				{
					break;
				}
			}
			fclose(pFile);
		}
	}
    return todoOk;
}

int controller_Filtrado_TipoFuego(LinkedList* pArrayListPokemon)
{
    int todoOk = 0;
    LinkedList* auxLista;
    if(pArrayListPokemon != NULL)
    {
        auxLista = ll_filter(pArrayListPokemon, pokemon_filtrarPorFuego);
        controller_cargarArchivo("FiltradoFire.csv", auxLista);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Filtrado_ExtraGrandeTipoVeneno(LinkedList* pArrayListPokemon)
{
    int todoOk = 0;
    LinkedList* auxLista;
    if(pArrayListPokemon != NULL)
    {
        auxLista = ll_filter(pArrayListPokemon, pokemon_filtrarPorExtraGrandeTipoVeneno);
        controller_cargarArchivo("FiltradoXLPoison.csv", auxLista);
        todoOk = 1;
    }
    return todoOk;
}

int controller_Mapeo_AtaqueCargado(LinkedList* pArrayListPokemon)
{
    int todoOk = 0;
    if(pArrayListPokemon != NULL)
    {
        ll_map(pArrayListPokemon, pokemon_Mapeo);
        controller_listarPokemones(pArrayListPokemon);
        todoOk = 1;
    }
    return todoOk;
}

int controller_batalla(LinkedList* pArrayListPokemon)
{
	int todoOk = 0;
	int contador = 0;

	if(pArrayListPokemon != NULL)
	{
		contador = ll_count(pArrayListPokemon, pokemon_validarPokemonesBatalla);
		if(contador >= 3)
		{
			printf("\n¡Felicidades, ganaste la batalla!");
		}
		else
		{
			printf("\n¡Oh no, perdiste la batalla!");
		}

		todoOk = 1;
	}
	return todoOk;
}

#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_cargarArchivoDesdeTexto(char* path, LinkedList* pArrayListPokemon);
int controller_listarPokemones(LinkedList* pArrayListPokemon);
int buscarPokemonPorNumero(LinkedList* pArrayListPokemon, int numero);
int controller_modificarValorAtaque(LinkedList* pArrayListPokemon);
int controller_cargarArchivo(char* path, LinkedList* pArrayListPokemon);
int controller_Filtrado_TipoFuego(LinkedList* pArrayListPokemon);
int controller_Filtrado_ExtraGrandeTipoVeneno(LinkedList* pArrayListPokemon);
int controller_batalla(LinkedList* pArrayListPokemon);

#endif // CONTROLLER_H_INCLUDED

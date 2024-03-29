typedef struct
{
    int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVarioColor;
}ePokemon;


#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

ePokemon* pokemon_new();
ePokemon* pokemon_newParametros(char *numeroStr, char *nombreStr, char *tipoStr, char *tamanioStr, char *ataqueCargadoStr, char *valorAtaqueStr, char *esVarioColorStr);
void pokemon_delete(ePokemon *this);
int pokemon_setNumero(ePokemon *this, int numero);
int pokemon_getNumero(ePokemon *this, int *numero);
int pokemon_setNombre(ePokemon *this, char *nombre);
int pokemon_getNombre(ePokemon *this, char *nombre);
int pokemon_setTipo(ePokemon *this, char *tipo);
int pokemon_getTipo(ePokemon *this, char *tipo);
int pokemon_setTamanio(ePokemon *this, char *tamanio);
int pokemon_getTamanio(ePokemon *this, char *tamanio);
int pokemon_setAtaqueCargado(ePokemon *this, char *ataqueCargado);
int pokemon_getAtaqueCargado(ePokemon *this, char *ataqueCargado);
int pokemon_setValorAtaque(ePokemon *this, int valorAtaque);
int pokemon_getValorAtaque(ePokemon *this, int *valorAtaque);
int pokemon_setEsVarioColor(ePokemon *this, int esVarioColor);
int pokemon_getEsVarioColor(ePokemon *this, int *esVarioColor);
void pokemon_mostrarEncabezado();
int pokemon_mostrarUnPokemon(ePokemon *unPokemon);
int pokemon_filtrarPorFuego(void* pElement);
int pokemon_filtrarPorExtraGrandeTipoVeneno(void* pElement);
int pokemon_Mapeo(void* pElement);
int calcularAumento(int valorAtaque, int porcentaje);
int pokemon_validarPokemonesBatalla(void* pElement);

#endif // POKEMON_H_INCLUDED

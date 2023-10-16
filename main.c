#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menus.h"
#include "Inputs.h"
#include "Controller.h"

int main()
{
    int seguir = 1;
    int flag = 0;
    char nombreArchivo[30];
    LinkedList* listaPokemones = ll_newLinkedList();

    do
    {
        switch(menu())
        {
            case 1:
                pedirArchivoCSV(nombreArchivo, "\nPor favor, ingrese el nombre del archivo con extension .csv: ", "\nEl nombre no es valido.");
                if(!controller_cargarArchivoDesdeTexto(nombreArchivo, listaPokemones))
                {
                    printf("\nHubo un problema al hacer la carga del archivo.\n");
                }
                else
                {
                    printf("\nEl archivo '%s' se ha cargado correctamente.", nombreArchivo);
                    flag = 1;
                }
                break;

            case 2:
                if(flag)
                {
                    if(!controller_modificarValorAtaque(listaPokemones))
                    {
                        printf("\nHubo un problema al hacer la modificacion.\n");
                    }
                    else
                    {
                        printf("\nModificacion exitosa!");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 3:
                if(flag)
                {
                    if(!controller_listarPokemones(listaPokemones))
                    {
                        printf("\nHubo un problema al hacer la lista.\n");
                    }
                    else
                    {
                        printf("\nListado exitoso!");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 4:
                if(flag)
                {
                    if(!controller_Filtrado_TipoFuego(listaPokemones))
                    {
                        printf("\nHubo un problema al hacer el filtro por fuego.\n");
                    }
                    else
                    {
                        printf("\nFiltrado por fuego exitoso!");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 5:
                if(flag)
                {
                    if(!controller_Filtrado_ExtraGrandeTipoVeneno(listaPokemones))
                    {
                        printf("\nHubo un problema al hacer el filtro por extra grande y tipo veneno.\n");
                    }
                    else
                    {
                        printf("\nFiltrado por extra grande y tipo veneno!");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 6:
                if(flag)
                {
                    if(!controller_Mapeo_AtaqueCargado(listaPokemones))
                    {
                        printf("\nHubo un problema al hacer el mapeo.\n");
                    }
                    else
                    {
                        printf("\nMapeo exitoso!");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 7:
                if(flag)
                {
                    if(!controller_batalla(listaPokemones))
                    {
                        printf("\nHubo un problema al la batalla pokemon.\n");
                    }
                }
                else
                {
                    printf("\nPrimero debes cargar el archivo.");
                }
                break;

            case 8:
                printf("\nGracias por utilizar este programa!");
                seguir = 0;
                break;
        }
    }while(seguir);

    return 0;
}

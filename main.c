#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*
Dado un archivo de texto variable con el formato
DNI|Peso en KG (punto flotante)|Nombre[31]

Parte B:
Hacer una función que a partir del puntero FILE, genere un archivo de texto con datos de pruebas, como mínimo 5 registros.

Parte C:
Realizar una función que genere un archivo binario a partir de los datos del archivo de texto.

Parte D:
Realizar una función que a partir de del puntero FILE, muestre por pantalla la información del binario.
*/
int main()
{
    FILE *pf;
    generarArchivo(pf);
    mostrarArchivoTexto(pf);

    convertirABinario(pf);

    mostrarArchivoBinario(pf);
    return 0;
}

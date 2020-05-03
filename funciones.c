#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/*Genera el lote de prueba*/
void generarArchivo(FILE *pf)
{
    pf = fopen("registro.txt", "wt");
    if(pf ==NULL)
    {
        system("PAUSE");
        exit(-2);
    }

    tRegistro reg[5] =
    {
        {439876671, 53.2, "Persona Uno"},
        {58554434, 75.5, "Persona Dos"},
        {7855656, 98.2, "Persona Tres"},
        {344433546, 68.7, "Persona Cuatro"},
        {56445365, 51.9, "Persona Cinco"}
    };

    for(int i = 0; i< 5; i++)
    {
        fprintf(pf, "%d|%.1f|%s\n", reg[i].dni, reg[i].peso, reg[i].nom);
    }
    fclose(pf);
}
/*Muestra un archivo de texto*/
void mostrarArchivoTexto(FILE *pf)
{
    char cad[100];
    pf =fopen("registro.txt", "rt");
    if(pf == NULL)
    {
        system("PAUSE");
        exit(-2);
    }

    while(fgets(cad, sizeof(cad), pf))
    {
        puts(cad);
    }
    fclose(pf);
}
/*Convertidor de texto a binario*/
void convertirABinario(FILE *pb)
{
    char cad[200], *pl;
    tRegistro temp;
    FILE *pt = fopen("registro.txt", "rt");
    pb = fopen("registro2.dat", "wb");

    /*Recorremos el archivo de texto. Guardamos linea por linea en una variable*/
    while(fgets(cad, sizeof(cad), pt))
    {
        /*Quitamos el "\n"  */
        pl = strrchr(cad, '\n');
        *pl = '\0';

        /*Capturamos el nombre*/
        pl = strrchr(cad, '|');
        sscanf(pl+1, "%[]", &temp.nom);
        *pl = '\0';

        /*Capturamos el Peso*/
        pl = strrchr(cad, '|');
        sscanf(pl+1, "%f", &temp.peso);
        *pl = '\0';

        /*Capturamos el DNI*/
        sscanf(cad, "%d", &temp.dni);

        /*Escritura*/
        fwrite(&temp, sizeof(tRegistro), 1, pb);
    }
    fclose(pt);
    fclose(pb);
    puts("\n****Se convirtio el archivo de texto a binario****\n");

}

void mostrarArchivoBinario(FILE *pb)
{
    tRegistro temp;
    pb = fopen("registro2.dat", "rb");
    fread(&temp, sizeof(tRegistro), 1, pb);
    while(!feof(pb))
    {
        printf("%d, %.1f, %s\n", temp.dni, temp.peso, temp.nom);
        fread(&temp, sizeof(tRegistro), 1, pb);
    }
    fclose(pb);

}

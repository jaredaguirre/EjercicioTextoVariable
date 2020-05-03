#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dni;
    float peso; /*en kilos*/
    char nom[31];
}tRegistro;

void generarArchivo(FILE *);
void mostrarArchivoTexto(FILE *);
void convertirABinario(FILE *);

void mostrarArchivoBinario(FILE *);

#endif // FUNCIONES_H_INCLUDED

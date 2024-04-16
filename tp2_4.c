#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CANT_PC 5
#define MAX 10

//Estructura
typedef struct 
{
    float velocidad; //Entre 1 y 3 GHz
    int anio; //Entre 2015 y 2023
    int cantidad; //Entre 1 y 8
    char *tipo_cpu; //Valores del arreglo tipos
}COMPU;

//Funciones
void PClista(COMPU *PC);
void PCmasvieja(COMPU *PC);
void PCmayorvelocidad(COMPU *PC);

//Main
int main (){
    //Asignacion Dinamica
    COMPU *PC = (COMPU *)malloc(CANT_PC * sizeof(COMPU));
    
    //Arreglo tipos
    char tipos[][MAX] = {
        "Intel",
        "AMD",
        "Celeron",
        "Athlon",
        "Core",
        "Pentium"};

    //LLenar estructura
    for (int i = 0; i < CANT_PC; i++)
    {
        PC[i].velocidad = rand() % (3 - 1 + 1) + 1;
        PC[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        PC[i].cantidad = rand() % (8 - 1 + 1) + 1;
        PC[i].tipo_cpu = tipos[rand() % (5 - 0 + 1) + 0];
    }    

    // Lista de PC
    PClista(PC);

    // PC mas vieja
    PCmasvieja(PC);

    // PC mayor velocidad
    PCmayorvelocidad(PC);

    //Liberar memoria
    free(PC);
    return 0;
}

void PClista(COMPU *PC){

    for (int i = 0; i < CANT_PC; i++)
    {
        printf("\n*******PC N°%d********", i + 1);
        printf("\n\tVelocidad: %d", PC[i].velocidad);
        printf("\n\tAnio: %d", PC[i].anio);
        printf("\n\tCantidad de nucleos: %d", PC[i].cantidad);
        printf("\n\tTipo de procesador: %s", PC[i].tipo_cpu);
    }
}
void PCmasvieja(COMPU *PC){
    int anio = PC[0].anio, j = 0;

    for (int i = 0; i < CANT_PC; i++)
    {
        if (anio > PC[i].anio)
        {
            anio = PC[i].anio;
            j = i;
        }
    }

    printf("\n\n**********PC mas vieja***********");
    printf("\n\tPC N° %d creada en el anio: %d", j + 1, anio);
}
void PCmayorvelocidad(COMPU *PC){
        int mayorVelocidad = PC[0].velocidad, j = 0;

    for (int i = 0; i < CANT_PC; i++)
    {
        if (mayorVelocidad < PC[i].velocidad)
        {
            mayorVelocidad = PC[i].velocidad;
            j = i;
        }
    }

    printf("\n\n***********PC con mayor velocidad**********");
    printf("\n\tPC N° %d con %d GHz", j + 1, mayorVelocidad);
}
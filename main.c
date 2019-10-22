#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct persona
{
    int id;
    char nombre[20];
    char apellido[20];
    struct persona * anterior;
    struct persona * siguiente;
};

void tattoo();
void guardar();
void guardarNuevo();
void leer();

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int main()
{
    int opcion;
    do
    {
        system("cls");
        printf("********************************************************************************\n");
        printf("* MENU PRINCIPAL                                                               *\n");
        printf("********************************************************************************\n");
        printf("* Hola! Que deseas hacer?                                                      *\n");
        printf("*                                                                              *\n");
        printf("*  1 > Leer Listado de heroes                                                  *\n");
        printf("*  2 > Sobreescribir listado de heroes (datos precargados)                     *\n");
        printf("*  3 > Agregar nuevo heroe                                                     *\n");
        printf("*  0 > Salir                                                                   *\n");
        printf("********************************************************************************\n");
        printf("*                                                                              *\n");
        printf("*  Tu eleccion es:                                                             *\n");
        printf("*                                                                              *\n");
        printf("********************************************************************************\n");
        gotoxy(19,11);
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
        case 0:
            printf("Chau!!!");
            exit(1);
            break;
        case 1:
            leer();
            break;
        case 2:
            guardar();
            break;

        case 3:
            guardarNuevo();
            break;
        }
        //opcion = -1;

    }

    while (opcion > 0 && opcion <= 3);

    return 0;
}
void guardar()
{
    FILE *archivo;

    //intento abrir archivo en modo escritura (pisar el archivo viejo)
    archivo = fopen("datos2", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir archivo...\n");
        system("pause");
        //exit(1);
    }
    else
    {
        //Genero lista de heroes
        struct persona hero1 = {1, "Luke", "Skywalker"};
        struct persona hero2 = {2, "Han", "Solo"};
        struct persona hero3 = {3, "Walter", "Molina"};

        //Escribo los datos en el archivo
        fwrite(&hero1, sizeof(struct persona), 1, archivo);
        fwrite(&hero2, sizeof(struct persona), 1, archivo);
        fwrite(&hero3, sizeof(struct persona), 1, archivo);

        printf("********************************************************************************\n");
        printf("* Se guardaron los datos!                                                      *\n");
        printf("********************************************************************************\n");
        printf("\n");

        system("pause");
        system("cls");

        // cerrar archivo
        fclose(archivo);
    }
}

void guardarNuevo()
{
    FILE *archivo;

    //intento abrir archivo en modo escritura (agregar al final)
    archivo = fopen("datos2", "a+");
    if (archivo == NULL)
    {
        printf("Error al abrir archivo...\n");
        system("pause");
        //exit(1);
    }
    else
    {
        printf("********************************************************************************\n");
        printf("* VAMOS A CARGAR UN NUEVO HEROE                                                *\n");
        printf("********************************************************************************\n");

        struct persona hero;

        printf("ID: ");
        scanf("%d",&hero.id);
        fflush( stdin );
        printf("Nombre: ");
        fgets(hero.nombre, sizeof(hero.nombre),stdin);
        fflush( stdin );

        printf("Apellido: ");
        fgets(hero.apellido, sizeof(hero.apellido),stdin);

        //Escribo los datos en el archivo
        fwrite(&hero, sizeof(struct persona), 1, archivo);


        printf("********************************************************************************\n");
        printf("* Se guardaron los datos!                                                      *\n");
        printf("********************************************************************************\n");
        printf("\n");
        system("pause");
        system("cls");
        //if (fwrite(ptr, size, num, f) != num) {
        //Error
        //}

        //if (fwrite != 0)
        //    printf("Guardado sin problemas!\n");
        //else
        //    printf("Ups! No se pudo guardar\n");

        // cerrar archivo
        fclose(archivo);
    }
}


void leer()
{
    FILE *archivo;
    struct persona personaDesdeArchivo;
    // Intento abrir el archivo para lectura
    archivo = fopen("datos2", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo...\n");
        system("pause");
        system("cls");
        //exit(1);
    }
    else
    {
        printf("********************************************************************************\n");
        printf("* DATOS EN EL ARCHIVO                                                          *\n");
        printf("********************************************************************************\n");
        // leemos el archivo hasta EOF (fin del archivo)


        while (fread(&personaDesdeArchivo, sizeof(struct persona), 1, archivo))
        {
            printf("\n");
            printf("> ID: %d\n",personaDesdeArchivo.id);
            printf("  %s %s\n",personaDesdeArchivo.nombre, personaDesdeArchivo.apellido);
            printf("\n");
            printf("********************************************************************************\n");
        }
        system("pause");
        system("cls");
        // Cerramos el archivo
        fclose(archivo);
    }
}


/*
Modos de apertura de archivos

r — abre el archivo en modo de solo lectura.
w — abre el archivo para escritura (si no existe lo crea, si existe lo destruye).
a — abre el archivo para agregar información (si no existe lo crea).
r+ — abre el archivo para lectura/escritura (comienza al principio del archivo).
w+ — abre el archivo para lectura/escritura, sobre-escribe el archivo si este ya existe o lo crea si no).
a+ — abre el archivo para lectura/escritura (se sitúa al final del archivo).

*/

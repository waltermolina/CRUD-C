#include <stdio.h>
#include <stdlib.h>

struct persona {
    int id;
    char nombre[20];
    char apellido[20];
};

int main () {
    int opcion;
    do {
        printf("================================================================================\n");
        printf(" Hola! ¿Qué deseas hacer?\n\n");
        printf("  1 > Leer Archivo\n");
        printf("  2 > Escribir Archivo\n");
        printf("  0 > Salir\n");
        printf("\n");
        printf("  Tu elección es: ");


        scanf("%d",&opcion);
        switch(opcion){
        case 0:
            printf("Gracias!");
            exit(1);
            break;
        case 1:
            leer();
            break;
        case 2:
            guardar();
            break;
        }
        opcion = -1;

    }while( opcion < 0 || opcion > 2);


    return 0;

}

void guardar(){
    FILE *archivo;

    //abrir archivo en modo escritura
    archivo = fopen ("datos2", "w");
    if (archivo == NULL){
        printf("Error al abrir archivo...\n");
        exit(1);
    }

    struct persona alumno1 = {1, "Luke", "Skywalker"};
    struct persona alumno2 = {2, "Han", "Solo"};
    struct persona alumno3 = {3, "Walter", "Molina"};

    //Escribir en el archivo...
    fwrite(&alumno1, sizeof(struct persona), 1, archivo);
    fwrite(&alumno2, sizeof(struct persona), 1, archivo);
    fwrite(&alumno3, sizeof(struct persona), 1, archivo);


    //if (fwrite(ptr, size, num, f) != num) {
        //Error
    //}

    if(fwrite != 0)
        printf("Guardado sin problemas!\n");
    else
        printf("Ups!\n");

    // cerrar archivo
    fclose (archivo);
}

void leer(){
    FILE *archivo;
    struct persona personaDesdeArchivo;

    // Abrir el archivo para lectura
    archivo = fopen ("datos2", "r");
    if (archivo == NULL){
        printf("Error al abrir el archivo...\n");
        exit(1);
    }

    // leer el archivo hasta EOF
    while(fread(&personaDesdeArchivo, sizeof(struct persona), 1, archivo)){
        printf("id = %d name = %s %s\n", personaDesdeArchivo.id, personaDesdeArchivo.nombre, personaDesdeArchivo.apellido);
    }

    // Cerrar el archivo
    fclose(archivo);

}

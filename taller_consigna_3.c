#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notas[5][3], suma, promedio, mayor, menor;
    int i, j, opcion, aprobados, reprobados;

    system ("cls");
    printf ("INGRESO DE NOTAS\n");

    for ( i = 0; i < 5; i++)
    {
        printf ("\n Estudiante %d\n", i + 1);

        for (j = 0; j < 3; j++){
            
            do
            {
                printf ("Nota de la asignatura %d: ", j + 1);
                if (scanf("%f", &notas[i][j]) != 1)
                {
                    while (getchar() != '\n');
                    notas[i][j] = -1;
                }

                if (notas[i][j] < 0 || notas[i][j] > 10)
                printf("Recuerde que la nota debe estar entre 0 y 10\n");
            } while (notas[i][j] < 0 || notas[i][j] > 10);

            

        }
       
        
    }
    do
    {
        system ("cls");   
        printf ("===    MENU    ===\n");
        printf ("   1.- Promedio por estudiante\n");
        printf ("   2.- Promedio por asignatura\n");
        printf ("   3.- Nota mayor y menor por estudiante\n");
        printf ("   4.- Nota mayor y menor por asignatura\n");
        printf ("   5.- Aprobados y Reprobados\n");
        printf ("   6.- Salir\n");
        printf ("Escoja una opcion: ");
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:
            
            for ( i = 0; i < 5; i++)
            {
                suma = 0;
                for ( j = 0; j < 3; j++)
                {
                    suma = suma + notas[i][j];
                }
                promedio = suma / 3;
                printf ("Estudiante %d: %.2f\n", i + 1, promedio);

            }
            break;
        
        case 2: 
            for (j = 0; j < 3; j++)
            {
                suma = 0;
                for ( i = 0; i < 5; i++)
                {
                    suma = suma + notas[i][j];
                }
                promedio = suma / 5;
                printf ("Asignatura %d: %.2f\n", j + 1, promedio);
            
            }   
            break;
        
        case 3: 
            for ( i = 0; i < 5; i++)
            {
                mayor = notas [i][0];
                menor = notas [i][0];


                for ( j = 0; j < 3; j++)
                {
                    if (notas[i][j] < menor)
                    menor = notas[i][j];
                    if (notas[i][j] > mayor)
                    mayor = notas[i][j];
                }
                
                printf ("Estudiante %d: mayor %.2f, menor %.2f\n", i + 1, mayor, menor);
            }
            break;

        case 4:
            
            for ( j = 0; j < 3; j++)
            {
                mayor = menor = notas [0][j];
            
                for ( i = 0; i < 5; i++)
                {
                    if (notas[i][j] > mayor)
                    mayor = notas [i][j];
                    if (notas[i][j] < menor)
                    menor = notas[i][j];
                }
                printf ("Asignatura %d: mayor %.2f, menor %.2f\n", j + 1, mayor, menor);

            
            
            }
            break;
        
        case 5: 
             
            for ( j = 0; j < 3; j++)
            {
                aprobados = 0;
                reprobados = 0;

                for ( i = 0; i < 5; i++)
                {
                    if (notas[i][j] >= 6)
                        aprobados++;
                    else
                        reprobados++;
                }
                printf ("Asignatura %d Aprobados: %d | Reprobados: %d\n", j + 1, aprobados, reprobados);
            }
            break;
        case 6:
            
            printf ("Programa finalizado con exito\n");
            break;

        default:
            printf ("El numero ingresado no existe porfavor intente nuevamente\n");    

        }

        system ("pause");
        

    } while (opcion != 6);
    
    
}
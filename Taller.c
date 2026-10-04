#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id, stock, opcion;
    float precio = 0, ganancias = 0;
    char nombre[50];
    int cantidad_venta, cantidad_reabastecer;
    float descuento, precio_final, total_venta;

    do
    {   

        system ("cls");


        printf("\t    SISTEMA DE GESTION DE INVENTARIO\n");
        printf("\t 1. Registrar Producto\n");
        printf("\t 2. Vender Unidades del producto\n");
        printf("\t 3. Reabastecer el producto\n");
        printf("\t 4. Informacion sobre el producto\n");
        printf("\t 5. Ganancias\n");
        printf("\t 6. Para terminar el programa\n");
        printf("\n\t Elija una opcion: ");
        scanf("%d",&opcion);
        while(getchar() != '\n'&& getchar() != EOF); 
        switch(opcion)
        {
        case 1:
            printf ("\t Escriba su ID: ");
            scanf ("%d",&id);
            printf ("\t Escriba el nombre: ");
            scanf ("%s", nombre);
            printf ("\t Ingrese la cantidad en stock: ");
            scanf ("%d",&stock);
            printf ("\t Ingrese el precio Unitario: ");
            scanf ("%f",&precio);
            printf ("\n\t El producto ha sido registrado con exito.\n");
            system("pause");

            break;
        
        case 2:
            printf ("\t Cantidad a vender: ");
            scanf ("%d",&cantidad_venta);
            if (cantidad_venta <= 0 )
            {
                printf ("\n\t Porfavor ingrese un numero mayor a 0 \n");

            }
            else if (cantidad_venta > stock)
            {
                printf ("\n\t Solo se dispone de %d unidades \n", stock);
            }
            else
            {
                printf ("\t Descuento (%%): ");
                scanf ("%f", &descuento);

                precio_final = precio -(precio * descuento / 100);
                total_venta = cantidad_venta * precio_final;
                
                stock = stock - cantidad_venta;
                ganancias = ganancias + total_venta;

                printf ("\t Venta exitosa. El total es: $%.2f\n", total_venta);

            }
            printf("\n");
            system ("pause");
            break;
        
        case 3:
        
            printf ("\t Ingrese una cantidad para abastecer: ");
            scanf ("%d",&cantidad_reabastecer);

            if (cantidad_reabastecer <= 0 )
            {
                printf ("\n\t Porfavor ingrese un numero mayor a 0 \n");
            }
            else
            {
                stock = stock + cantidad_reabastecer;
                printf ("\n\t El nuevo stock es: %d\n",stock);

            }
            system ("pause");
            break;
            

        case 4:
            printf ("\t ID:\t %d\n", id);
            printf ("\t Nombre del producto:\t %s\n", nombre);
            printf ("\t Stock disponible;\t %d\n",stock);
            printf ("\t Precio Unitario:\t $%.2f\n",precio);
            printf ("\n");
            system ("pause");
            break;
           
        
        case 5:

            printf ("\t Las ganancias totales son:  $%.2f\n",ganancias);
            printf ("\n");
            system ("pause");
            break;
        case 6:
            
            printf ("\t Programa terminado... \n");
            break;

        default:
            printf ("El numero ingresado no existe. \n");
            system ("pause");
            break;
        }

    } while (opcion != 6);

    return 0;
    
}

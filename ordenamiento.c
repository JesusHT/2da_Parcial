// Jesús Emmanuel Hernandez Torres
#include <stdio.h>
#include <stdlib.h>

int *lista;

void imprimir(int n){
    for (int i = 0; i < n-1; i++){
        printf("%d, ",lista[i]);
    }
    printf("%d \n",lista[n-1]);
}

void swap(int *listaMin, int *listaI){
	int temp = *listaMin;
	*listaMin = *listaI;
	*listaI = temp;
}

void ordenamiento(int n){
    int min;

    for(int i=0; i < n;i++){
        min = i;

        for (int j = i+1; j < n; j++){
            if(lista[j] < lista[min]){
                min = j;
            }   
        }
        
        if (min != i){
           swap(&lista[min], &lista[i]);
        }
    }
}


int main(){
   int tam;

    printf("Cuantos numeros deseas ordenar: ");
    scanf("%d",&tam);

	lista = (int *) malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++){
        printf("Ingrese le valor de la lista en la posición %d: ",i);
        scanf("%d",&lista[i]);
    }

    printf("\nlista desordenada\n");
    imprimir(tam);

    ordenamiento(tam);

    printf("\nlista ordenada\n");
    imprimir(tam);

    lista = NULL;
}

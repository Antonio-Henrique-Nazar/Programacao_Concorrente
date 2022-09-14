#include <stdio.h>
#include <stdlib.h>
float *matriz;
float *vetor;
float *saida;

int main(int argc, char* argv[]){
    int dim;
    if(argc<2){
        printf("Digite %s <dimensao da matriz>\n", argv[0]);
        return 1;
    }
    dim = atoi(argv[1]);
    matriz = (float*)malloc(sizeof(float) * dim * dim);
    if(matriz==NULL){
        printf("Erro de alocacao de memoria(matriz)\n");
        return 2;
    }
    vetor = (float *)malloc(sizeof(float) * dim);
    if(vetor==NULL){
        printf("Erro de alocacao de memoria(vetor)\n");
        return 2;
    }
    saida = (float *)malloc(sizeof(float) * dim);
    if(saida==NULL){
        printf("Erro de alocacao de memoria(saida)\n");
        return 2;
    }
    //Criacao
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim;j++){
            matriz[i*dim+j]=1;
            vetor[i] = 1;
            saida[i] = 0;
        }
    }
    //Multiplicacao
    for (int i = 0; i < dim;i++){
        for (int j = 0; j < dim;j++){
            saida[i] += matriz[i * dim + j] * vetor[j];
        }
    }

        // Leitura
        puts("Matriz de entrada\n");
    for (int i= 0; i < dim;i++){
        for (int j = 0; j < dim;j++){
            printf("%lf ", matriz[i * dim + j]);
        }
    }
    puts("\nVetor de entrada\n");
        for (int j = 0; j < dim;j++){
            printf("%lf ", vetor[j]);

        }
        puts("\nSaida de entrada\n");
        for (int j = 0; j < dim;j++){
            printf("%lf ", saida[j]);
        }
        free(matriz);
        free(vetor);
        free(saida);

        return 0;
}
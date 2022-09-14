#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
int main(int argc, char* argv[]){
    // Inicialização das variáveis
    int linha1;
    int coluna1;
    int linha2;
    int coluna2;
    int tamanho1;
    int tamanho2;
    float *matriz1;
    float *matriz2;
    float *saida;
    FILE *descritorArquivo;
    size_t ret;
    // Checar se a entrada foi correta 
    if(argc!=3){
        printf("Erro nas entradas do arquivo\n");
        return 2;
    }
    // Abrir arquivos para leitura binaria
    descritorArquivo = fopen(argv[1], "rb");
    if(!descritorArquivo){
        fprintf(stderr, "Erro de abertura do primeiro arquivo\n");
        return 3;
    }
    ret = fread(&linha1, sizeof(int), 1, descritorArquivo);
    if(!ret){
        fprintf(stderr, "Erro na leitura da linha da matriz1\n");
        return 4;
    }
    ret = fread(&coluna1, sizeof(int), 1, descritorArquivo);
    if(!ret){
        fprintf(stderr, "Erro na leitura da coluna da matriz1\n");
        return 4;
    }
    // Cria a matriz 1 no programa
    tamanho1 = linha1 * coluna1;
    matriz1 = (float *)(malloc(sizeof(float) * tamanho1));
    if(!matriz1){
        printf("Erro Alocacao matriz1\n");
        return 1;
    }
    // Le a matriz 1 do arquivo
    ret = fread(matriz1, sizeof(float), tamanho1, descritorArquivo);
    if(ret!=tamanho1){
        fprintf(stderr, "Erro na leitura da matriz\n");
        return 4;
    }
    fclose(descritorArquivo);
    // Abertura do segundo arquivo
    descritorArquivo = fopen(argv[2], "rb");
    if(!descritorArquivo){
        fprintf(stderr, "Erro de abertura do segundo arquivo\n");
        return 3;
    }
    // Pegar parametros para a segunda matriz
    ret = fread(&linha2, sizeof(int), 1, descritorArquivo);
    if(!ret){
        fprintf(stderr, "Erro na leitura da linha da matriz2\n");
        return 4;
    }
    ret = fread(&coluna2, sizeof(int), 1, descritorArquivo);
    if(!ret){
        fprintf(stderr, "Erro na leitura da coluna da matriz2\n");
        return 4;
    }
    // Cria a segunda matriz
    matriz2 = (float *)(malloc(sizeof(float) * linha2 * coluna2));
    if(!matriz2){
        printf("Erro Alocacao matriz2\n");
        return 1;
    }
    tamanho2 = linha2 * coluna2;
    // Le a matriz 2 do arquivo
    ret = fread(matriz2, sizeof(float), tamanho2, descritorArquivo);
    if(ret!=tamanho2){
        fprintf(stderr, "Erro na leitura da matriz\n");
        return 4;
    }
    fclose(descritorArquivo);

    // Cria a matriz de saida
    saida = (float *)(malloc(sizeof(float) * linha1 * coluna2));
    if(!saida){
        printf("Erro Alocacao saida\n");
        return 1;
    }   
    
      for (int i = 0; i < linha1;i++){
        for (int j = 0; j < coluna2;j++){
            *(saida + i*coluna2 +j) = 0.0f;
        }
    }
    
    for (int i = 0; i < linha1;i++){
        for (int j = 0; j < coluna2;j++){
            for (int k = 0; k < linha2;k++)
            {
                *(saida + i * coluna2 + j) += *(matriz1 + i * coluna1 + k) * (*(matriz2 + k * coluna2 + j));
            }
        }
    }
    
    for (int i = 0; i < linha1;i++){
        for (int j = 0; j < coluna2;j++){
            printf("%f ",*(saida + i*coluna2 +j));
        }
        printf("\n");
    }
        free(matriz1);
        free(matriz2);
        free(saida);
}
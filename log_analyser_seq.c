/*
Referências:
https://medium.com/@future_fanatic/a-beginners-guide-to-file-handling-in-c-with-fopen-e0e7c6969b92
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *arquivo;
    char linha[1000];
    arquivo = fopen("/Users/joaopioltini/Documents/Mackenzie/Paralela/Projeto 1/access_log_large.txt", "r");
    if(arquivo == NULL){
        perror("Error opening file!");
        return 1;
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;

}
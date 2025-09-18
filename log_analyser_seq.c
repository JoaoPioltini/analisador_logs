/*
Referências:
https://medium.com/@future_fanatic/a-beginners-guide-to-file-handling-in-c-with-fopen-e0e7c6969b92
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *arquivo;
    char *linha = NULL;
    size_t len = 0;
    size_t read;
    int max_linhas = 2;
    int count = 0;
    arquivo = fopen("/Users/joaopioltini/Documents/Mackenzie/Paralela/Projeto 1/analisador_logs/access_log_large.txt", "r");
    if(arquivo == NULL){
        perror("Error opening file!");
        exit(EXIT_FAILURE);
    }

    while((read = getline(&linha, &len,arquivo)) != NULL){
        if (count == max_linhas){
            break;
        }
        count++;
        char *quote_ptr = strstr(linha , "\" ");
        if (quote_ptr){
            int status_code;
            long long bytes_sent;
            if(sscanf(quote_ptr + 2, "%d %lld", &status_code, &bytes_sent) == 2) {
                printf("status: %d, bytes: %lld\n", status_code, bytes_sent);
            };
        }
    }

    fclose(arquivo);
    if(linha){
        free(linha);
    }
    return 0;

}
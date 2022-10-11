#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // permite abrir, ler e fechar diretórios

int main(){
    char d[50];
    DIR *p; // variável de fluxo de diretório: é um ponteiro que permite abrir/fechar um diretório e ler arquivos e subdiretórios que estao dentro desse diretório
    struct dirent *d1; // d1: diretório de entrada → é um ponteiro para um struct
    printf("Entre com um nome de um diretório:\n");
    scanf("%s",d);
    p = opendir(d); // abre o fluxo de diretório → se falhar retorna NULL
    if( p==NULL ){
    perror("Diretório não encontrado");
    exit(-1);
    }
    // (d1 = readdir(directory)) != NULL
    while( d1 = readdir(p) )  // fica sempre acessando o próximo diretório de entrada e printa o nome dele
    printf("%s\n",d1->d_name);
}
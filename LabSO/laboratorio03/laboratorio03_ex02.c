#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	char buff[100], fn[10]; /* buff: buffer | fn: file name */
	int fd, n; /* fd : file descriptor */
		   /* número de bytes */
	printf("Entre com o nome de um arquivo \n");
	scanf("%s", fn);
	fd = open(fn, O_RDONLY);
	if (fd != -1){
		n = read(fd, buff,100);
		if (n == 0){
			printf("arquivo vazio");
		}
		n = write(1, buff,n);
		printf("\n\nCaracteres lidos e exibidos: %d\n",n);
		close(fd);
	} else{
		printf("ERRO AO ABRIR O ARQUIVO");
	}
	return 0;
}

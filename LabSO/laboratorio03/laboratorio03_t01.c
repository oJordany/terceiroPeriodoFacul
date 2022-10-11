#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void discard_remainder_of_line(void)
{
    int c;
    
    do
    {
        c = getchar(); // lê um caracter de stdin

    } while ( c != EOF && c != '\n' ); // EOF: End Of Line
}

int main(){
	char buff[100], fn[20];
	int fd, n, i;
	printf("Entre com o nome de um arquivo novo:\n");
	scanf("%s", fn);
	discard_remainder_of_line();
	printf("\nEntre com um texto qualquer:\n");
	// scanf("%s*c", buff);
	fgets(buff, 100, stdin);
	fd = open(fn, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
	n = write(fd, buff, strlen(buff));
	close(fd);
	printf("\n\nVeja o conteúdo do arquivo criado\n");
	return 0;
}
// F: file
// GET: pegar
// S: String
// fgets() é uma função muito utilizada para fazer a leitura de texto do arquivo
// como essa função é bem genérica, a gente consegue utilizar ela também para fazer a leitura de texto a partir do teclado
// PARÂMETROS:
// primeiro: char* →  onde deseja salvar o texto que será lido
// segundo: int → a quantidade máxima de caracteres que deve ser lido. Assim, eu garanto que só serão lidos 100 caracteres e o resto é perdido
// terceiro: FILE* →  Nesse caso não é de nenhum arquivo e sim do buffer de entrada (buffer do teclado →  entrada padrão → standard input → stdin)
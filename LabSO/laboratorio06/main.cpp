#include "inverse.cpp"
#include <unistd.h>

#define BUFSIZE 80

int main()
{
  float a[25][25], b[25][25], k, d;
  int i, j, fd[2];

  inverseMatrix inverseA;
  inverseMatrix inverseB;

  float aux[25][25];

  pipe(fd); /* fd[0] - leitura, fd[1] - escrita */

  printf("Enter the order of the Matrices '': ");
  scanf("%f", &k);
  printf("Enter the elements of %.0fX%.0f Matrix A: \n", k, k);
  for (i = 0; i < k; i++)
  {
    for (j = 0; j < k; j++)
    {
      scanf("%f", &a[i][j]);
    }
  }
  printf("Enter the elements of %.0fX%.0f Matrix B: \n", k, k);
  for (i = 0; i < k; i++)
  {
    for (j = 0; j < k; j++)
    {
      scanf("%f", &b[i][j]);
    }
  }
  if (fork() == 0)
  {
    close(fd[0]);

    d = determinant(b, k);
    if (d == 0)
      printf("\nInverse of Entered Matrix is not possible\n");
    else
    {
      inverseB = cofactor(b, k);
      write(fd[1], inverseB.matrix, sizeof(aux));
    }
  }
  else
  {
    close(fd[1]);

    d = determinant(a, k);
    if (d == 0)
      printf("\nInverse of Entered Matrix is not possible\n");
    else
    {
      inverseA = cofactor(a, k);
      read(fd[0], aux, sizeof(aux));
      multiplication(inverseA.matrix, aux, k);
    }
  }
}

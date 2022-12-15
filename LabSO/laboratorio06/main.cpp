#include "inverse.cpp"

int main()
{
  float a[25][25], b[25][25], k, d;
  int i, j;
  float **inverseA;
  float **inverseB;

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
  d = determinant(a, k);
  if (d == 0)
    printf("\nInverse of Entered Matrix is not possible\n");
  else
  {
    inverseA = cofactor(a, k);
    printf("\n\n\nThe inverse of matrix A is : \n");
    for (i = 0; i < k; i++)
    {
      for (j = 0; j < k; j++)
      {
        printf("\t%.2f", inverseA[i][j]);
      }
      printf("\n");
    }
    inverseB = cofactor(b, k);

    printf("\n\n\nThe inverse of matrix B is : \n");

    for (i = 0; i < k; i++)
    {
      for (j = 0; j < k; j++)
      {
        printf("\t%.2f", inverseB[i][j]);
      }
      printf("\n");
    }
    printf("\n\n\nThe inverse of matrix A is : \n");
    for (i = 0; i < k; i++)
    {
      for (j = 0; j < k; j++)
      {
        printf("\t%.2f", inverseA[i][j]);
      }
      printf("\n");
    }
  }
}
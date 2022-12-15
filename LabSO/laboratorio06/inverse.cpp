#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

float determinant(float[][25], float);
void cofactor(float[][25], float);
void transpose(float[][25], float[][25], float);
int multiplication(float[25][25], float[25][25], float);

/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
  {
    return (a[0][0]);
  }
  else
  {
    det = 0;
    for (c = 0; c < k; c++)
    {
      m = 0;
      n = 0;
      for (i = 0; i < k; i++)
      {
        for (j = 0; j < k; j++)
        {
          b[i][j] = 0;
          if (i != 0 && j != c)
          {
            b[m][n] = a[i][j];
            if (n < (k - 2))
              n++;
            else
            {
              n = 0;
              m++;
            }
          }
        }
      }
      det = det + s * (a[0][c] * determinant(b, k - 1));
      s = -1 * s;
    }
  }

  return (det);
}

void cofactor(float num[25][25], float f)
{
  float b[25][25], fac[25][25];
  int p, q, m, n, i, j;
  for (q = 0; q < f; q++)
  {
    for (p = 0; p < f; p++)
    {
      m = 0;
      n = 0;
      for (i = 0; i < f; i++)
      {
        for (j = 0; j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
              n++;
            else
            {
              n = 0;
              m++;
            }
          }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}

/*Finding transpose of matrix*/
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      b[i][j] = fac[j][i];
    }
  }
  d = determinant(num, r);
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      inverse[i][j] = b[i][j] / d;
    }
  }
  
  multiplication(inverse, inverse, 2);
  printf("\n\n\nThe inverse of matrix is : \n");

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      printf("\t%.2f", inverse[i][j]);
    }
    printf("\n");
  }
}

int multiplication(float matrixA[25][25], float matrixB[25][25], float ki)
{
  int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;
  r1 = 2;
  c1 = 2;
  r2 = 2;
  c2 = 2;
  // Initializing elements of matrix mult to 0.
  for (i = 0; i < r1; ++i)
  {
    for (j = 0; j < c2; ++j)
    {
      mult[i][j] = 0;
    }
  }

  // Multiplying matrix a and b and storing in array mult.
  for (i = 0; i < r1; ++i)
  {
    for (j = 0; j < c2; ++j)
    {
      for (k = 0; k < c1; ++k)
      {
        cout << matrixA[i][k];
        mult[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
  // Displaying the multiplication of two matrix.
  cout << endl
       << "Output Matrix: " << endl;
  for (i = 0; i < r1; ++i)
  {
    for (j = 0; j < c2; ++j)
    {
      cout << " " << mult[i][j];
      if (j == c2 - 1)
        cout << endl;
    }
  }

  return 0;
}

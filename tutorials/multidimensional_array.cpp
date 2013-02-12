#include <cstdio>
#include <cstdlib>
#include <cmath>

#define LINEARIZED

#define ROWMAJOR

typedef double *Vector;

Vector allocate_vector(int dim)
{
  return (Vector) malloc(dim*sizeof(double));
}

#ifdef LINEARIZED
/**************************************************************************************
 * Flattened array implementation
 **************************************************************************************/

typedef double *Matrix;

int get_linear_index(int i, int j, int rows, int columns) {
#ifdef ROWMAJOR
  return i*rows + j;
#else
  return i + j*columns;
#endif
}

Matrix allocate_identity(int rows, int columns)
{
  Matrix res = (Matrix) calloc(rows*columns, sizeof(double));

  for (int i = 0 ; i < rows; ++i) {
    if (i < columns) {
      res[get_linear_index(i, i, rows, columns)] = 1.0;
    }
  }
  return res;
}

double get_matrix_element(Matrix matrix, int i, int j, int rows, int columns) {
  return matrix[get_linear_index(i, j, rows, columns)];
}

#else
/**************************************************************************************
 * Pointer-to-pointer implementation
 **************************************************************************************/

typedef double **Matrix;

Matrix allocate_identity(int rows, int columns)
{
  Matrix res = (Vector *) malloc(rows*sizeof(Vector));

  for (int i = 0 ; i < rows; ++i) {
    res[i] = (Vector) calloc(columns, sizeof(double));
    if (i < columns) {
      res[i][i] = 1.0;
    }
  }
  return res;
}

double get_matrix_element(Matrix matrix, int i, int j, int rows, int columns) {
  return matrix[i][j];
}

#endif

/**************************************************************************************
 * Common rest
 **************************************************************************************/

void matrix_vector_product(Matrix matrix, Vector vector, Vector result, int rows, int columns)
{
  for (int i = 0 ; i < rows; ++i) {
    double sum = 0;
    for (int j = 0; j < columns; ++j) {
      sum += get_matrix_element(matrix, i, j, rows, columns) * vector[j];
    }
    result[i] = sum;
  }
}

double norm(Vector vector, int dim)
{
    double sum = 0;
    for (int j = 0; j < dim; ++j) {
      sum += vector[j]*vector[j];
    }
    return sqrt(sum);
}

const int dim = 10000;
const int iterations = 10;

/**************************************************************************************
 * Main, simple vector iteration
 **************************************************************************************/

int main()
{
  Matrix matrix = allocate_identity(dim, dim);
  /* double buffering, we start at vector1 */
  Vector vector1 = allocate_vector(dim);
  Vector vector2 = allocate_vector(dim);

  for (int j = 0; j < dim; ++j) {
    vector1[j] = 1.0;
  }

  for (int it = 0; it < iterations; ++it) {
    matrix_vector_product(matrix, vector1, vector2, dim, dim);
    matrix_vector_product(matrix, vector2, vector1, dim, dim);
  }

  printf("%lf\n", norm(vector1, dim));
}

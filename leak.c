#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **add_square_matrices(int **a, int **b, int n) {
  int **c = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    c[i] = malloc(sizeof(int) * n);
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      c[y][x] = a[y][x] + b[y][x];
    }
  }

  return c;
}

void free_matrix(int **mat, int height, int width);

int main(int argc, char *argv[]) {
  int **a = malloc(sizeof(int *) * 3);
  int **b = malloc(sizeof(int *) * 3);

  for (int i = 0; i < 3; i++) {
    a[i] = malloc(sizeof(int) * 3);
    b[i] = malloc(sizeof(int) * 3);
  }

  a[0][0] = 1;
  a[0][1] = 2;
  a[0][2] = 3;
  a[1][0] = 4;
  a[1][1] = 5;
  a[1][2] = 6;
  a[2][0] = 7;
  a[2][1] = 8;
  a[2][2] = 9;

  b[0][0] = 9;
  b[0][1] = 8;
  b[0][2] = 7;
  b[1][0] = 6;
  b[1][1] = 5;
  b[1][2] = 4;
  b[2][0] = 3;
  b[2][1] = 2;
  b[2][2] = 1;

  int **c = add_square_matrices(a, b, 3);
  print_matrix(c, 3, 3);

  free_matrix(a, 3, 3);
  free_matrix(b, 3, 3);
  free_matrix(c, 3, 3);
}

void free_matrix(int **mat, int height, int width) {
  // your free code here
}


#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int n = mat->rows;

    for (int col = 0; col < n; col++) {
        int pivotRow = col;
        for (int row = col + 1; row < n; row++) {
            if (fabs(mat->data[row][col]) > fabs(mat->data[pivotRow][col])) {
                pivotRow = row;
            }
        }

        if (fabs(mat->data[pivotRow][col]) < EPSILON) {
            return -1;
        }

        if (pivotRow != col) {
            swapRows(mat, b, pivotRow, col);
        }

        for (int row = col + 1; row < n; row++) {
            double factor = mat->data[row][col] / mat->data[col][col];

            for (int k = col; k < n; k++) {
                mat->data[row][k] -= factor * mat->data[col][k];
            }

            b->data[row][0] -= factor * b->data[col][0];
        }
    }

    return 0;
}


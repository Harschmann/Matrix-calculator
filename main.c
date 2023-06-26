#include <stdio.h>

#define MAX_SIZE 10

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[][MAX_SIZE], int transpose[][MAX_SIZE], int rows, int cols);
void inverseMatrix(int matrix[][MAX_SIZE], int size, double inverse[][MAX_SIZE]);
double calculateDeterminant(int matrix[][MAX_SIZE], int size);

int main()
{
    printf("Harsh Kumar\n");

    int choice;
    int rows1, cols1, rows2, cols2;

    printf("Matrix Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Inverse\n");
    printf("5. Determinant\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2)
    {
        printf("Enter the number of rows and columns for Matrix 1: ");
        scanf("%d %d", &rows1, &cols1);
        printf("Enter the number of rows and columns for Matrix 2: ");
        scanf("%d %d", &rows2, &cols2);

        if (rows1 != rows2 || cols1 != cols2)
        {
            printf("Error: Matrices must have the same dimensions for addition/subtraction.\n");
            return 0;
        }
    }
    else if (choice == 3)
    {
        printf("Enter the number of rows and columns for Matrix 1: ");
        scanf("%d %d", &rows1, &cols1);
        printf("Enter the number of rows and columns for Matrix 2: ");
        scanf("%d %d", &rows2, &cols2);

        if (cols1 != rows2)
        {
            printf("Error: The number of columns in Matrix 1 must be equal to the number of rows in Matrix 2 for multiplication.\n");
            return 0;
        }
    }
    else if (choice == 4 || choice == 5)
    {
        printf("Enter the size of the square matrix: ");
        scanf("%d", &rows1);
        cols1 = rows1;
    }
    else
    {
        printf("Invalid choice. Please select a valid option (1-5).\n");
        return 0;
    }

    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    double inverse[MAX_SIZE][MAX_SIZE];
    int determinant;

    printf("\nEnter elements of Matrix 1:\n");
    readMatrix(matrix1, rows1, cols1);

    if (choice == 1 || choice == 2 || choice == 3)
    {
        printf("\nEnter elements of Matrix 2:\n");
        readMatrix(matrix2, rows2, cols2);
    }

    switch (choice)
    {
        case 1:
            addMatrices(matrix1, matrix2, result, rows1, cols1);
            printf("\nMatrix 1 + Matrix 2:\n");
            displayMatrix(result, rows1, cols1);
            break;

        case 2:
            subtractMatrices(matrix1, matrix2, result, rows1, cols1);
            printf("\nMatrix 1 - Matrix 2:\n");
            displayMatrix(result, rows1, cols1);
            break;

        case 3:
            multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
            printf("\nMatrix 1 * Matrix 2:\n");
            displayMatrix(result, rows1, cols2);
            break;

        case 4:
            inverseMatrix(matrix1, rows1, inverse);
            printf("\nInverse of Matrix 1:\n");
            displayMatrix((int *)inverse, rows1, cols1);
            break;

        case 5:
            determinant = calculateDeterminant(matrix1, rows1);
            printf("\nDeterminant of Matrix 1: %d\n", determinant);
            break;
    }

    return 0;
}

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int transpose[][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

double calculateDeterminant(int matrix[][MAX_SIZE], int size)
{
    double det = 0;

    if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else
    {
        int subMatrix[MAX_SIZE][MAX_SIZE];
        int sign = 1;

        for (int k = 0; k < size; k++)
        {
            int subI = 0, subJ = 0;

            for (int i = 1; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (j != k)
                    {
                        subMatrix[subI][subJ++] = matrix[i][j];

                        if (subJ == size - 1)
                        {
                            subJ = 0;
                            subI++;
                        }
                    }
                }
            }

            det += sign * matrix[0][k] * calculateDeterminant(subMatrix, size - 1);
            sign = -sign;
        }
    }

    return det;
}

void getCofactor(int matrix[][MAX_SIZE], int temp[][MAX_SIZE], int p, int q, int size)
{
    int i = 0, j = 0;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];

                if (j == size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjointMatrix(int matrix[][MAX_SIZE], int adjoint[][MAX_SIZE], int size)
{
    if (size == 1)
    {
        adjoint[0][0] = 1;
        return;
    }

    int sign = 1;
    int temp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            getCofactor(matrix, temp, i, j, size);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * calculateDeterminant(temp, size - 1);
        }
    }
}

void inverseMatrix(int matrix[][MAX_SIZE], int size, double inverse[][MAX_SIZE])
{
    int det = calculateDeterminant(matrix, size);

    if (det == 0)
    {
        printf("Error: The matrix is not invertible as the determinant is zero.\n");
        return;
    }

    int adjoint[MAX_SIZE][MAX_SIZE];
    adjointMatrix(matrix, adjoint, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            inverse[i][j] = adjoint[i][j] / (double)det;
        }
    }
}

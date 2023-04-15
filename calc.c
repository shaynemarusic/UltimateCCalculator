#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Matrix {
    double determinant;
    double ** matrix;
    int height;
    int width;
} Matrix;

//Prototypes

//Menus
void ScalarOpsMenu();
int PrintInitialMenu();
void MatrixOpsMenu();

//Scalar Function Prototypes
double ScalarAddition(double * result);
double ScalarSubtraction(double * result);
double ScalarMultiplication(double * result);
double ScalarDivision(double * result);
int ScalarModulo(double * result);
double ScalarExponentiation(double * result);

//Matrix Function Prototypes
void MatrixScalarMultiplicationInterface(Matrix * result);
void MatrixAdditionInterface(Matrix * result);
void MatrixCompositionInterface(Matrix * result);
double ** UserInitializeMatrix(int height, int width);
double ** MatrixAddition(double ** matrix1, double ** matrix2, int height, int width);
double ** MatrixScalarMultiplication(double ** matrix, double scalar, int height, int width);
double ** MatrixComposition(double ** leftMatrix, double ** rightMatrix, int leftHeight, int sharedDimension, int rightWidth);
void PrintMatrix(double ** matrix, int height, int width);
void DestroyMatrix(double ** matrix, int height, int width);
double ** InitializeIdentityMatrix(int height, int width);
double ** InitializeZeroMatrix(int height, int width);

int main() {
    printf("Welcome to the Ultimate C Calculator v1.0.1!\n");
    int cont = 1;
    
    while (cont) {
        switch(PrintInitialMenu()) {
            case (1):
                ScalarOpsMenu();
                break;
            case (2):
                MatrixOpsMenu();
                break;
            case (3):
                cont = 0;
                printf("Thank you for using the Ultimate C Calculator");
                break;
            default:
                printf("Not a valid menu selection. Please try again\n");
        }
    }
    return 0;
}

//Menu Function Definitions

int PrintInitialMenu() {
    printf("What would you like to do?\n1. Scalar Math\n2. Matrix Math\n3. Exit\n");
    int input;
    scanf("%d", &input);
    return input;
}

void ScalarOpsMenu() {
    int input;
    int cont = 1;
    double resultBuffer;
    double * result = NULL;
    while (cont) {
        printf("What scalar operation would you like to perform?\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulo\n6. Exponentiation\n7. Clear results\n8. Return to main menu\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                resultBuffer = ScalarAddition(result);
                result = &resultBuffer;
                break;
            case 2:
                resultBuffer = ScalarSubtraction(result);
                result = &resultBuffer;
                break;
            case 3:
                resultBuffer = ScalarMultiplication(result);
                result = &resultBuffer;
                break;
            case 4:
                resultBuffer = ScalarDivision(result);
                result = &resultBuffer;
                break;
            case 5:
                resultBuffer = (double) ScalarModulo(result);
                result = &resultBuffer;
                break;
            case 6:
                resultBuffer = ScalarExponentiation(result);
                result = &resultBuffer;
                break;
            case 7:
                result = NULL;
                break;
            case 8:
                cont = 0;
                break;
            default:
                printf("Not a valid menu selection. Please try again");
        }
    }
}

void MatrixOpsMenu() {
    int input;
    int cont = 1;
    Matrix result = {0, NULL, 0, 0};
    while (cont) {
        printf("What matrix operation would you like to perform?\n1. Addition\n2. Scalar Multiplication\n3. Matrix Multiplication\n4. Calculate Determinant\n5. Invert\n6. Diagonalize\n7. Clear Results\n8. Exit\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                MatrixAdditionInterface(&result);
                break;
            case 2:
                MatrixScalarMultiplicationInterface(&result);
                break;
            case 3:
                MatrixCompositionInterface(&result);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                DestroyMatrix(result.matrix, result.height, result.width);
                result.matrix = NULL;
                break;
            case 8:
                cont = 0;
                break;
            default:
                printf("Not a valid menu selection. Please try again\n");
        }
    }
}

//Scalar Operation Definitions

double ScalarAddition(double * result) {
    double operand1;
    double operand2;
    double tempRes;
    if (result != NULL) {
        printf("Enter operand: ");
        scanf("%lf", &operand1);
        tempRes = *result + operand1;
        printf("Result: %lf\n", tempRes);
    }
    else {
        printf("Enter first operand: ");
        scanf("%lf", &operand1);
        printf("Enter second operand: ");
        scanf("%lf", &operand2);
        tempRes = operand1 + operand2;
        printf("Result: %lf\n", tempRes);
    }
    return tempRes;
}

double ScalarSubtraction(double * result) {
    double operand1;
    double operand2;
    double tempRes;
    if (result != NULL) {
        printf("Enter operand: ");
        scanf("%lf", &operand1);
        tempRes = *result - operand1;
        printf("Result: %lf\n", tempRes);
    }
    else {
        printf("Enter first operand: ");
        scanf("%lf", &operand1);
        printf("Enter second operand: ");
        scanf("%lf", &operand2);
        tempRes = operand1 - operand2;
        printf("Result: %lf\n", tempRes);
    }
    return tempRes;
}

double ScalarMultiplication(double * result) {
    double operand1;
    double operand2;
    double tempRes;
    if (result != NULL) {
        printf("Enter operand: ");
        scanf("%lf", &operand1);
        tempRes = *result * operand1;
        printf("Result: %lf\n", tempRes);
    }
    else {
        printf("Enter first operand: ");
        scanf("%lf", &operand1);
        printf("Enter second operand: ");
        scanf("%lf", &operand2);
        tempRes = operand1 * operand2;
        printf("Result: %lf\n", tempRes);
    }
    return tempRes;
}

double ScalarDivision(double * result) {
    double operand1;
    double operand2;
    double tempRes;
    if (result != NULL) {
        printf("Enter operand: ");
        scanf("%lf", &operand1);
        tempRes = *result / operand1;
        printf("Result: %lf\n", tempRes);
    }
    else {
        printf("Enter first operand: ");
        scanf("%lf", &operand1);
        printf("Enter second operand: ");
        scanf("%lf", &operand2);
        tempRes = operand1 / operand2;
        printf("Result: %lf\n", tempRes);
    }
    return tempRes;
}

int ScalarModulo(double * result) {
    double operand1;
    double operand2;
    int tempRes;
    if (result != NULL) {
        printf("Enter operand - Note that floats will be rounded down: ");
        scanf("%lf", &operand1);
        tempRes = (int)*result % (int)operand1;
        printf("Result: %d\n", tempRes);
    }
    else {
        printf("Enter first operand - Note that floats will be rounded down: ");
        scanf("%lf", &operand1);
        printf("Enter second operand - Note that floats will be rounded down: ");
        scanf("%lf", &operand2);
        tempRes = (int) operand1 % (int) operand2;
        printf("Result: %d\n", tempRes);
    }
    return tempRes;
}

double ScalarExponentiation(double * result) {
    double operand1;
    double operand2;
    double tempRes;
    if (result != NULL) {
        printf("Enter operand: ");
        scanf("%lf", &operand1);
        tempRes = pow(*result, operand1);
        printf("Result: %lf\n", tempRes);
    }
    else {
        printf("Enter first operand: ");
        scanf("%lf", &operand1);
        printf("Enter second operand: ");
        scanf("%lf", &operand2);
        tempRes = pow(operand1, operand2);
        printf("Result: %lf\n", tempRes);
    }
    return tempRes;
}

double ** UserInitializeMatrix(int height, int width) {
    double ** matrix = (double **) calloc(height, sizeof(double*));
    for (int i = 0; i < height; i++) {
            matrix[i] = (double *) calloc(width, sizeof(double));
            for (int j = 0; j < width; j++) {
                printf("Row %d, Column %d: ", i, j);
                double element;
                scanf("%lf", &element);
                matrix[i][j] = element;
            }
    }
    return matrix;
}

void MatrixAdditionInterface(Matrix * result) {
    int height;
    int width;
    double ** matrix1 = NULL;
    double ** matrix2 = NULL;
    if (result->matrix != NULL) {
        printf("Initialize matrix: \n");
        matrix1 = UserInitializeMatrix(result->height, result->width);
        double ** hold = result->matrix;
        result->matrix = MatrixAddition(result->matrix, matrix1, result->height, result->width);
        PrintMatrix(result->matrix, result->height, result->width);
        DestroyMatrix(matrix1, result->height, result->width);
        DestroyMatrix(hold, result->height, result->width);
    }
    else {
        printf("Enter matrices' height: ");
        scanf("%d", &height);
        printf("Enter first matrices' width: ");
        scanf("%d", &width);
        printf("Initialize first matrix:\n");
        matrix1 = UserInitializeMatrix(height, width);
        printf("Initialize second matrix:\n");
        matrix2 = UserInitializeMatrix(height, width);
        result->matrix = MatrixAddition(matrix1, matrix2, height, width);
        result->height = height;
        result->width = width;
        PrintMatrix(result->matrix, height, width);
        DestroyMatrix(matrix1, height, width);
        DestroyMatrix(matrix2, height, width);
    }
}

double ** MatrixAddition(double ** matrix1, double ** matrix2, int height, int width) {
    double ** result = (double **) calloc(height, sizeof(double*));
    for (int i = 0; i < height; i++) {
        result[i] = (double *) calloc(width, sizeof(double));
        for (int j = 0; j < width; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

void PrintMatrix(double ** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        printf("|");
        for (int j = 0; j < width; j++) {
            printf(" %lf ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void DestroyMatrix(double ** matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        free((void *) matrix[i]);
    }
    free((void *) matrix);
}

double ** InitializeZeroMatrix(int height, int width) {
    double ** matrix = (double **) calloc(height, sizeof(double *));
    for (int i = 0; i < height; i++) {
        matrix[i] = (double *) calloc(width, sizeof(double));
        for (int j = 0; j < width; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void MatrixScalarMultiplicationInterface(Matrix * result) {
    int height;
    int width;
    double scalar;
    double ** matrix1 = NULL;
    if (result->matrix != NULL) {
        printf("Enter scalar: ");
        scanf("%lf", &scalar);
        double ** hold = result->matrix;
        result->matrix = MatrixScalarMultiplication(result->matrix, scalar, result->height, result->width);
        PrintMatrix(result->matrix, result->height, result->width);
        DestroyMatrix(hold, result->height, result->width);
    }
    else {
        printf("Enter matrix height: ");
        scanf("%d", &height);
        printf("Enter first matrix width: ");
        scanf("%d", &width);
        printf("Initialize matrix:\n");
        matrix1 = UserInitializeMatrix(height, width);
        printf("Enter scalar: ");
        scanf("%lf", &scalar);
        result->matrix = MatrixScalarMultiplication(matrix1, scalar, height, width);
        result->height = height;
        result->width = width;
        PrintMatrix(result->matrix, height, width);
        DestroyMatrix(matrix1, height, width);
    }
}

double ** MatrixScalarMultiplication(double ** matrix, double scalar, int height, int width) {
    double ** result = (double **) calloc(height, sizeof(double*));
    for (int i = 0; i < height; i++) {
        result[i] = (double *) calloc(width, sizeof(double));
        for (int j = 0; j < width; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

double ** InitializeIdentityMatrix(int height, int width) {
    double ** result = (double **) calloc(height, sizeof(double *));
    for (int i = 0; i < height; i++) {
        result[i] = (double *) calloc(width, sizeof(double));
        for (int j = 0; j < width; j++) {
            if (i == j) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = 0;
            }
        }
    }
    return result;
}

void MatrixCompositionInterface(Matrix * result) {
    int leftHeight;
    int sharedDimension;
    int rightWidth;
    double ** matrix1 = NULL;
    double ** matrix2 = NULL;
    if (result->matrix != NULL) {
        leftHeight = result->height;
        sharedDimension = result->width;
        printf("Enter width of right matrix: ");
        scanf("%d", &rightWidth);
        printf("Initialize right matrix:\n");
        matrix1 = UserInitializeMatrix(sharedDimension, rightWidth);
        double ** hold = result->matrix;
        result->matrix = MatrixComposition(result->matrix, matrix1, leftHeight, sharedDimension, rightWidth);
        PrintMatrix(result->matrix, leftHeight, rightWidth);
        DestroyMatrix(hold, leftHeight, sharedDimension);
        result->width = rightWidth;
    }
    else {
        printf("Enter height of left matrix: ");
        scanf("%d", &leftHeight);
        printf("Enter width of left matrix/height of right matrix: ");
        scanf("%d", &sharedDimension);
        printf("Initialize left matrix:\n");
        matrix1 = UserInitializeMatrix(leftHeight, sharedDimension);
        printf("Enter width of right matrix: ");
        scanf("%d", &rightWidth);
        printf("Initialize right matrix:\n");
        matrix2 = UserInitializeMatrix(sharedDimension, rightWidth);
        result->matrix = MatrixComposition(matrix1, matrix2, leftHeight, sharedDimension, rightWidth);
        result->height = leftHeight;
        result->width = rightWidth;
        PrintMatrix(result->matrix, leftHeight, rightWidth);
        DestroyMatrix(matrix1, leftHeight, sharedDimension);
        DestroyMatrix(matrix2, sharedDimension, rightWidth);
    }
}

double ** MatrixComposition(double ** leftMatrix, double ** rightMatrix, int leftHeight, int sharedDimension, int rightWidth) {
    double ** result = (double **) calloc(leftHeight, sizeof(double *));
    double entry;
    for (int i = 0; i < leftHeight; i++) {
        result[i] = (double *) calloc(rightWidth, sizeof(double));
        for (int j = 0; j < rightWidth; j++) {
            entry = 0;
            for (int k = 0; k < sharedDimension; k++) {
                entry += leftMatrix[i][k] * rightMatrix[k][j];
            }
            result[i][j] = entry;
        }
    }
    return result;
}
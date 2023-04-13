#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void MatrixAdditionInterface(double * result);
double ** UserInitializeMatrix(int height, int width);
double ** MatrixAddition(double ** matrix1, double ** matrix2, int height, int width);
void PrintMatrix(double ** matrix, int height, int width);

typedef struct MatrixReturn {
    double determinant;
    double ** matrix;
    int matrixHeight;
    int matrixWidth;
} MatrixReturn;

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
    MatrixReturn resultBuffer;
    double * result = NULL;
    while (cont) {
        printf("What matrix operation would you like to perform?\n1. Addition\n2. Scalar Multiplication\n3. Matrix Multiplication\n4. Calculate Determinant\n5. Invert\n6. Diagonalize\n7. Clear Results\n8. Exit");
        scanf("%d", &input);
        switch (input) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
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

void MatrixAdditionInterface(double * result) {
    int height;
    int width;
    double ** matrix1 = NULL;
    double ** matrix2 = NULL;
    double ** resMatrix = NULL;
    if (result != NULL) {

    }
    else {
        printf("Enter matrices' height: ");
        scanf("%d", &height);
        printf("Enter first matrices' width: ");
        scanf("%d", &width);
        printf("Initialize first matrix:\n");
        matrix1 = InitializeMatrix(height, width);
        printf("Initialize second matrix:\n");
        matrix2 = InitializeMatrix(height, width);
        
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
    
}
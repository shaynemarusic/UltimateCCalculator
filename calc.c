#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Ultimate C Calculator v1.0.0!\n");
    while (1) {
        printf("Please enter the first operand: ");
        double op1;
        scanf("%lf", &op1);
        printf("Please enter the second operand: ");
        double op2;
        scanf("%lf", &op2);
        printf("Lovely! Your operands are %lf and %lf\n", op1, op2);
        printf("What would you like to do?\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulo\n6. Exponentiate\n7. Exit\n");
        int choice;
        double result;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            result = op1 + op2;
            break;
        case 2:
            result = op1 - op2;
            break;
        case 3:
            result = op1 * op2;
            break;
        case 4:
            result = op1 / op2;
            break;
        case 5:
            result = (int) op1 % (int) op2;
            break;
        case 6:
            result = pow(op1, op2);
            break;
        default:
            printf("Beans");
            break;
        }
        printf("%lf", result);
    }
    return 0;
}
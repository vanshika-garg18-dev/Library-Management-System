#include <stdio.h>
#include <math.h>

long long factorial(int n)
{
    if (n < 0)
        return -1;

    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

int main()
{
    int choice;
    double a, b, result;
    int n;

    printf("\n");
    printf("=============================================\n");
    printf("        SCIENTIFIC CALCULATOR IN C\n");
    printf("=============================================\n");

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power (x^y)\n");
        printf("6. Square Root\n");
        printf("7. Cube Root\n");
        printf("8. Sine\n");
        printf("9. Cosine\n");
        printf("10. Tangent\n");
        printf("11. Log Base 10\n");
        printf("12. Natural Log\n");
        printf("13. Exponential (e^x)\n");
        printf("14. Factorial\n");
        printf("15. Percentage\n");
        printf("16. Absolute Value\n");
        printf("17. Value of PI\n");
        printf("18. Value of e\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf%lf", &a, &b);
                printf("Result = %.2lf\n", a + b);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf%lf", &a, &b);
                printf("Result = %.2lf\n", a - b);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf%lf", &a, &b);
                printf("Result = %.2lf\n", a * b);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf%lf", &a, &b);

                if(b == 0)
                    printf("Error! Division by zero.\n");
                else
                    printf("Result = %.2lf\n", a / b);
                break;

            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf%lf", &a, &b);
                printf("Result = %.2lf\n", pow(a, b));
                break;

            case 6:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result = %.2lf\n", sqrt(a));
                break;

            case 7:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result = %.2lf\n", cbrt(a));
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", sin(a * M_PI / 180));
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", cos(a * M_PI / 180));
                break;

            case 10:
                printf("Enter angle in degrees: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", tan(a * M_PI / 180));
                break;

            case 11:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", log10(a));
                break;

            case 12:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", log(a));
                break;

            case 13:
                printf("Enter value of x: ");
                scanf("%lf", &a);
                printf("Result = %.4lf\n", exp(a));
                break;

            case 14:
                printf("Enter integer: ");
                scanf("%d", &n);
                printf("Result = %lld\n", factorial(n));
                break;

            case 15:
                printf("Enter value and total: ");
                scanf("%lf%lf", &a, &b);
                printf("Percentage = %.2lf%%\n", (a / b) * 100);
                break;

            case 16:
                printf("Enter number: ");
                scanf("%lf", &a);
                printf("Result = %.2lf\n", fabs(a));
                break;

            case 17:
                printf("PI = %.15lf\n", M_PI);
                break;

            case 18:
                printf("e = %.15lf\n", M_E);
                break;

            case 0:
                printf("\nThank you for using the calculator!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}
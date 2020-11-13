#include <iostream>
// simple calculator
int main()
{
    double num1;
    double num2;
    int operation;
    double output;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("now the second number: ");
    scanf("%lf", &num2);
    printf("%lf and %lf, okay\n", num1, num2);
    printf("what do you want me to do?");
    printf("choose one of these numbers: \n1:add, \n2:subtract, \n3:divide, \n4:multiply\n");
    scanf("%d", operation);

    if (operation == 1)
    {
        output = num1 + num2;
    }
    else if (operation == 2)
    {
        output = num1 - num2;
    }
    else if (operation == 3)
    {
        output = num1 / num2;
    }
    else
    {
        output = num1 * num2;
    }

    printf("Here is the result: %lf", output);
    return 0;
}

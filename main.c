#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double NumberControl(int situation){
    double num;
    char buf[1024];
    int success;

    do
    {
        if (!fgets(buf, 1024, stdin))
        {

            return 1;
        }
        char *endptr;

        num = strtod(buf, &endptr);

        if (situation == 1){
            if (endptr == buf) {
                printf("You entered a character. Please enter number!\n");
                success = 0;
            }else if(num < 0){
                printf("The lengths of geometric bodies cannot be negative!\n");
                success = 0;
            } else {
                success = 1;
            }
        }else if (situation == 2){
            if (endptr == buf) {
                printf("You entered a character. Please enter number!\n");
                success = 0;
            }else {
                success = 1;
            }
        }

    } while (!success);

    return num;
}
double cube() {
    double volume,cubeEdge;
    printf("Enter any edge of the cube:\n"
           "->");
    cubeEdge = NumberControl(1);
    volume = pow(cubeEdge, 3);
    return volume;
}
void rectangularPrism() {
    double volume, rectangularEdge1, rectangularEdge2, prismHeight;
    printf("Enter the base sides of the rectangular prism perpendicular to each other:\n"
           "first edge ->");
    rectangularEdge1 = NumberControl(1);
    printf("second edge ->");
    rectangularEdge2 = NumberControl(1);
    printf("Enter the height of the rectangular prism:\n"
           "height ->");
    prismHeight = NumberControl(1);
    volume = rectangularEdge1 * rectangularEdge2 * prismHeight;
    printf("Volume: %.2lf\n", volume);

}
double sphere() {
    double volume, radius;
    printf("Enter the radius of the sphere:\n"
           "radius ->");
    radius = NumberControl(1);
    volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    return volume;
}
int main() {
    while(1){
    int geometricFigure, exit = 1;
    char runAgain;
    printf("Enter the geometric solid whose volume you want to find:\n"
           "1) Cube\n"
           "2) Rectangular prism\n"
           "3) Sphere\n"
           "4) Exit\n"
           "->");

        geometricFigure = NumberControl(2);
        switch (geometricFigure) {
            case 1:
                printf("Volume: %lf\n",cube());
                break;
            case 2:
                rectangularPrism();
                break;
            case 3:
                printf("Volume: %lf\n",sphere());
                break;
            case 4:
                exit = 0;
                break;
            default:
                printf("You entered an invalid geometric object!");
                break;
        }
        if(exit == 0){
            printf("Thank you using the program.");
            break;
        }
        printf("\nDo you want to run again?(N:No, Y:Yes)\n");
        scanf("%s", &runAgain);
        if (runAgain != 'y' && runAgain != 'Y') {
            if (runAgain != 'n' && runAgain != 'N') {
                printf("You entered indefinite value!");
                break;
            } else {
                printf("Thank you using the program.");
                break;
            }
        }
        fflush(stdin);
    }
    return 0;
}

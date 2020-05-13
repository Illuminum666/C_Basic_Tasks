#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point { // struct
    double x, y;
};

int findHCF(int m, int n, int o) { // for simplifying formula
    int start = (o < m && o < n && o != 0) ? o : ((m < n && m < o && m != 0) ? m : n);
    for (start; start >= 1; start--) {
        if (!(m % start) && !(n % start) && !(o % start)) {
            return start;
            break;
        }
    }
}

void printFormula(double m, double n, double o) { // a function to print a nicely formated formula
    if (m < 0) { // make first number positive
        m = abs(m);
        n *= -1;
        o *= -1;
    }

    double hcf = findHCF(m, abs(n), abs(o)); // reduce coefficients
    m /= hcf;
    n /= hcf;
    o /= hcf;
    
    printf("The formula is "); // beginning
    /* mx */
    if (m != 0) {
        if (m != 1) {
            printf("%.2fx ", m);
        } else {
            printf("x ");
        }
    }
    /* ny */
    if (n != 0) {
        if (n > 0 && n != 1) {
            printf("+ %.2fy ", n);
        } else if (n == 1) {
            printf("+ y ");
        } else if (n != -1) {
            if (m != 0) {
                printf("- %.2fy ", abs(n));
            } else {
                printf("%.2fy ", n);
            }
        } else {
            printf("- y ");
        }
    }
    /* o */
    if (o != 0) {
        if (o > 0) {
            printf("+ %.2f ", o);
        } else {
            printf("- %.2f ", abs(o));
        }
    }

    printf("= 0\n"); // ending
}

struct point findMidPt(struct point a, struct point b) { // find coordinates of the middle between two points
    struct point midpt = {(a.x + b.x)/2, (a.y + b.y)/2};
    return midpt;
}

double findDistance(struct point a, struct point b) { // find distance between two points
    double distance = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return distance;
}

void getFormula(struct point a, struct point b) { // get formula from two points
    double m = b.y - a.y;
    double n = a.x - b.x;
    double o = a.y * b.x - a.x * b.y;

    printFormula(m, n, o); // print
}

void checkLinear(struct point a, struct point b, struct point c) { // check whether three points are collinear
    double m = b.y - a.y;
    double n = a.x - b.x;
    double o = a.y * b.x - a.x * b.y;

    if ((m * c.x + n * c.y + o) == 0) {
        printf("The three points are on the same line!\n");
        printFormula(m, n, o);
    } else {
        printf("The three points are not on the same line! :(\n");
    }
}

int main()
{
    struct point test1, test2, test3; //Point is not declared yet, try to look up how it should be created.
    printf("Enter the cooridnate of Point 1: ");
    scanf("%lf %lf", &test1.x, &test1.y);
    printf("Enter the cooridnate of Point 2: ");
    scanf("%lf %lf", &test2.x, &test2.y);
    printf("Enter the cooridnate of Point 3: ");
    scanf("%lf %lf", &test3.x, &test3.y);

    struct point midpt = findMidPt(test1, test2); // func 1
    printf("Midpoint of point 1 and point 2: (%.2f, %.2f)\n", midpt.x, midpt.y);

    printf("Distance between point 1 and point 2: %.2f\n", findDistance(test1, test2)); // func 2

    getFormula(test1, test2); // func 3

    checkLinear(test1, test2, test3); // func 4
    
    system("pause");
    return 0;
}
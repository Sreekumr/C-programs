#include <stdio.h>

struct polynomial {
    int coefficient;
    int degree;
};

int i;

void read(struct polynomial poly[], int n) {
    printf("Enter the terms\n");
    for (i = n; i >= 0; i--) {
        poly[i].degree = i;
        if (i > 0) {
            printf("Enter the coefficient of x^%d: ", poly[i].degree);
            scanf("%d", &poly[i].coefficient);
        } else if (i == 0) {
            printf("Enter the constant term: ");
            scanf("%d", &poly[i].coefficient);
        }
    }
}

void disp(struct polynomial poly[], int n) {
    printf("THE POLYNOMIAL IS: ");
    for (i = n; i >= 0; i--) {
        if (i > 0) {
            printf("%dx^%d + ", poly[i].coefficient, poly[i].degree);
        } else {
            printf(" %d", poly[i].coefficient);
        }
    }
    printf("\n");
}



void subtract(struct polynomial poly1[], struct polynomial poly2[], struct polynomial result[], int n1, int n2) {
    int max_degree = n1 > n2 ? n1 : n2;

    for (i = 0; i <= max_degree; i++) {
        result[i].degree = i;
        result[i].coefficient = (i <= n1 ? poly1[i].coefficient : 0) - (i <= n2 ? poly2[i].coefficient : 0);
    }
}

int main() {
    int n1, n2;
    printf("Enter the total number of terms in the first polynomial: ");
    scanf("%d", &n1);
    struct polynomial poly1[n1 + 1]; // Increase the array size to accommodate the degree

    printf("Enter the total number of terms in the second polynomial: ");
    scanf("%d", &n2);
    struct polynomial poly2[n2 + 1]; // Increase the array size to accommodate the degree

    read(poly1, n1);
    read(poly2, n2);

    int max_degree = n1 > n2 ? n1 : n2;
    struct polynomial result[max_degree + 1];

    printf("First Polynomial:\n");
    disp(poly1, n1);

    printf("Second Polynomial:\n");
    disp(poly2, n2);


    subtract(poly1, poly2, result, n1, n2);
    printf("Difference of the Polynomials:\n");
    disp(result, max_degree);

    return 0;
}


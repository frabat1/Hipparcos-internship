/*
Given the 3 vertices of a triangle, check if an input point lies in the triangle or not.

Example: let A=(0,0), B=(0,6) and C=(3,5). Is the point D=(2,1) inside the triangle ABC?

The strategy adopted is to write two functions:
- one that receives the 3 + 1 point and decides wether or not the last one is inside the triangle
- the other that asks for the inputs from the users and tells the answer.

Note that for a given point P, we will consider P[0] = x_P and P[1] = y_P
*/

#include <stdio.h>

// in this function I will check that D is on the right semiplane identified by the sides of the triangle,
// for each of the three sides: AB, BC and AC.
void triangle_check(float A[2], float B[2], float C[2], float D[2]) {

    if (C[1] > (B[1] - A[1])/(B[0] - A[0]) * C[0] + B[1] - (B[1] - A[1])/(B[0] - A[0]) * B[0]) { //if C is over AB
        if  (D[1] < (B[1] - A[1])/(B[0] - A[0]) * D[0] + B[1] - (B[1] - A[1])/(B[0] - A[0]) * B[0]) { // if D is below AB
            printf("The point is OUTSIDE the triangle ABC.");
        } else { // if D is over/on AB
            if (A[1] > (B[1] - C[1])/(B[0] - C[0]) * A[0] + B[1] - (B[1] - C[1])/(B[0] - C[0]) * B[0]) { //if A is over BC
                if  (D[1] < (B[1] - C[1])/(B[0] - C[0]) * D[0] + B[1] - (B[1] - C[1])/(B[0] - C[0]) * B[0]) { // if D is below BC
                    printf("The point is OUTSIDE the triangle ABC.");
                } else { //if D is over/on BC
                    if (B[1] > (A[1] - C[1])/(A[0] - C[0]) * B[0] + A[1] - (A[1] - C[1])/(A[0] - C[0]) * A[0]) { //if B is over AC
                        if  (D[1] < (A[1] - C[1])/(A[0] - C[0]) * D[0] + A[1] - (A[1] - C[1])/(A[0] - C[0]) * A[0]) { // if D is below AC
                        printf("The point is OUTSIDE the triangle ABC.");
                        } else { //if D is over/on AC
                            printf("Point D is INSIDE the triangle ABC.");
                        }
                    } else { // if B is below AC
                        if  (D[1] > (A[1] - C[1])/(A[0] - C[0]) * D[0] + A[1] - (A[1] - C[1])/(A[0] - C[0]) * A[0]) { // if D is over AC
                        printf("The point is OUTSIDE the triangle ABC.");
                        } else { //if D is below/on AC
                            printf("Point D is INSIDE the triangle ABC.");
                        }
                    }
                }
            } else { // if A is below BC
                if  (D[1] > (B[1] - C[1])/(B[0] - C[0]) * D[0] + B[1] - (B[1] - C[1])/(B[0] - C[0]) * B[0]) { // if D is over BC
                printf("The point is OUTSIDE the triangle ABC.");
                } else { //if D is below/on BC
                    printf("Point D is INSIDE the triangle ABC.");
                }
            }
        }
    } else { //if C is below AB
        if  (D[1] > (A[1] - B[1])/(A[0] - B[0]) * D[0] + A[1] - (A[1] - B[1])/(A[0] - B[0]) * A[0]) { // if D is over AB
            printf("The point is OUTSIDE the triangle ABC.");
        } else { //if D is below/on AB
            printf("Point D is INSIDE the triangle ABC.");
        }
    }
}
// is there a better way of doing this process? maybe a for loop to avoid all this horrendous if/else statement


// main function to print the results
int main() {
    float A[2], B[2], C[2], D[2];

    printf("Select the 3 points that constitute the triangle.\n");
    
    // point A
    printf("Insert the x value of A: ");
    scanf("%f", &A[0]); 
    printf("Insert the y value of A: ");
    scanf("%f", &A[1]); 

    // point B
    printf("Insert the x value of B: ");
    scanf("%f", &B[0]); 
    printf("Insert the y value of B: ");
    scanf("%f", &B[1]); 
    
    // point C
    printf("Insert the x value of C: ");
    scanf("%f", &C[0]); 
    printf("Insert the y value of C: ");
    scanf("%f", &C[1]); 
    
    // point D
    printf("Select the point D to know if it is inside or outside.\n");
    printf("Insert the x value of D: ");
    scanf("%f", &D[0]); 
    printf("Insert the y value of D: ");
    scanf("%f", &D[1]); 
    
    triangle_check(A, B, C, D);
    return 0;
}

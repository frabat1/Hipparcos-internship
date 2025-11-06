/* Here it is a programm (more version of it to investigate how to optimeze things in C)
that given in input from the user the int i, it has to find the correct i-th number of the
Fibonacci sequence.

ex. F(0) = 0, F(1) = 1, F(2) = 1, F(3) = 2, ... F(7) = 13, ...ecc
*/


#include <stdio.h>

//1st) VERSION
/*
This is almost the optimal one since it has a time complexity of O(n) 
*/

/*
int main() {
    int i;
    printf("Which number of the Fibonacci sequence do you want?");
    scanf("%d", &i);

    if (i == 1) {
        printf("The first number of the Fibonacci sequence is 0");
    } else if (i == 2) {
        printf("The second number of the Fibonacci sequence is 1");
    } else {
        int a, b = 0, c = 1;
        for (int n = 3; n <= i; n++) {
            a = b + c;
            b = c;
            c = a;
        }
        printf("The %d-th number of the Fibonacci sequence is %d", i, a);
    }
    return 0;
}
*/

// Can we improve this function? A part from comprhending also the non-valid character
// that could be inserted, I want to make it more powerful, to let me have also very large
// Fibonacci numbers.


// 2nd) VERSION
/*
With matrix exponentiation, we can calculate Fibonacci numbers much faster
by working with matrices. There's a special matrix (transformation matrix)
that represents how Fibonacci numbers work. It looks like this:

                    |1 1|
                    |1 0|

To find the Nth Fibonacci number we need to multiple transformation 
matrix (n-1) times, the matrix equation for the Fibonacci sequence looks like:

                    |1 1|^(n-1)   |F(n)   F(n-1)|
                    |1 0|       = |F(n-1) F(n-2)|

Here the time complexity drop to O(log(n)), which is a slight but sometimes valuable
improvement.
*/ 
// 3 functions are necessary (+ the main() function to call all of them)

// Function for computing matrix multiplication between two 2x2 matrices A and B
void matrix_mult(int A[2][2], int B[2][2], int out[2][2]) {
    out[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    out[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    out[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    out[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}

// Function for computing the n-th exponent of a 2x2 matrix, using recursion so considering 
// the base case (n = 1)
void matrix_power(int M[2][2], int n, int out[2][2]) {
    if (n < 0) {
        printf("Invalid exponent. Please insert only nonnegative values.");  
    } else if (n == 0) { //identity matrix
        out[0][0] = 1;
        out[0][1] = 0;
        out[1][0] = 0;
        out[1][1] = 1; 
    } else if (n == 1) {
        // insert for loop for having the equality M = out
        for (int row = 0; row <= 1; row ++) {
            for (int column = 0; column <= 1; column ++) {
                out[row][column] = M[row][column];
            }
        }
    } else {
        int temp[2][2]; //temporary variable used to store the recursive result
        matrix_power(M, n-1, temp);
        matrix_mult(temp, M, out);
    }
}
        
// function to print the bottom right element a matrix
int print_Fib(int A[2][2]) {
    int n = A[1][1];
    return n;
}

// main function to call all the intermediate functions and display the reusult
int main() {
    int n;
    printf("Which number of the Fibonacci sequence do you want?\n");
    scanf("%d", &n);
    int M[2][2] = {{1, 1}, {1, 0}};
    int M_n[2][2];
    matrix_power(M, n, M_n);
    int F_n = print_Fib(M_n); //the n-th Fibonacci number is 
    printf("The %d-th number of the Fibonacci sequence is %d", n, F_n);
    return 0;
} 


/*
Right now I'm satisfied with the result obtained but to be honest the last algorithm has still time complexity O(n).
To improve it to be O(log(n)) we should implement a "Divide et Conquer" tactic called EXPONENTIATION BY SQUARING:
- if n is even: M_n = (M_{n/2})^2;
- if n is odd: M_n = M * M_{n-1}
 */

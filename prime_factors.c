/*
Given a number n, we want to find an efficient algorithm which finds all its prime factors.

Example:
- input = 18
- output = 2, 3.
*/

#include <stdlib.h>
#include <stdio.h>

// The first function checks for divisors of n
void factorization(int n, int *factors) {
    int index = 0; //initialization of the index

    for (int i = 2; i <= n; i++) { // check every number from 2 until the half of n if it's a divisor.
        while (n % i == 0) { // if i is a divisor, store it in the vector 
            factors[index++] = i;
            n = n/i; // updating n by dividing it, let us only consider the prime numbers. 
        }
    } 
    factors[index] = 0;
}

int main() {
    int n;
    
    printf("Which number do you want to factorize? ");
    scanf("%d", &n);
    
    int *primes = malloc(n/2 * sizeof(int));
    factorization(n, primes);

    printf("The prime factors of %d are: \n", n);
    for (int j = 0; j < n/2; j++) { //select the nonzero values from the primes vector which could have some of its values to be 0
        if (primes[j] != 0) {
            printf("%d \n", primes[j]);
        }
    }
    free(primes);
    return 0;
}

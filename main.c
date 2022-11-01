// Julia Frances
// main.c
// September 23, 2022
// C implementation of the Collatz sequence in order to determine how many steps will be taken before reaching a power of 2

#include <stdio.h>

int numSteps(int);
int powOfTwo(int);

int main() {
    int num;
    int steps;
    // for loop through 1-100 to print table
    for (num = 1; num <= 100; num++){ 
        steps = numSteps(num);
        printf("%d\t%d\n", num, steps); // print number passed through function and number of steps determined by function 
    }
    return 0;
}

// function to determine number of steps necessary to reach a power of two
int numSteps(int n){
    int count = 0;
    int pow;
    // while loop until number reaches 1 (end of larger sequence)
    while (n != 1){
        pow = powOfTwo(n); // determine if number is a power of two using function
        if (pow == 1){
            break; // if it is a power of two, break loop
        } else if (n % 2 == 0){ // if number is even (remainder is 0), divide by 2, increase count by 1
            n = n / 2;
            count = count + 1; 
        } else { // otherwise it is odd, multiply by 3 and add 1, increase count by 1
            n = (n * 3) + 1;
            count = count + 1;
        }
    }
    return count;
}

// function to determine whether a number is a power of 2 based on binary representations
// this method works because powers of 2 only have one 1 bit in their binary representations 
// subtracting 1 will result in a binary number with every value flipped (0->1, 1->0) 
// &ing them together will always result in 0 since 0&1 = 0. 
int powOfTwo(int n){
    if((n != 0) && ((n & (n - 1)) == 0)){ // check that n isnt 0, method explained above
        return 1;
    } else {
        return 0;
    }
}

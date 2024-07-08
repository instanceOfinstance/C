#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

// Function to reverse an integer
int reverse(int x) {
    int reversed = 0;
    
    while (x != 0) {
        int digit = x % 10;
        x /= 10;
        
        // Check for overflow before updating reversed
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) return 0;
        
        reversed = reversed * 10 + digit;
    }
    
    return reversed;
}

// Main function to test the reverse function
int main() {
    int num1 = 123;
    int num2 = -123;
    int num3 = 120;
    
    printf("Reverse of %d is: %d\n", num1, reverse(num1));
    printf("Reverse of %d is: %d\n", num2, reverse(num2));
    printf("Reverse of %d is: %d\n", num3, reverse(num3));
    
    return 0;
}


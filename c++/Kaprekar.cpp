// C++ program to check if a number is a Kaprekar number for a specific base.

#include <iostream>
#include <cmath>
using namespace std;

bool isKaprekar(int number, int base) {
    if (number < 0 || base <= 1) {
        return false; // Invalid input case
    }

    long long squared = static_cast<long long>(number) * number;
    long long divisor = 1;

    // Find the appropriate divisor for splitting the squared number
    while (squared / divisor >= base) {
        divisor *= base;
    }

    // Try splitting the square into two parts and check the Kaprekar condition
    while (divisor > 0) {
        long long left = squared / divisor;
        long long right = squared % divisor;

        // Check if the sum of left and right equals the original number
        if (left + right == number && right > 0) {
            return true;
        }
        divisor /= base;
    }
    return false;
}

int main() {
    int number, base;

    // Take user input
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;

    // Check and display if the number is a Kaprekar number
    if (isKaprekar(number, base)) {
        cout << number << " is a Kaprekar number in base " << base << endl;
    } else {
        cout << number << " is not a Kaprekar number in base " << base << endl;
    }

    return 0;
}

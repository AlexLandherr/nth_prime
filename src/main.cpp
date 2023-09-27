#include "include/functions.h"
#include <iostream>
#include <stdexcept>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.
What is the 10,001st prime number?
*/

int main() {
    try {
        std::cout << "The 10,001st prime number is: " << func::nth_prime(10001) << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }

    return 0;
}
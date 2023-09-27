#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cstdint>

namespace func {
    bool is_prime(int64_t n) {
        //Checks if a single signed 64-bit integer is a prime number.
        if (n > std::numeric_limits<int64_t>::max() || n < std::numeric_limits<int64_t>::min()) {
            throw std::invalid_argument("Argument 'n' is out of range for 'int64_t' type.");
        }
        if (n <= 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n > 2 && n % 2 == 0) {
            return false;
        }

        int64_t max_divisor = std::ceil(std::sqrt((long double) n));
        for (int64_t d = 3; d < max_divisor + 1; d+=2) {
            if (n % d == 0) {
                return false;
            }
        }

        return true;
    }

    int64_t nth_prime(int64_t n) {
        int prime_count = 1;
        int64_t i = 2;
        while (prime_count < n) {
            i++;
            if (is_prime(i)) {
                prime_count++;
            }
        }
        return i;
    }
}
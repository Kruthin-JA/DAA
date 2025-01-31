#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Handle edge cases
        
        int left = 0, right = x, result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2; // Use long long to avoid overflow
            long long square = mid * mid;
            
            if (square == x) {
                return mid; // Perfect square
            } else if (square < x) {
                result = mid; // Update result
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        
        return result; // Return the largest integer whose square <= x
    }
};


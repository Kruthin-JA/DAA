#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // Find the position of the first occurrence of needle in haystack
        size_t pos = haystack.find(needle);
        
        // If found, return the position; otherwise, return -1
        return (pos != string::npos) ? pos : -1;
    }
};

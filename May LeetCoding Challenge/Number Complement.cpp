class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = -1;
        while ((mask & num) > 0) mask <<= 1;
        return ~mask ^ num;
        // or
        // return ~mask & ~num;
        
    }
};


/*
    Solution 2
*/

class Solution {
public:
    int findComplement(int num) {
        return num ^ (INT_MAX >> (31 - (int(log2(num)) + 1)));
    }
};
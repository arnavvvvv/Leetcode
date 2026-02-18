class Solution {
public:
    bool hasAlternatingBits(int n) {

        //Solution 1: using for loop and getting binary string
        // int check = n%2;
        // n = n/2;
        // while(n) {
        //     if(n%2 == check)
        //         return false;
        //     else
        //         check = n%2;
        //     n = n/2;
        // }
        // return true;

        //Solution 2: Usin xor bit manipulation
        unsigned int x = n ^ (n >> 1);
        return (x & (x+1)) == 0;
    }
};
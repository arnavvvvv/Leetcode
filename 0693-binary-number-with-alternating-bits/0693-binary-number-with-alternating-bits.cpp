class Solution {
public:
    bool hasAlternatingBits(int n) {
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
        unsigned int x = n ^ (n >> 1);
        cout<<(n >> 1)<<endl;
        cout<<x;
        return (x & (x+1)) == 0;
    }
};
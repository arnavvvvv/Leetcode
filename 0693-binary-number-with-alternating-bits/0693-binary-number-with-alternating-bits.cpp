class Solution {
public:
    bool hasAlternatingBits(int n) {
        int check = n%2;
        n = n/2;
        while(n) {
            if(n%2 == check)
                return false;
            else
                check = n%2;
            n = n/2;
        }
        return true;
    }
};
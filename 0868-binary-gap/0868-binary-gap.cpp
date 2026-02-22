class Solution {
public:
    int binaryGap(int n) {
        int last_position = -1;
        int count = 0;
        int i = 0;
        while(n) {
            if(n%2 && last_position == -1)
                last_position = i;
            else if(n%2) {
                count = max(count, i - last_position);
                last_position = i;
            }
            ++i;
            n = n/2;
        }
        return count;
    }

};
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(int i = 0; i < patterns.size(); ++i) {
            for(int j = 0; j < word.size(); ++j) {
                if(patterns[i][0] == word[j]) {
                    int a = 0;
                    int b = j;

                    while(a < patterns[i].size() && b < word.size() && patterns[i][a] == word[b]) {
                        ++a;
                        ++b;
                    }
                    if(a == patterns[i].size()) {
                        ++count;
                        break;
                    }
                        
                }
            }
        }
        return count;
    }
};
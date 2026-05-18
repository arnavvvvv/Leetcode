class Solution {
private:
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        unordered_set<string> visited;
        //unordered_set<string> s;
        queue<string> q;
        int distance = 1;
        for(string word: wordList) {
            for(int i = 0; i < word.size(); ++i) {
                string t = word;
                t[i] = '*';
                m[t].push_back(word);
            }
        }
        q.push(beginWord);
        while(!q.empty()) {
            
            int count = q.size();
            for(int i = 0; i < count; ++i) {
                string s = q.front(); q.pop();
                visited.insert(s);
                if(s == endWord)
                    return distance;
                for(int j = 0; j < s.size(); ++j) {
                    char c = s[j];
                    s[j] = '*';
                    for(string x: m[s]) {
                        if(visited.count(x) == 0)
                            q.push(x);
                    }
                    s[j] = c;
                }
            }
            ++distance;
        }
        return 0;
        
    }
};

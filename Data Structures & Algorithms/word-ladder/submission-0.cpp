class Solution {
   public:
    int isValidChoice(string s1, string s2) {
        int diff = 0;
        for(int i = 0; i<s1.size() && diff <= 1; i++)
            if(s1[i]!=s2[i]) diff++;

        return diff==1;

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Simple dfs should solve this
        queue<pair<int, string>> q;
        unordered_set<string> visited;

        visited.insert(beginWord);
        q.push({1, beginWord});


        while(!q.empty()) {
            auto [currOp, currWord] = q.front(); q.pop();

            if(currWord==endWord) return currOp;

            for(string nei : wordList) {
                if(visited.count(nei)) continue;
                if(isValidChoice(currWord, nei)) {
                    visited.insert(nei);
                    q.push({currOp+1, nei});
                }
            }
        }
        return 0;
    }
};

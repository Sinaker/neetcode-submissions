class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> freq;
        freq.fill(0);
        for(char c : s1)
            freq[c-'a']++;

        for(int i = 0; i<s1.size()-1; i++)
            freq[s2[i]-'a']--;
        
        for(int i = s1.size(); i<s2.size(); i++) {
            freq[s2[i]-'a']--;

            if(accumulate(freq.begin(), freq.end(), 0) ==0) return true;

            freq[s2[i - s1.size()] - 'a']++;
        }
        return false;
    }
};

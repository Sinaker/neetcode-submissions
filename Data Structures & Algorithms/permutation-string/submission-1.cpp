
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int freq[26] = {0};
        for(char c : s1)
            freq[c-'a']++;

        for(int i = 0; i < (int)s1.size() - 1; i++)
            freq[s2[i]-'a']--;
        
        for(int i = s1.size() - 1; i < s2.size(); i++) {
            freq[s2[i]-'a']--;

            bool zero = true;
            for(int i = 0;i<26;i++)
                if(freq[i]!=0) zero=false;
            
            if(zero) return true;

            freq[s2[i - s1.size() + 1] - 'a']++;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int a : asteroids) {
            while(!st.empty() && st.back() > 0 && a < 0 && abs(a) > abs(st.back()))
                st.pop_back();

            if(!st.empty() && st.back() > 0 && a < 0 && abs(a) == abs(st.back())) {
                st.pop_back();
                continue;
            }
            else if(!st.empty() && st.back() > 0 && a < 0 && abs(a) < abs(st.back()))
                continue;

            st.push_back(a);
        }

        return st;
    }
};
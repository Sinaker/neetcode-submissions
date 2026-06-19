class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // base preq will have no outDegree (terminal node) [course -> preq]

        // this is exactly like safeNodes
        vector<int> ans;

        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> revGraph;
        queue<int> q;

        for(vector preq : prerequisites) {
            revGraph[preq[1]].push_back(preq[0]);
            inDegree[preq[0]]++; // Acc to revGraph
        }

        for(int i = 0; i<numCourses; i++)
            if(inDegree[i]==0) q.push(i);
        
        while(!q.empty()) {
            int currCourse = q.front(); q.pop(); // course with 0 preq
            ans.push_back(currCourse);

            for(int par : revGraph[currCourse]) {
                inDegree[par]--;
                if(inDegree[par]==0) q.push(par);
            }
        }

        if(ans.size()!=numCourses) return {};
        return ans;
    }
};

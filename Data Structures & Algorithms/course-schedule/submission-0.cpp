class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> visited(numCourses,0);

        for(auto preq: prerequisites) 
            adjList[preq[0]].push_back(preq[1]);

        for(int i = 0; i<numCourses; i++) 
            if(dfs(i, adjList, visited)) return false;
        
        
        return true;
        
    }
    bool dfs(int currNode, unordered_map<int, vector<int>>& adjList, vector<int>& visited) {
        // visited is an array containing 3 states, 0, unprocess, 1 processing, 2 done

        if(visited[currNode]==1) return true;
        if(visited[currNode]==2) return false; // already processed

        visited[currNode] = 1;

        for(int preq : adjList[currNode]) 
            if(dfs(preq, adjList, visited)) return true;
        
        visited[currNode] = 2; // processed
        return false;
    }
};

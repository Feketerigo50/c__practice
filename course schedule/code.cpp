class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> stk;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> outDegree(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]] += 1;
            outDegree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0) stk.push(i);
        }
        if(stk.empty()) return false;

        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            visited[cur] = true;
            for(int i = 0; i < outDegree[cur].size(); i++){
                if(visited[outDegree[cur][i]]) return false; // circle
                
                inDegree[outDegree[cur][i]] -= 1;
                if(inDegree[outDegree[cur][i]] == 0){
                    stk.push(outDegree[cur][i]);
                }
            }
        }

        if(count(visited.begin(), visited.end(), false) > 0) return false;

        return true;
    }
};
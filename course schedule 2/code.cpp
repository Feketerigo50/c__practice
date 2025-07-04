class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> outdegree(numCourses, vector<int>());
        
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]] += 1;
            outdegree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> BFS;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                BFS.push(i);
            }
        }
        
        int visited = 0;
        while(!BFS.empty()){
            int cur = BFS.front();
            BFS.pop();
            visited++;
            result.push_back(cur);
            for(int i = 0; i < outdegree[cur].size(); i++){
                if(--indegree[outdegree[cur][i]] == 0){
                    BFS.push(outdegree[cur][i]);
                }
            }
        }

        if(visited != numCourses) result.clear();

        return result;
    }
};
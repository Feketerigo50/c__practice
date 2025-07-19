class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> result;
        vector<int> degree(n, 0);
        vector<vector<int>> neighbors(n, vector<int>());

        for(int i = 0; i < edges.size(); i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }

        
        queue<int> que;
        int remains = n;

        while(remains > 2){
            int cur_round = 0;
            for(int i = 0; i < n; i++){
                if(degree[i] == 1){
                    cur_round++;
                    que.push(i);
                }
            }

            while(!que.empty()){
                int cur_node = que.front();
                que.pop();
                for(int j = 0; j < neighbors[cur_node].size(); j++){
                    degree[neighbors[cur_node][j]]--;
                    degree[cur_node] -= 2;
                }
            }
            remains -= cur_round;
        }

        for(int i = 0; i < degree.size(); i++){
            if(degree[i] >= 0){
                result.push_back(i);
            }
        }

        return result;
    }
};
class Solution {
private:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;

public:
    double dfs(double value, string start, string end){
        if(start == end) return value;
        visited.insert(start);

        double result = -1;
        for(auto mid = graph[start].begin(); mid != graph[start].end(); mid++){
            if(visited.count(mid->first) == 0){
                result = dfs(value*mid->second, mid->first, end);
            }
            if(result != -1) return result;
        }

        return result;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); i++){
            string start = equations[i][0];
            string end = equations[i][1];
            double value = values[i];

            graph[start][end] = value;
            graph[end][start] = 1 / value;
        }

        vector<double> result;
        for(int i = 0; i < queries.size(); i++){
            string start = queries[i][0];
            string end = queries[i][1];

            if(graph.count(start) == 0 || graph.count(end) == 0){
                result.push_back(-1.0);
            }else if(start == end){
                result.push_back(1.0);
            }else{
                visited.clear();
                result.push_back(dfs(1.0, start, end));
            }
        }

        return result;
    }
};
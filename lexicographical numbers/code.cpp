class Solution {
private:
    void dfs(int cur, int n, vector<int>& res){
        if(cur > n) return;
        res.push_back(cur);
        for(int i = 0; i < 10; i++){
            if(cur*10 + i > n) return; 
            dfs(cur*10 + i, n, res);
        }
        return;
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i < 10; i++){
            dfs(i, n, res);
        }
        return res;
    }
};
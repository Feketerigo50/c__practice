/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> ele_level;
            int cur_level = que.size();

            for(int i = 0; i < cur_level; i++){
                Node* cur_node = que.front();
                que.pop();
                
                ele_level.push_back(cur_node->val);
                for(int j = 0; j < cur_node->children.size(); j++){
                    que.push(cur_node->children[j]);
                }
            }
            result.push_back(ele_level);
        }

        return result;
    }
};
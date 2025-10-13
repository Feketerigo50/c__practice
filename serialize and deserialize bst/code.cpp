/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string preorder = "";
        
        TreeNode* dummy = nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            dummy = stk.top();
            stk.pop();
            
            preorder += to_string(dummy->val) + " ";
            if(dummy->right) stk.push(dummy->right);
            if(dummy->left) stk.push(dummy->left);
        }

        return preorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        
        stringstream ss(data);
        vector<int> vals;
        int val = 0;
        while(ss >> val) vals.push_back(val);
        int idx = 0;
        return makeTree(vals, idx, INT_MIN, INT_MAX);
    }

    TreeNode* makeTree(vector<int> &preorder, int &idx, int lower, int upper){
        if(idx >= preorder.size()) return nullptr;
        int val = preorder[idx];
        if(val < lower || val > upper) return nullptr;
        idx++;
        TreeNode *root = new TreeNode(val);
        root->left = makeTree(preorder, idx, lower, val);
        root->right = makeTree(preorder, idx, val, upper);

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
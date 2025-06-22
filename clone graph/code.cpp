/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        queue<Node*> origin_que;
        unordered_map<Node*, Node*> made_nodes;

        Node* first_node = new Node(node->val);
        made_nodes[node] = first_node;
        origin_que.push(node);

        while(!origin_que.empty()){
            Node *cur_node = origin_que.front();
            origin_que.pop();

            for(auto &origin_neighbor : cur_node->neighbors){
                if(!made_nodes.count(origin_neighbor)){
                    made_nodes[origin_neighbor] = new Node(origin_neighbor->val);
                    origin_que.push(origin_neighbor);
                }
                made_nodes[cur_node]->neighbors.push_back(made_nodes[origin_neighbor]);
            }
        }

        return first_node;
    }
};
class Solution {
public:
    struct Node{
        string permute;
        bool visited;
        vector<Node*> out;

        Node(string str){
            permute = str;
            visited = false;
        }
    };

    bool ifNextMut(string a, string b){
        int count = 0;
        for(int idx = 0; idx < 8; idx++){
            if(a[idx] != b[idx]) count++;
        }
        return count == 1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(find(bank.begin(), bank.end(), endGene) == bank.end()) return -1;

        bank.push_back(startGene);
        set<string> tmp(bank.begin(), bank.end());
        vector<string> vertex(tmp.begin(), tmp.end());

        map<string, Node*> graph;
        for(string st : bank){
            graph[st] = new Node(st);
        }

        int n = vertex.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(ifNextMut(vertex[i], vertex[j])){
                    string st = vertex[i];
                    string des = vertex[j];
                    graph[st]->out.push_back(graph[des]);
                    graph[des]->out.push_back(graph[st]);
                }
            }
        }

        queue<Node*> que;
        que.push(graph[startGene]);
        graph[startGene]->visited = true;
        int depth = 0;
        while(!que.empty()){
            depth++;

            int level = que.size();
            for(int i = 0; i < level; i++){
                Node* cur_node = que.front();
                que.pop();
                
                for(Node* next : cur_node->out){
                    if(next->visited) continue;
                    if(next->permute == endGene) return depth;
                    next->visited = true;
                    que.push(next);
                }
            }
        }
        
        
        return -1;
    }
};
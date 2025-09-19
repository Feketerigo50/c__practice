class AllOne {
private:
    struct Node{
        int count;
        Node* prev;
        Node* next;
        unordered_set<string> keys;    
        Node(int c){
            count = c;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<string, Node*> store;
    Node* head;
    Node* tail;

public:
    AllOne() {
        head = nullptr;
        tail = nullptr;
    }
    
    void inc(string key) {
        if(!store.count(key)){
            if(!head || head->count != 1){
                Node* new_node = new Node(1);

                if(head){
                    new_node->next = head;
                    head->prev = new_node;
                }else{
                    tail = new_node;
                }
                head = new_node;
            }
            head->keys.insert(key);
            store[key] = head;
        }else{
            Node* cur_node = store[key];
            Node* next_node = cur_node->next;
            if(!next_node || cur_node->count+1 != next_node->count){
                Node* new_node = new Node(cur_node->count+1);

                if(next_node){
                    new_node->next = next_node;
                    next_node->prev = new_node;
                }else{
                    tail = new_node;
                }
                cur_node->next = new_node;
                new_node->prev = cur_node;
                next_node = new_node;
            }

            cur_node->keys.erase(key);
            if(cur_node->keys.empty()){
                if(cur_node->prev){
                    cur_node->prev->next = next_node;
                    next_node->prev = cur_node->prev;
                }else{
                    head = next_node;
                    next_node->prev = nullptr;
                }
                delete cur_node;
            }
            store[key] = next_node;
            next_node->keys.insert(key);
        }

        return;
    }
    
    void dec(string key) {
        Node* cur_node = store[key];
        Node* prev_node = cur_node->prev;
        
        if(!prev_node || prev_node->count != cur_node->count - 1){
            Node* new_node = new Node(cur_node->count - 1);
            
            if(prev_node){
                prev_node->next = new_node;
                new_node->prev = prev_node;
            }else{
                head = new_node;
            }
            new_node->next = cur_node;
            cur_node->prev = new_node;

            prev_node = new_node;
        }

        cur_node->keys.erase(key);
        if(cur_node->keys.empty()){
            Node* next_node = cur_node->next;

            if(next_node){
                prev_node->next = next_node;
                next_node->prev = prev_node;
            }else{
                tail = prev_node;
                prev_node->next = nullptr;
            }
            delete cur_node;
        }

        if(prev_node->count == 0){
            Node* next_node = prev_node->next;
            if(next_node){
                head = next_node;
                next_node->prev = nullptr;
            }else{
                head = nullptr;
                tail = nullptr;
            }
            delete prev_node;
            store.erase(key);
        }else{
            prev_node->keys.insert(key);
            store[key] = prev_node;
        }

        return;
    }
    
    string getMaxKey() {
        return tail ? *(tail->keys.begin()) : "";
    }
    
    string getMinKey() {
        return head ? *(head->keys.begin()) : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
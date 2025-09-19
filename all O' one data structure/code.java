class AllOne {
    private class Node{
        int count;
        Node prev;
        Node next;
        Set<String> keys;

        Node(int c){
            count = c;
            keys = new HashSet<>();
        }
    };
    Node head;
    Node tail;
    Map<String, Node> store;

    public AllOne() {
        store = new HashMap<>();
    }
    
    public void inc(String key) {
        if(!store.containsKey(key)){
            if((head == null) || (head.count != 1)){
                Node new_node = new Node(1);
                
                if(head != null){
                    new_node.next = head;
                    head.prev = new_node;
                    head = new_node;
                }else{
                    head = new_node;
                    tail = new_node;
                }
            }
            head.keys.add(key);
            store.put(key, head);
        }else{
            Node cur_node = store.get(key);
            Node next_node = cur_node.next;
            if((next_node == null) || (cur_node.count + 1 != next_node.count)){
                Node new_node = new Node(cur_node.count + 1);
                
                if(next_node != null){
                    new_node.next = next_node;
                    next_node.prev = new_node;
                }else{
                    tail = new_node;
                }
                cur_node.next = new_node;
                new_node.prev = cur_node;
                
                next_node = new_node;
            }

            cur_node.keys.remove(key);
            if(cur_node.keys.isEmpty()){
                Node prev_node = cur_node.prev;

                if(prev_node != null){
                    prev_node.next = next_node;
                    next_node.prev = prev_node;
                }else{
                    head = next_node;
                    next_node.prev = null;
                }
                cur_node = null;
            }

            next_node.keys.add(key);
            store.put(key, next_node);
        }

        return;
    }
    
    public void dec(String key) {
        Node cur_node = store.get(key);
        Node prev_node = cur_node.prev;
        if((prev_node == null) || (prev_node.count != cur_node.count - 1)){
            Node new_node = new Node(cur_node.count-1);

            if(prev_node != null){
                prev_node.next = new_node;
                new_node.prev = prev_node;
            }else{
                head = new_node;
            }
            new_node.next = cur_node;
            cur_node.prev = new_node;
            prev_node = new_node;
        }

        cur_node.keys.remove(key);
        if(cur_node.keys.isEmpty()){
            Node next_node = cur_node.next;
            if(next_node != null){
                prev_node.next = next_node;
                next_node.prev = prev_node;
            }else{
                tail = prev_node;
                prev_node.next = null;
            }
            cur_node = null;
        }

        if(prev_node.count == 0){
            Node next_node = prev_node.next;
            if(next_node != null){
                head = next_node;
                next_node.prev = null;
            }else{
                head = null;
                tail = null;
            }
            prev_node = null;
            store.remove(key);
        }else{
            prev_node.keys.add(key);
            store.put(key, prev_node);
        }

        return;
    }
    
    public String getMaxKey() {
        return tail == null ? "" : tail.keys.iterator().next();
    }
    
    public String getMinKey() {
        return head == null ? "" : head.keys.iterator().next();
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
class Solution {
    private class Node{
        String permute;
        List<Node> out;
        boolean visited;
        Node(String input){
            permute = input;
            out = new ArrayList<>();
            visited = false; 
        }
    }

    private boolean isNextMut(String a, String b){
        int count = 0;
        for(int i = 0; i < 8; i++){
            if(a.charAt(i) != b.charAt(i)) count++;
        }

        return count == 1;
    }

    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> tmp = new HashSet<>();
        tmp.add(startGene);
        for(String s : bank){
            tmp.add(s);
        }
        
        if(!tmp.contains(endGene)) return -1;
        
        List<String> vertex = new ArrayList<>(tmp);
        Map<String, Node> graph = new HashMap<>();

        for(String s : vertex){
            graph.put(s, new Node(s));
        }

        for(int i = 0; i < vertex.size(); i++){
            for(int j = i+1; j < vertex.size(); j++){
                if(isNextMut(vertex.get(i), vertex.get(j))){
                    graph.get(vertex.get(i)).out.add(graph.get(vertex.get(j)));
                    graph.get(vertex.get(j)).out.add(graph.get(vertex.get(i)));
                }
            }
        }
        
        Queue<Node> que = new LinkedList<>();
        que.offer(graph.get(startGene));
        graph.get(startGene).visited = true;
        int depth = 0;
        while(!que.isEmpty()){
            int level = que.size();
            depth++;

            for(int i = 0; i < level; i++){
                Node cur_node = que.poll();
                for(Node next : cur_node.out){
                    if(next.permute.equals(endGene)) return depth;
                    if(!next.visited){
                        next.visited = true;
                        que.offer(next);
                    }
                }
            }
        }

        return -1;
    }
}
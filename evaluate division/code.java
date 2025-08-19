class Solution {
    private Map<String, Map<String, Double>> graph;
    private Set<String> visited;

    private double dfs(double value, String start, String end){
        if(start.equals(end)) return value;
        visited.add(start);

        double result = -1;
        Set<Map.Entry<String, Double>> entries = graph.get(start).entrySet();
        for(var e : entries){
            if(!visited.contains(e.getKey())){
                result = dfs(value*e.getValue(), e.getKey(), end);
            }
            if(result != -1) return result;
        }

        return result;
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        graph = new HashMap<>();
        visited = new HashSet<>();

        for(int i = 0; i < equations.size(); i++){
            String start = equations.get(i).get(0);
            String end = equations.get(i).get(1);
            double value = values[i];

            graph.putIfAbsent(start, new HashMap<>());
            graph.putIfAbsent(end, new HashMap<>());
            graph.get(start).put(end, value);
            graph.get(end).put(start, 1.0/value);
        }

        int n = queries.size();
        double[] result = new double[n];

        for(int i = 0; i < n; i++){
            String start = queries.get(i).get(0);
            String end = queries.get(i).get(1);
            
            if(!graph.containsKey(start) || !graph.containsKey(end)){
                result[i] = -1.0;
            }else if(start.equals(end)){
                result[i] = 1.0;
            }else{
                visited.clear();
                result[i] = dfs(1.0, start, end);
            }
        }

        return result;
    }
}
class Solution {
public:
    map<string, multiset<string>> graph;
    vector<string> itinerary;

    void DFS(string vertex){
        auto& siblings = graph[vertex];
        
        while(!siblings.empty()){
            auto next = siblings.begin();
            string next_dest = *next;
            siblings.erase(next);
            DFS(next_dest);
        }
        itinerary.push_back(vertex);
        
        
        return;
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++){
            graph[tickets[i][0]].insert(tickets[i][1]);
        }

        DFS("JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};
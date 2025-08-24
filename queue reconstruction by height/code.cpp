class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        map<int, set<int>> classbyfront;
        
        for(int i = 0; i < people.size(); i++){
            classbyfront[people[i][1]].insert(people[i][0]);
        }

        vector<vector<int>> result(people.size(), vector<int>());
        
        int done_sort = 0;
        for(auto entry : classbyfront){
            int front = entry.first;
            int last_pos = -1;
            for(int height : entry.second){
                int taller_count = 0;
                int insert_idx = done_sort;
                for(int i = 0; i < done_sort; i++){
                    if(result[i][0] >= height) taller_count++;
                    if(taller_count == front && i >= last_pos){
                        insert_idx = i+1;
                        break;
                    }
                }
                if(insert_idx != done_sort){
                    for(int i = done_sort; i > insert_idx; i--){
                        result[i] = {result[i-1][0], result[i-1][1]};
                    }
                    result[insert_idx] = {height, front};
                    done_sort += 1;
                    last_pos = insert_idx;
                }else{
                    result[done_sort] = {height, front};
                    last_pos = done_sort;
                    done_sort += 1;
                }
            }
            // for(int i = 0; i < done_sort; i++){
            //     vector<int> num = result[i];
            //     cout << "[" << num[0] << "," << num[1] << "], "; 
            // }
            // cout << " | " << done_sort << endl;
        }

        return result;
    }
};
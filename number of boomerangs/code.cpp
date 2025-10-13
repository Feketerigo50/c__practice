class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3) return 0;

        int result = 0;
        for(int i = 0; i < n; i++){
            unordered_map<long long, int> distance;
            for(int j = 0; j < n; j++){
                long long dis_x = (long long)(points[i][0] - points[j][0]);
                dis_x *= dis_x;
                long long dis_y = (long long)(points[i][1] - points[j][1]);
                dis_y *= dis_y;

                distance[dis_x + dis_y]++;
            }

            for(auto& [dis, count] : distance){
                result += count*(count - 1);
            }
        }
        
        return result;
    }
};
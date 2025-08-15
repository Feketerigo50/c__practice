class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        unordered_set<string> dup_corner;

        for(int i = 0; i < rectangles.size(); i++){
            int tx1 = rectangles[i][0];
            int ty1 = rectangles[i][1];
            int tx2 = rectangles[i][2];
            int ty2 = rectangles[i][3];

            // cout << (long long) (tx2 - tx1) * (ty2 - ty1) << endl;
            area += (long long) (tx2 - tx1) * (ty2 - ty1);

            x1 = min(x1, tx1);
            y1 = min(y1, ty1);
            x2 = max(x2, tx2);
            y2 = max(y2, ty2);

            vector<string> corners = {
                to_string(tx1) + " " + to_string(ty1),
                to_string(tx1) + " " + to_string(ty2),
                to_string(tx2) + " " + to_string(ty1),
                to_string(tx2) + " " + to_string(ty2)
            };
            for(auto corn : corners){
                if(!dup_corner.insert(corn).second){
                    dup_corner.erase(corn);
                }
            }
        }

        if(dup_corner.size() != 4) return false;
        // cout << x1 << " " << y1 << " | " << x2 << " " << y2 << endl;
        // cout << area << endl;
        if( (long long) (x2 - x1) * (y2 - y1) != area) return false;

        vector<string> corners = {
            to_string(x1) + " " + to_string(y1),
            to_string(x1) + " " + to_string(y2),
            to_string(x2) + " " + to_string(y1),
            to_string(x2) + " " + to_string(y2)
        };
        for(auto corn : corners){
            if(dup_corner.insert(corn).second) return false;
        }

        return true;
    }
};
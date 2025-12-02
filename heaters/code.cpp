class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int radius = INT_MIN;
        for(int house : houses){
            int left = 0;
            int right = heaters.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(heaters[mid] < house){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }

            int distLeft = INT_MAX;
            int distRight = INT_MAX;
            if(left == heaters.size()){
                distLeft = house - heaters[left-1];
            }else if(left == 0){
                distRight = heaters[0] - house;
            }else{
                distRight = heaters[left] - house;
                distLeft = house - heaters[left-1];
            }

            radius = max(radius, min(distRight, distLeft));
        }

        return radius;
    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n-1;
        int h = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(citations[mid] >= n - mid){
                h += right - mid + 1;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return h;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int front_idx;
        for(int back_idx = numbers.size()-1; back_idx > 0; back_idx--){
            int cur_target = target - numbers[back_idx];
            front_idx = binary_search(numbers, cur_target, back_idx);
            if(front_idx != -1){
                result.push_back(front_idx + 1);
                result.push_back(back_idx + 1);
                break;
            }
        }

        return result;
    }

    int binary_search(const vector<int>& numbers,int cur_target, int back_idx){
        int front = 0;
        int back = back_idx;
        while(front <= back){
            int mid = front + (back-front)/2;
            if(numbers[mid] == cur_target){
                return mid;
            }else if(numbers[mid] > cur_target){
                back = mid - 1;
            }else{
                front = mid + 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candi1 = INT_MIN;
        int candi2 = INT_MIN+1;
        int count1 = 0;
        int count2 = 0;
        for(auto num : nums){
            if(candi1 == num){
                count1++;
            }else if(candi2 == num){
                count2++;
            }else if(count1 == 0){
                candi1 = num;
                count1 = 1;
            }else if(count2 == 0){
                candi2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(auto num : nums){
            if(num == candi1){
                count1++;
            }else if(num == candi2){
                count2++;
            }
        }
        
        vector<int> result;
        if(count1 > nums.size()/3) result.push_back(candi1);
        if(count2 > nums.size()/3) result.push_back(candi2);

        return result;

    }
};
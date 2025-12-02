class Solution {
public:
    multiset<int> lower, upper;

    void makeBalance(){
        if(upper.size() > lower.size()){
            int tmp = *upper.begin();
            lower.insert(tmp);
            upper.erase(upper.find(tmp));
        }else if(lower.size() > upper.size() + 1){
            int tmp = *lower.rbegin();
            lower.erase(lower.find(tmp));
            upper.insert(tmp);
        }

        return;
    }

    void add(int num){
        if(lower.empty() || num <= *lower.rbegin()){
            lower.insert(num);
        }else{
            upper.insert(num);
        }
        makeBalance();

        return;
    }

    void remove(int num){
        if(num <= *lower.rbegin()){
            lower.erase(lower.find(num));
        }else{
            upper.erase(upper.find(num));
        }
        makeBalance();

        return;
    }

    double median(int k){
        if(k % 2){
            return (double)(*lower.rbegin());
        }

        return ((double)(*lower.rbegin()) + (double)(*upper.begin())) / 2.0;
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
            if(i >= k) remove(nums[i - k]);
            if(i >= k-1) ans.push_back(median(k));
        }
        
        return ans;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> save;
        for(int i = 0; i < nums.size(); i++){
            save.push_back(to_string(nums[i]));
        }

        sort(save.begin(), save.end(), [](string& a, string& b){
            return a + b > b + a;
        });

        if(save[0] == "0") return "0";
        string result = "";
        for(auto s : save){
            result += s;
        }
        return result;
    }
};
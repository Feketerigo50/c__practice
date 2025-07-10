class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if(memo.count(expression)) return memo[expression];

        vector<int> result;
        for(int idx = 0; idx < expression.length(); idx++){
            if(!isdigit(expression[idx])){
                string left = expression.substr(0, idx);
                string right = expression.substr(idx + 1);

                vector<int> left_possible = diffWaysToCompute(left);
                vector<int> right_possible = diffWaysToCompute(right);

                for(int i = 0; i < left_possible.size(); i++){
                    for(int j = 0; j < right_possible.size(); j++){
                        if(expression[idx] == '+'){
                            result.push_back(left_possible[i] + right_possible[j]);
                        }else if(expression[idx] == '-'){
                            result.push_back(left_possible[i] - right_possible[j]);
                        }else if(expression[idx] == '*'){
                            result.push_back(left_possible[i] * right_possible[j]);
                        }
                    }
                }
            }
        }
        
        if(result.empty()){
            result.push_back(stoi(expression));
        }

        return memo[expression] = result;
    }
};
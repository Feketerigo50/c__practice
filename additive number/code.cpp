class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 1; i <= n/2; i++){
            if(num[0] == '0' && i > 1) break;
            string first = num.substr(0, i);
            for(int j = 1; max(i, j) <= n - i - j; j++){
                if(num[i] == '0' && j > 1) break;
                string second = num.substr(i, j);
                if(isValid(first, second, num.substr(i + j))){
                    return true;
                }
            }
        }
        return false;
    }

    bool isValid(string first, string second, string rest){
        while(rest.length() != 0){
            string sum = addstring(first, second);
            if(rest.find(sum) != 0) return false;
            rest = rest.substr(sum.length());
            first = second;
            second = sum;
        }
        return true;
    }


    string addstring(string first, string second){
        string sum = "";
        int idxf = first.length() - 1;
        int idxs = second.length() - 1;
        int carry = 0;
        while( idxf > -1 || idxs > -1 || carry){
            if(idxf > -1) carry += first[idxf--] - '0';
            if(idxs > -1) carry += second[idxs--] - '0';
            sum = to_string(carry % 10) + sum;
            carry /= 10;
        }

        return sum;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        string result;
        if((numerator < 0) ^ (denominator < 0)) result = "-";
        
        long long num = abs((long long)numerator);
        long long den = abs((long long) denominator);
        result += to_string(num / den);

        long long remain = num % den;
        if(remain == 0) return result;

        result += ".";
        unordered_map<long long, int> detect_recursive;
        while(remain != 0){
            if(detect_recursive.find(remain) != detect_recursive.end()){
                result.insert(detect_recursive[remain], "(");
                result += ")";
                break;
            }
            detect_recursive[remain] = result.length();
            remain *= 10;
            result += to_string(remain / den);
            remain %= den;
        }

        return result;
    }
};
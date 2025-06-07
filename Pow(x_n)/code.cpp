class Solution {
public:
    double myPow(double x, int n) {
        long long parameter = n;
        
        if(n < 0){
            x = 1/x;
            parameter = -parameter;
        }


        return lognpow(x, parameter);
    }

    double lognpows(double num, long long para){
        if(para == 0.0) return 1.0;

        if(para % 2 == 1){
            return lognpow(num, para/2) * lognpow(num, para/2) * num;
        }else{
            return lognpow(num, para/2) * lognpow(num, para/2);
        }
    }

    double lognpow(double num, long long para){
        double res = 1.0;
        while(para > 0){
            if(para % 2 == 1){
                res *= num;
            }
            num*= num;
            para /= 2;
        }

        return res;
    }
};
class Solution {
public:
    string validIPAddress(string queryIP) {
        bool isIPV4 = false;
        bool isIPV6 = false;
        for(int i = 0; i < 5; i++){
            if(queryIP[i] == '.') isIPV4 = true;
            if(queryIP[i] == ':') isIPV6 = true;
        }

        if(isIPV4){
            // cout << "ipv4" << endl;
            int dotCnt = 0;
            int num = 0;
            int idx = 0;
            char lastChar = '.';
            while(idx < queryIP.size()){
                if(dotCnt > 3 || (!isdigit(queryIP[idx]) && queryIP[idx] != '.') || num < 0 || num > 255){
                    // cout << "num: " << num << ",dot: " << dotCnt << ",idx: " << idx << endl;
                    return "Neither";
                }
                if(queryIP[idx] == '0'){
                    if(lastChar == '.' && idx+1 != queryIP.size() && queryIP[idx+1] != '.') return "Neither";
                }
                if(queryIP[idx] == '.'){
                    if((idx + 1 != queryIP.size()) && queryIP[idx+1] == '.') return "Neither";
                    if(idx + 1 == queryIP.size()) return "Neither";
                }
                
                if(queryIP[idx] == '.'){
                    // cout << num << endl;
                    dotCnt++;
                    num = 0;
                }else{
                    num = num*10 + queryIP[idx] - '0';
                }
                
                lastChar = queryIP[idx];
                idx++;
            }

            if(dotCnt == 3 && num < 256) return "IPv4";
        }

        if(isIPV6){
            int dotCnt = 0;
            int digitCnt = 0;
            int idx = 0;
            char lastChar;
            while(idx < queryIP.size()){
                char cur = queryIP[idx];

                if(dotCnt > 7 || digitCnt > 4 || (!isdigit(cur) && cur != ':' && tolower(cur)-'a' > 5)){
                    // cout << "digitCnt: " << digitCnt << ",lastchar: " << lastChar << ",dot: " << dotCnt << ",idx: " << idx << endl;
                    return "Neither";
                }
                if(cur == ':'){
                    // cout << idx << endl;
                    if((idx + 1 != queryIP.size()) && queryIP[idx+1] == ':') return "Neither";
                    if(idx + 1 == queryIP.size()) return "Neither";
                    if(digitCnt < 1) return "Neither";
                }
                
                if(cur == ':'){
                    dotCnt++;
                    digitCnt = 0;
                }else{
                    digitCnt++;
                }
                
                lastChar = cur;
                idx++;
            }

            if(dotCnt == 7 && digitCnt < 5) return "IPv6";
        }

        return "Neither";
    }
};
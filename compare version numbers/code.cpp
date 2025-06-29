class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = cut(version1);
        vector<int> ver2 = cut(version2);

        int len = max(ver1.size(), ver2.size());
        for(int i = 0; i < len; i++){
            int num1 = i < ver1.size() ? ver1[i] : 0 ;
            int num2 = i < ver2.size() ? ver2[i] : 0 ;
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }
        return 0;
    }

    vector<int> cut(string tmp){
        vector<int> result;
        int num = 0;

        for(int i = 0; i < tmp.length(); i++){
            if(tmp[i] == '.'){
                result.push_back(num);
                num = 0;
            }else{
                num = num*10 + (tmp[i] - '0');
            }
        }
        result.push_back(num);

        return result;
    }
};
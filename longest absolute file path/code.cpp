class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> depthLen;
        depthLen[0] = 0;
        int maxLen = 0;

        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (line[depth] == '\t') depth++;

            string name = line.substr(depth);
            if (name.find('.') != string::npos) { 
                maxLen = max(maxLen, depthLen[depth] + (int)name.size());
            } else {
                depthLen[depth + 1] = depthLen[depth] + name.size() + 1;
            }
        }
        return maxLen;
    }
};
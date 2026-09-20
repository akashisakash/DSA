class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        string substring = "";
        vector<int> index = {};
        int result = 0;
        
        // Step 1: Filter out all valid pairs to find the "barriers"
        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                substring.push_back(s[i]);
                index.push_back(i);
            } else if (s[i] == ')'){
                if (!substring.empty()){
                    if (substring.back() == '('){
                        substring.pop_back();
                        index.pop_back();
                        continue;
                    }
                }
                substring.push_back(s[i]);
                index.push_back(i);
            }
        }
        
        // Step 2: If no barriers, the whole string is valid
        if (substring.empty()){
            return n;
        }
        
        // Step 3: Add a virtual barrier at the end to measure the last gap
        index.push_back(n);
        
        // Gap before the first barrier
        if ((index[0]) > result){
            result = index[0];
        }
        
        // Step 4: Find the max gap between the remaining barriers
        for (int i = 1; i < index.size(); i++){
            int j = index[i] - index[i-1] - 1;
            if (j > result){
                result = j;
            }
        }
        
        return result;
    }
};
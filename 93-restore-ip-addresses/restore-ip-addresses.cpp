class Solution {
public:
    static const int _ ;
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        backtrack(s, 0, 0, path, res);
        return res;
    }
private:
    void backtrack(const string& s, int start, int parts, string& path, vector<string>& res) {
        if (parts == 4) {
            if (start == (int)s.size()) res.push_back(path.substr(0, path.size() - 1));
            return;
        }
        for (int len = 1; len <= 3 && start + len <= (int)s.size(); ++len) {
            if (len > 1 && s[start] == '0') break;
            string part = s.substr(start, len);
            int val = stoi(part);
            if (val > 255) break;
            int oldSize = path.size();
            path += part + '.';
            backtrack(s, start + len, parts + 1, path, res);
            path.resize(oldSize);
        }
    }
};
const int Solution::_ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();
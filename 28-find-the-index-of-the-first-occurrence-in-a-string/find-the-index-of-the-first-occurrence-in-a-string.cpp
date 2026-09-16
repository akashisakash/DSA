class Solution {
public:
    vector<int> buildLPS(string &pat) {
        int n = pat.size();
        vector<int> lps(n, 0);

        int len = 0, i = 1;

        while (i < n) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

        return lps;
    }

    int strStr(string s, string pat) {
        int m = s.size(), n = pat.size();
        if (m < n) return -1;

        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;

        while (i < m) {
            if (s[i] == pat[j]) {
                i++;
                j++;
                if (j == n) return i - n;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }
};
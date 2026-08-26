class Solution {
public:
    map<pair<int,int>, bool> m1;

    bool ans(int i, int j, string s, string p) {

        int n = s.size();
        int m = p.size();

        // Both string and pattern completed
        if(i >= n && j >= m)
            return true;

        // Pattern finished but string remains
        if(j >= m)
            return false;

        // Memoized state
        if(m1.contains({i, j}))
            return m1[{i, j}];

        // Current character match check
        bool match = i < n && (s[i] == p[j] || p[j] == '.');

        // Handle '*'
        if((j + 1) < m && p[j + 1] == '*') {

            m1[{i, j}] =
                (match && ans(i + 1, j, s, p)) ||
                ans(i, j + 2, s, p);

            return m1[{i, j}];
        }

        // Normal matching
        if(match) {
            m1[{i, j}] = ans(i + 1, j + 1, s, p);
            return m1[{i, j}];
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return ans(0, 0, s, p);
    }
};
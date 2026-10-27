class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> answer;
        answer.reserve(m);

        for (int i = 0; i < m; ++i) {
            string row;
            row.reserve(n);

            for (int j = 0; j < n; ++j) {
                row.push_back((i == 0 || j == n - 1) ? '.' : '#');
            }

            answer.push_back(row);
        }

        return answer;
    }
};
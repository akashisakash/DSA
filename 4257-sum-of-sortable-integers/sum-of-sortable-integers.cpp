class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int N = nums.size();

        vector<int> divisors;

        for (int i = 1; i <= N / i; i++) {
            if (N % i == 0) {
                divisors.push_back(i);

                if (N / i != i) {
                    divisors.push_back(N / i);
                }
            }
        }

        int answer = 0;

        for (int d : divisors) {
            int r = 0;
            int l = 0;
            bool valid = true;

            int prev_max = INT_MIN;

            while (r < N) {
                int start = r;
                r += d;

                int drops = 0;
                int curr_max = INT_MIN;
                int curr_min = INT_MAX;

                while (l < r) {
                    if (l + 1 < r && nums[l] > nums[l + 1]) {
                        if (drops < 1 && nums[start] >= nums[r - 1]) {
                            drops++;
                        } else {
                            valid = false;
                            break;
                        }
                    }

                    curr_min = min(curr_min, nums[l]);
                    curr_max = max(curr_max, nums[l]);
                    l++;
                }

                if (!valid) {
                    break;
                }

                if (curr_min < prev_max) {
                    valid = false;
                    break;
                }

                prev_max = curr_max;
            }

            if (valid) {
                answer += d;
            }
        }

        return answer;
    }
};
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

        // multipliers for each index
        vector<long long> mul(n, 1);

        // group queries by step k
        unordered_map<int, vector<vector<int>>> mp;
        for (auto &q : queries) {
            mp[q[2]].push_back(q);
        }

        // handle small k
        for (auto &[k, qs] : mp) {
            if (k <= B) {
                vector<long long> temp(n, 1);

                for (auto &q : qs) {
                    int l = q[0], r = q[1], val = q[3];

                    for (int i = l; i <= r; i += k) {
                        temp[i] = (temp[i] * val) % MOD;
                    }
                }

                for (int i = 0; i < n; i++) {
                    mul[i] = (mul[i] * temp[i]) % MOD;
                }
            }
        }

        // handle large k مباشرة
        for (auto &[k, qs] : mp) {
            if (k > B) {
                for (auto &q : qs) {
                    int l = q[0], r = q[1], val = q[3];

                    for (int i = l; i <= r; i += k) {
                        mul[i] = (mul[i] * val) % MOD;
                    }
                }
            }
        }

        // apply multiplication + xor
        int ans = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = (1LL * nums[i] * mul[i]) % MOD;
            ans ^= nums[i];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        for(int &x: nums) {
            string s = to_string(x);
            for(char &ch: s) {
                v.push_back(ch-'0');
            }
        }
        return v;
    }
};
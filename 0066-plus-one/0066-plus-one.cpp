class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i = digits.size()-1;
        while(i >= 0 && digits[i] == 9) {
            ans.push_back(0);
            i--;
        }
        if(i == -1) ans.push_back(1);
        else {
            ans.push_back(digits[i--]+1);
        }
        while(i >= 0) {
            ans.push_back(digits[i--]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
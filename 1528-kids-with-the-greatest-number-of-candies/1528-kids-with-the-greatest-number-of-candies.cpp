class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(int &x: candies) {
            ans.push_back((x+extraCandies >= mx));
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_so_far = 0;
        for(auto &x: st) {
            if(st.find(x-1) == st.end()) {
                int len = 1;
                while(st.find(x+len) != st.end()) {
                    len++;
                }
                max_so_far = max(max_so_far, len);
            }
        }
        return max_so_far; 
    }
};

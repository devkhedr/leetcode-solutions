class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        for(int &i: nums) st.insert(i);
        int dist = st.size(), cnt = 0;
        st.clear();
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                st.insert(nums[j]);
                cnt += (st.size() == dist);
            }
            st.clear();
        }
        return cnt;
    }
};
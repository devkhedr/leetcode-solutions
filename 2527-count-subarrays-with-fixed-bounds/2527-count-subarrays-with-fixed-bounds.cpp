class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minm=-1;
        int maxm=-1;
        int start=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                if(nums[i]==minK)minm=i;
                if(nums[i]==maxK)maxm=i;
                int k=min(minm,maxm);
                if(minm!=-1 && maxm!=-1 && k>start){
                    ans+=(k-start);
                }
            }
            else start=i;
        }
        return ans;
    }
};
class Solution {
public:
    int search(vector<int>&v, int target) {
        int n = v.size();
        int l = 0;
        int h = n-1;
        int ans = -1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(v[mid]==target){
                ans = mid;
                break;
            }

            if(v[mid] > v[h]){
                if(target >=v[l] && target < v[mid]){
                    h = mid -1;
                }
                else l = mid +1;
            }else{
                if(target > v[mid] && target<=v[h]){
                   l = mid + 1;
                }
                else  h= mid -1;
            }
        }

        return ans;

    }
};
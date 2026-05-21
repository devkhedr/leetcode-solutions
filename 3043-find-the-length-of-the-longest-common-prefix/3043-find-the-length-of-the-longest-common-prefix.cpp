class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set1;
        for(int i : arr1){
            int temp = i;
            int prefix = 0;
            while(temp){
                set1.insert(temp);
                temp /= 10;
            }
        }
        int maxLength = 0;
        for(int i : arr2){
            int val = i;
            while(val){
                if(set1.count(val)){
                    int currLength = 0;
                    int temp = val;
                    while(temp){
                        currLength++;
                        temp /= 10;
                    }
                    maxLength = max(maxLength,currLength);
                    break;
                }
                val /= 10;
            }
        }
        return maxLength;
}
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> resultArray;
        unordered_map<int, int> map;
        int count = 0;

        for(int i = 0; i < nums.size() ;i++){
            map[i] = nums[i];
        }

        for(int i = 0; i < nums.size() ;i++){
            if(map[i] < pivot){
                resultArray.push_back(map[i]);
                count++;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(map[i] == pivot){
                resultArray.push_back(map[i]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(map[i] > pivot){
                resultArray.push_back(map[i]);
            }
        }

        return resultArray;
    }
};
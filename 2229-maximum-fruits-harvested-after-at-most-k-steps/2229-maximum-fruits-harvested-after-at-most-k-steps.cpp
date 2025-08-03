class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, max_fruits = 0, total_fruits = 0;

        for(int right = 0; right < n; right++){
            total_fruits += fruits[right][1];

            while(left <= right){
                int l = fruits[left][0];
                int r = fruits[right][0];

                int min_steps = min(
                                    abs(startPos - l) + (r - l),
                                    abs(startPos - r) + (r - l)
                                );

                if(min_steps <= k) break;

                total_fruits -= fruits[left][1];
                left++;
            }

            max_fruits = max(max_fruits, total_fruits);
        }

        return max_fruits;
    }
};
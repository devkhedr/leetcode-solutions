// Author: Mohamed Khedr

class Solution {
public:
    /* the triviail approach of the problem:
    - just square each number of the array, then sort it in ascending order.
    - the complexity of this solution is O(N log(N)) (time of builtin sort function)
    another approach: can be solved by two pointer technique
    - we guarantee that the given array is sorted in ascending order
    - we can define 2 variables point to the left and right element in the array
    - then traverse on the array by these pointers and comparing the squares of the left and
       right element then store the largest square of them, and move the choosen pointer.
    - at the end, we have the result array sorted in descending order, we can reverse it in O(N).
    */
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int left = nums[l] * (nums[l] < 0 ? -1 : 1);
            int right = nums[r] * (nums[r] < 0 ? -1 : 1);
            if (left >= right)
                ans.push_back(left * left), l++;
            else
                ans.push_back(right * right), r--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// time: O(N)

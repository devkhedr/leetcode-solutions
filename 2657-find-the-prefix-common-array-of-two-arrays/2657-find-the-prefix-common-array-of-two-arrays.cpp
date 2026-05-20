class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> prev;
        vector<unordered_set<int>> prefixCount;
        for(int i = 0; i < A.size(); i++) {
            prev.insert(A[i]);
            prefixCount.push_back(prev);
        }

        vector<int> result;
        prev.clear();
        for(int i = 0; i < B.size(); i++) {
            int count = 0;
            prev.insert(B[i]);
            for(auto num : prev) {
                if(prefixCount[i].count(num)) count++;
            }
            result.push_back(count);
        }

        return result;
    }
};
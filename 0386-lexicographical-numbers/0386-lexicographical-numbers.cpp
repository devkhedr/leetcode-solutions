class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        sort(v.begin(), v.end(), [](int a, int b){
            string x = to_string(a), y = to_string(b);
            return x < y;
        });
        return v;
    }
};
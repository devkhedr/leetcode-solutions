class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        for(int i=1;i<=n;i++) {
            v.push_back(i);
        }
        sort(v.begin(), v.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            return a < b;
        });
        return v;
    }
};
// mohamed
// ahmed

// ahh
// aah

// aaa
// aa
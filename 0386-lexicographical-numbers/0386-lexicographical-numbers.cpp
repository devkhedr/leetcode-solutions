class Solution {
public:
    vector<int> v;
    int nn;
    void rec(int x) {
        if(x > nn) return;
        v.push_back(x);
        for(int i=0;i<10;i++) {
            rec(x*10+i);
        }
    }
    vector<int> lexicalOrder(int n) {
        nn = n;
        for(int i=1;i<=9;i++) rec(i);
        return v;
    }
};
// 1 -> 10 , 11 , 12 , 13 ,14
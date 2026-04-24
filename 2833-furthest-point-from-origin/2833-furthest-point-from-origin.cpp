class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length(), cnt_1 = 0, cnt_2 = 0;
        for(char &x: moves) cnt_1+=(x == 'L');
        for(char &x: moves) cnt_2+=(x == 'R');
        return n - 2*min(cnt_1, cnt_2);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Sort: by x ascending, and if equal, by y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });

        int counter = 0;
        for (int i = 0; i < points.size(); i++) {
            int x0 = points[i][0], y0 = points[i][1];
            int bottom = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[j][0], y1 = points[j][1];
                if (bottom < y1 && y1 <= y0) {
                    bottom = y1;
                    counter++;
                    if (y1 == y0) {
                        break;
                    }
                }
            }
        }
        return counter;
    }
};

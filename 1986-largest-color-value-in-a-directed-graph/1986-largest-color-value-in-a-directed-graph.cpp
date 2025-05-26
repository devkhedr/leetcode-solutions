#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        vector<vector<int>> colorCounts(n, vector<int>(26, 0));
        
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
            colorCounts[i][colors[i] - 'a'] = 1;
        }
        
        int processed = 0;
        int maxColorValue = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            
            int currentMax = *max_element(colorCounts[u].begin(), colorCounts[u].end());
            maxColorValue = max(maxColorValue, currentMax);
            
            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c) {
                    int newCount = colorCounts[u][c];
                    if (c == colors[v] - 'a') {
                        newCount += 1;
                    }
                    if (newCount > colorCounts[v][c]) {
                        colorCounts[v][c] = newCount;
                    }
                }
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (processed != n) {
            return -1;
        }
        
        return maxColorValue;
    }
};
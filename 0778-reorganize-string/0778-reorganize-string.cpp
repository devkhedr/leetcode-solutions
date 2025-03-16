class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> f(26);
        for(int i=0;i<s.length();i++) {
            f[s[i]-'a']++;
        }
        for(char a='a';a<='z';a++) {
            if(f[a-'a'] > 0) pq.push({f[a-'a'], a});
        }
        string t = "";
        while(!pq.empty()) {
            pair<int, int> x = pq.top();
            pq.pop();
            if(t.empty() || x.second != t.back() ) {
                t += x.second;
                if(x.first > 1) pq.push({x.first-1, x.second});
            }    
            else {
                if(pq.empty()) return "";
                pair<int, int> y = pq.top();
                pq.pop();
                pq.push(x);
                t += y.second;
                if(y.first > 1) pq.push({y.first-1, y.second});
            }
        }
        return t;
    }
};
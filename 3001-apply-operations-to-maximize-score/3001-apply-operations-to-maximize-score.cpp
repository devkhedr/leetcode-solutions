#define ll long long
class Solution {
public:
    ll mod_exp(ll base, ll exp, ll mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
                exp--;
            }
            else {
                base = (base * base) % mod;
                exp /= 2;
            }
        }
        return result;
    }

    static bool myComp(vector<int> &a, vector<int>&b) {
        if(a[0] > b[0]) return true;
        if(a[0] == b[0]) return a[1] < b[1];
        return false;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(100005, 0);
        
        for (int i = 2; i <= 100004; i++) {
            if (score[i] == 0) {
                for (int j = i; j <= 100004; j += i) {
                    score[j] += 1;
                }
            }
        }

        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && score[nums[st.top()]] < score[nums[i]]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && score[nums[st.top()]] <= score[nums[i]]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        ll ans = 1;
        ll mod = 1e9 + 7;

        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end(), myComp);

        for(int i = 0; i < n && k > 0; i++) {
            int num = v[i][0];
            int idx = v[i][1];
            ll leftSpan = idx - left[idx];
            ll rightSpan = right[idx] - idx;
            ll subs = (leftSpan * rightSpan);
            ll take = min((ll)k, subs);
            ans = (ans * mod_exp(num, take, mod)) % mod;
            k -= take;
        }
        return (int)ans;
    }
};
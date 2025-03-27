class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        unordered_map<int, int> freq;
        int cnt = 0, mjr = 0;
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
            if(cnt == 0) mjr = nums[i], cnt = 1;
            else if(mjr == nums[i]) cnt++;
            else cnt--;
            
            if(freq[mjr] > (i+1) / 2) pre[i] = mjr;
            else pre[i] = INT_MAX;
        }
        cout << "hi\n";
        cnt = mjr = 0;
        freq.clear();
        for(int i=n-1;i>=0;i--) {
            freq[nums[i]]++;
            if(cnt == 0) mjr = nums[i], cnt = 1;
            else if(mjr == nums[i]) cnt++;
            else cnt--;
            if(freq[mjr] > (n-i) / 2) suf[i] = mjr;
            else suf[i] = INT_MIN;
            cout << i  << ' ' << mjr << ' ' << freq[mjr] << '\n';
        }
        for(int i=0;i<n-1;i++) {
            if(pre[i] == suf[i+1]) return i;
        }
        return -1;
    }
};
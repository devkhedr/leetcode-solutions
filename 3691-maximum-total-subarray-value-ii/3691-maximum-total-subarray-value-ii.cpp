#define ll long long int  
struct segtree
{
    vector<int> mxv, mnv;
    int n;

    segtree(vector<int> &nums)
    {

        n = nums.size();
        mxv.resize(4*n);
        mnv.resize(4*n);
        build(0,n - 1, 1, nums);

    }

    void build(int i, int j, int x, vector<int> &nums)
    {
        int n = nums.size();

        if(i == j)
        {


            mxv[x] = mnv[x] = nums[i];

            return;

        }

        int mid = (i + j)/2;

        build(i , mid , 2 * x , nums);
        build(mid + 1, j, 2 * x + 1, nums);

        mxv[x] = max(mxv[2*x], mxv[2*x + 1]);
        mnv[x] = min(mnv[2*x], mnv[2* x + 1]);


    }

    int find_max(int i, int j, int x,  int l, int r)
    {
        if(l <= i && j <= r)
            return mxv[x];

        int mid = (i + j)/2;
        int ans = INT_MIN; 

       
        if(l <= mid)
            ans = max(ans, find_max(i, mid, 2 * x, l, r));
        if(r > mid)
            ans = max(ans, find_max(mid + 1, j, 2 * x + 1, l, r));

        return ans;

    }

    int find_min(int i, int j, int x,  int l, int r)
    {
        if(l <= i && j <= r)
            return mnv[x];

        int mid = (i + j)/2;
        int ans = INT_MAX; 

        
        if(l <= mid)
            ans = min(ans, find_min(i, mid, 2 * x, l, r));
        if(r > mid)
            ans = min(ans, find_min(mid + 1, j, 2 * x + 1, l, r));

        return ans;

    }

};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        int n = nums.size();


        segtree sg(nums);

        priority_queue<tuple<int,int,int>> pq;
        set<pair<int, int>> visited;

        for(int i = 0; i < n; i++)
        {
            pq.emplace(sg.find_max(0, n - 1, 1, i, n - 1) 
                        - sg.find_min(0, n - 1, 1, i , n - 1),
                        i, n - 1);

        }

        ll ans = 0;

        while(k--)
        {
            auto [val, i, j] = pq.top();
            pq.pop();

            ans += val;


            if(j > i)
            {
                pq.emplace(sg.find_max(0, n - 1, 1, i, j - 1) 
                        - sg.find_min(0, n - 1, 1, i , j - 1),
                        i, j - 1);
            }

        }


        return ans;
        
        
    }
};
class Solution {
public:
    int sz=50001;
    vector<int> segment = vector<int>(4*50001, 0);
    set<int> blocks;
    void update(int block, int i, int l, int r) {
        if(l==r) {
            auto it = blocks.lower_bound(block);
            segment[i] = block - *prev(it);
            return;
        }
        int mid = l + (r - l) / 2;
        if (block <= mid) {
            update(block, 2 * i + 1, l, mid);
        } else {
            update(block, 2 * i + 2, mid + 1, r);
        }
        segment[i] = max(segment[2 * i + 1], segment[2 * i + 2]);
    }

  int search(int ql, int i, int l, int r) {
    if (r <= ql) return segment[i];
    if (l > ql) return 0;

    int mid = (l + r) / 2;
    if (ql <= mid)
        return search(ql, 2*i+1, l, mid);

    return max(segment[2*i+1], search(ql, 2*i+2, mid+1, r));
}
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;

        blocks.insert(0);
        blocks.insert(sz);

        update(sz, 0, 0, sz);

        for (auto &q:queries) {
            int type = q[0];

            if (type == 1) {
                int range = q[1];
                blocks.insert(range);
                update(range, 0, 0, sz);
                auto it = blocks.find(range);
                auto nxt = next(it);
                if (nxt != blocks.end()) {
                    update(*nxt, 0, 0, sz);
                }
            } else {
                int range = q[1];
                int blockSize = q[2];

                int canPlace = search(range, 0, 0, sz);
                auto it = blocks.upper_bound(range);
                canPlace = max(canPlace, range - *prev(it));
                ans.push_back(canPlace >= blockSize);
            }
        }
        return ans;
    }
};
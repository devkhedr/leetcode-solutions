class Solution {
    public long putMarbles(int[] w, int k) {
        if (k == 1) return 0;

        int[] sum = new int[w.length - 1];
        for (int i = 0; i < sum.length; i++) sum[i] = w[i] + w[i + 1];

        Arrays.sort(sum);
        long res = 0;
        for (int i=0; i<k-1; i++) 
        res += sum[sum.length-1-i] - sum[i];

        return res;
    }
}
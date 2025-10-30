class Solution {
public:
    int n,sum;
    vector<int>a;
    int dp[201][20010];

    int rec(int level, int curr_sum) {
        // pruning
        if(curr_sum>(sum-curr_sum)) {
            return 0;
        }
        // base-case
        if(level==n) {
            if(curr_sum==(sum-curr_sum)) {
                return 1;
            }
            return 0;
        }
        // cache-check
        if(dp[level][curr_sum]!=-1) {
            return dp[level][curr_sum];
        }
        // compute
        int ans = 0;
        ans = rec(level+1, curr_sum);
        ans = max(ans, rec(level+1, a[level]+curr_sum));
        // save & return
        return dp[level][curr_sum]=ans;
    }

    bool canPartition(vector<int>& nums) {
        n=nums.size();
        a.resize(n);
        a=nums;
        memset(dp, -1, sizeof(dp));
        sum = accumulate(a.begin(), a.end(), 0);
        if(sum%2) return 0;
        if(rec(0,0)==1) {
            return true;
        }
        return false;
    }
};

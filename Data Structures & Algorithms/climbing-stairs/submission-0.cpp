using ll = long long;
class Solution {
public:

    int climbStairs(int n) {
        vector<ll> ways(n+1,0);
        ways[1] = 1ll;
        ways[2] = 2ll;

        for(int i=3;i<=n;i++)
            ways[i] = ways[i-1]+ways[i-2];       

        return ways[n];
    
    }

    
};

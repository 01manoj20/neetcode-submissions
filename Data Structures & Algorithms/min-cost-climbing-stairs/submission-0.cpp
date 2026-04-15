using ll = long long;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        ll n = cost.size();
        vector<ll> floor_cost(n,0);

        floor_cost[n-1] = cost[n-1];
        floor_cost[n-2] = cost[n-2];
        for(int i=n-3;i>=0;i--)
            floor_cost[i] = min(cost[i]+floor_cost[i+1],cost[i]+floor_cost[i+2]);

        return min(floor_cost[0],floor_cost[1]);
        



    }
};

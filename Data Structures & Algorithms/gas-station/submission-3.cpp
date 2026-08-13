class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> dif(n,0);

        for(int i=0;i<n;i++)
            dif[i] = (gas[i]-cost[i]);

        int r = n-1;
        int l = 0;

        int cur_gas = dif[r];
        while(l<r)
        {
            if(cur_gas<0){
                r--;
                cur_gas+=dif[r];
            }
            else
            {
                cur_gas+=dif[l];
                l++;
            }
        }

        if(cur_gas>=0)
            return r;
        else
            return -1;
        
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pos(n,false);
        pos[n-1] = true;

        int min_req  = 1;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>=min_req){
                pos[i] = true;
                min_req = 1;
            }
            else
                min_req++;
            cout<<i<<" "<<pos[i]<<endl;
        }

        return pos[0];
    }
};

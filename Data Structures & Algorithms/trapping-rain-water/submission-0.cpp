class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = -1;
        right_max[n-1] = -1;

        for(int i=1;i<n;i++)
            left_max[i] = max(left_max[i-1], height[i-1]);

        for(int i=n-2;i>=0;i--)
            right_max[i] = max(right_max[i+1],height[i+1]);


        int ans = 0;

        for(int i=1;i<n-1;i++)
        {
            cout<<height[i]<<" "<<left_max[i]<<" "<<right_max[i]<<endl;
            int min_end = min(left_max[i],right_max[i]);
            if((height[i]<left_max[i]) && (height[i]<right_max[i]))
            {
                ans+=(min_end - height[i]);
                cout<<"adding "<<min_end-height[i]<<endl;
            }
        }

        return ans;
        
    }
};

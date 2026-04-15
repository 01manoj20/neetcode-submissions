class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size()-1;

        int ans = -1;

        while(l<=r)
        {   

            ans = max(min(heights[l],heights[r])*(r-l),ans);
            if(heights[l]<=heights[r])
                l++;
            else r--;

        }

        return ans;
    }
};

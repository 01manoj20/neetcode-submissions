class Solution {
public: 
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> next_small(n,-1);
        vector<int> before_small(n,-1);

        stack<pair<int,int>> st;


        for(int i=0;i<n;i++)
        {

            if(!st.empty() && st.top().first<=heights[i])
            {
                st.push({heights[i],i});
            }
            
            while(!st.empty() && st.top().first>heights[i])
            {
                auto cur = st.top();
                next_small[cur.second] = i;
                st.pop();
            }
            
            st.push({heights[i],i});
            
        }

        stack<pair<int,int>> st2;

        for(int i=n-1;i>=0;i--)
        {
            if(!st2.empty() && st2.top().first<=heights[i])
            {
                st2.push({heights[i],i});
            }
            
            while(!st2.empty() && st2.top().first>heights[i])
            {
                auto cur = st2.top();
                before_small[cur.second] = i;
                st2.pop();
            }
            
            st2.push({heights[i],i});
        }

        int ans = -1;

        for(int i=0;i<n;i++)
            cout<<before_small[i]<<" ";
        cout<<endl;

        for(int i=0;i<n;i++)
            cout<<next_small[i]<<" ";
        cout<<endl;

        for(int i=0;i<n;i++)
        {
            int max_l = (before_small[i] == -1)? 0:before_small[i]+1;
            int max_r = (next_small[i] == -1)? n-1:next_small[i]-1;

            cout<<i<<" "<<max_l<<" "<<max_r<<" "<<heights[i]<<endl;

            ans = max((max_r-max_l+1)*heights[i],ans);
        }

        return ans;
        
    }
};

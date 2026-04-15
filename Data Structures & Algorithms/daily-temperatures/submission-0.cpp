using ll = long long;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<ll,ll>> st;
        

        ll n = temperatures.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            ll cnt = 0;
            ll temp = temperatures[i];

            while(!st.empty())
            {
                if(st.top().first>=temp){
                    cout<<"pushing "<<temp<<" "<<i<<endl;
                    st.push({temp,i});
                    break;
                }
                else
                {

                    ll ind = st.top().second;
                    ans[ind] = i-ind;
                    cout<<"pop "<<st.top().first<<" "<<st.top().second<<" "<<i-ind<<endl;
                    st.pop();
                }
            }
            if(st.empty()){
                cout<<"pushing "<<temp<<" "<<i<<endl;
                st.push({temp,i});
            }
        }


        return ans;
    }
};

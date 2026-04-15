using ll = long long;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll product = 1;
        int cnt = 0;
        for(auto elm:nums){
            if(elm == 0)
                cnt++;
            else
                product*=elm;
        }
            
        
        vector<int> ans;
        if(cnt == 0)
            for(auto elm:nums)
                ans.push_back(product/elm);

        if(cnt == 1){
            for(auto elm:nums){
                if(elm)
                    ans.push_back(0);
                else
                    ans.push_back(product);
            }
        }

        if(cnt>1)
            for(auto elm:nums)
                ans.push_back(0);
                
        
        return ans;
    }
};

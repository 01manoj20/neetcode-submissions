using ll = long long;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> st;

        for(auto ch:tokens)
        {
            ll num1,num2;
            if((ch=="+") || (ch=="-") || (ch=="*") || (ch=="/"))
            {
                num1 = st.top(); st.pop();
                num2 = st.top(); st.pop();

                // cout<<num1<<" "<<num2<<endl;

                if(ch == "+")
                    st.push(num1+num2);

                if(ch == "-")
                    st.push(num2-num1);

                if(ch == "/")
                    st.push(num2/num1);

                if(ch == "*")
                    st.push(num1*num2);


            }
            else{
                ll num = stoi(ch);
                st.push(num);
            }         
        }
        
        ll ans = st.top();

        return ans;
    }
};

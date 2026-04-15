class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int l = s.length();

        for(int i=0;i<l;i++)
        {
            if((s[i]=='(') || (s[i] == '[') || (s[i]=='{'))
                st.push(s[i]);
            else
            {   
                if(st.empty())
                    return false;
                    
                char top_char = st.top();

                if(s[i] == ']')
                {
                    if(top_char == '[')
                        st.pop();
                    else
                        return false;
                }

                if(s[i] == '}')
                {
                    if(top_char == '{')
                        st.pop();
                    else
                        return false;
                }

                if(s[i] == ')')
                {
                    if(top_char == '(')
                        st.pop();
                    else
                        return false;
                }

            }
        }

        if(st.empty())
            return true;
        else
            return false;
        
    }
};

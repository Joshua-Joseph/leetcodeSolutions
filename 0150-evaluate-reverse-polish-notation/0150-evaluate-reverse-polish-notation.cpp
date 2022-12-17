class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long long res;
        stack<long long> st;
        
        for(int i=0;i<tokens.size();i++)
        {
            // cout<<i<<" ";
            if(tokens[i] != "+" and tokens[i] != "-" and tokens[i] != "*" and tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                long long second = st.top();
                st.pop();
                long long first = st.top();
                st.pop();
                if(tokens[i] == "+")
                {
                     res = first + second;
                }
                else if(tokens[i] == "-")
                {
                     res = first - second;
                }
                else if(tokens[i] == "*")
                {
                     res = first * second;
                }
                else
                {
                     res = first / second;
                }
                st.push(res);
            }
        }
        // int ans = stoi(st.top());
        return st.top();
    }
};
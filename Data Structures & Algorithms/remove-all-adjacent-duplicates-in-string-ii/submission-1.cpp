class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;

        for(char c : s)
        {
            if(!st.empty() && st.top().first == c)
            {
                st.top().second++; // increase count 
                if(st.top().second == k)
                {
                    st.pop();
                }
            }
            else
            {
                st.push({c,1});
            }
        }

        string result = "";
        while(!st.empty())
        {
            auto [ch , count] = st.top();

            result.append(count , ch);

            st.pop();
        }

        reverse(result.begin() , result.end());
        return result;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;

        string curr = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '[')
            {
                st.push({curr, num});

                curr = "";
                num = 0;
            }
            else if (c == ']')
            {
                string prev = st.top().first;
                int k = st.top().second;
                st.pop();

                for (int i = 0; i < k; i++)
                {
                    prev += curr;
                }

                curr = prev;
            }
            else
            {
                curr += c;
            }
        }

        return curr;
    }
};
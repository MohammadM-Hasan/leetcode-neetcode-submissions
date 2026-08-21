class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size() , 0);
        stack<int> st;

        // monotonic stack (decreasing order)
        for(int i = 0 ; i < temperatures.size() ; i++)
        {
           while(!st.empty() && 
                temperatures[st.top()] < temperatures[i])
                {
                    int index = st.top();
                    st.pop();

                    result[index] = i - index;
                }

                st.push(i);
        }

        return result;
    }
};

class Solution {
public:
    string decodeString(string s) {
        stack<string> strings;
        stack<int> numbers;

        string curr = "";
        int num = 0;

        for(char c : s)
        {
            if(isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if(c == '[')
            {
                strings.push(curr);
                numbers.push(num);

                curr = "";
                num = 0;
            }
            else if(c == ']')
            {
                string prev = strings.top();
                strings.pop();

                int k = numbers.top();
                numbers.pop();

                for(int i = 0 ; i < k ;i++)
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
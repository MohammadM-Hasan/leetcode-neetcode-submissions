class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int counter = 0;
        int ptrSpaces = 0;

        for(char c : s)
        {
            if(ptrSpaces == spaces.size())
                break;
            
            if(counter == spaces[ptrSpaces])
            {
                result += ' ';
                ptrSpaces++;
            }

            counter++;
            result += c;
        }

        if(counter != s.size())
        {
            for(int i = counter ; i < s.size() ; i++)
            {
                result += s[i];
            }
        }

        return result;
    }
};

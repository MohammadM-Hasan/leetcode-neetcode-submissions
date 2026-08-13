class Solution {
public:

    bool isVowel(char c)
    {
        return c == 'a' || c == 'o' || c == 'u' ||
               c == 'e' || c == 'i';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        // 1-indexed array 
        // Take the previous count → then add 1 if the current word is valid.
        vector<int> prefixSumArray(words.size() + 1 , 0);
        
        for(int i = 0 ; i < words.size() ; i++)
        {
            prefixSumArray[i + 1] = prefixSumArray[i];

            if(isVowel(words[i][0]) &&
               isVowel(words[i][words[i].size() - 1]))
            {
                prefixSumArray[i + 1]++;
            }
        }

        vector<int> ans;

        for(const vector<int>& query : queries)
        {
            int left = query[0];
            int right = query[1];

            ans.push_back(
                prefixSumArray[right + 1] - prefixSumArray[left]
            );
        } 

        return ans;
    }
};
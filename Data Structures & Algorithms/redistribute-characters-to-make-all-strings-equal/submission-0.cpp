class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char , int> freq;

        for(string word : words)
        {
            for(char c : word)
            {
                freq[c]++;
            }
        }

        for(auto & f : freq)
        {
            if(f.second % words.size() != 0)
            {
                return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int> freq;

        for(char letter : s)
        {
            freq[letter]++;
        }

        int result = 0;
        bool remainsOdd = false;

        // letter with even frequency is considered , otherwise take only one letter that got odd frequency (but don't forget to take the longest odd)
        for(auto& p : freq)
        {
            if(p.second %2 == 0)
            {
                result += p.second;
            }
            else
            {
                remainsOdd = true;
                result += p.second - 1;
            }
        }

        return remainsOdd ? result + 1 : result;
    }   
};
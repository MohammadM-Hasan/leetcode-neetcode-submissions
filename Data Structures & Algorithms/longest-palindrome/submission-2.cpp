class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        int result = 0;
        bool hasOdd = false;

        for (auto& p : freq) {
            result += p.second / 2 * 2;

            if (p.second % 2 != 0)
                hasOdd = true;
        }

        return result + (hasOdd ? 1 : 0);
    }
};
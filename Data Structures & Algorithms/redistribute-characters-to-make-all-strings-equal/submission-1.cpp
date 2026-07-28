class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26] = {};

        for (const string& word : words) {
            for (char c : word) {
                freq[c - 'a']++;
            }
        }

        for (int count : freq) {
            if (count % words.size() != 0) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    string makeGood(string s) {
        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] + 32 == s[i + 1] ||
                s[i] - 32 == s[i + 1]) {

                s.erase(i, 2);

                if (i != 0)
                    i -= 2;
                else
                    i = -1;
            }
        }

        return s;
    }
};

#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int write = 0; // Pointer to write the compressed character and count
        int i = 0;     // Pointer to traverse the original array
        
        while (i < chars.size()) {
            int j = i;
            // Find the end of the consecutive repeating character group
            while (j < chars.size() && chars[j] == chars[i]) {
                j++;
            }
            
            // 1. Write the character
            chars[write++] = chars[i];
            
            // 2. Write the count if it's greater than 1
            int count = j - i;
            if (count > 1) {
                std::string countStr = std::to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
            
            // Move to the next distinct character group
            i = j;
        }
        
        return write; // The new length of the compressed array
    }
};

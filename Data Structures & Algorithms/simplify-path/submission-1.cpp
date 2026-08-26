class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        string temp;
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (!temp.empty()) {
                    if (temp == "..") {
                        if (!parts.empty()) parts.pop_back();
                    } else if (temp != ".") {
                        parts.push_back(temp);
                    }
                    temp.clear();
                }
            } else {
                temp += path[i];
            }
        }
        
        string result;
        for (auto &p : parts) result += "/" + p;
        return result.empty() ? "/" : result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!temp.empty()) {
                    if (ans.empty())
                        ans = temp;
                    else
                        ans = temp + " " + ans;
                    temp.clear();
                }
            } else {
                temp += s[i];
            }
        }

        return ans;
    }
};
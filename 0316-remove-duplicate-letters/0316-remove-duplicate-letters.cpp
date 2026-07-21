class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> f(26, 0);
        vector<bool> inAns(26, false);
        for (char x : s) f[x - 'a']++;

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            f[s[i] - 'a']--;             
            if (inAns[s[i] - 'a']) continue; 

            while (!ans.empty() && ans.back() > s[i] && f[ans.back() - 'a'] > 0) {
                inAns[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            inAns[s[i] - 'a'] = true;
        }
        return ans;
    }
};
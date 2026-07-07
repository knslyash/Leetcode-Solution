class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        int i = 0;
        int su = 0;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] != '0') {
                s[i++] = s[j];
                su += s[j] - '0';
            }
        }

        s.resize(i);

        if (s.empty())
            return 0;

        return 1LL * stoi(s) * su;
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=t.size()-1;
        if(s.empty()) return true;
        while(i>=0){
            if(s.back()==t[i]){
                s.pop_back();
            }
            if(s.empty()) return true;
            i--;
        }
        return s.empty();
    }
};
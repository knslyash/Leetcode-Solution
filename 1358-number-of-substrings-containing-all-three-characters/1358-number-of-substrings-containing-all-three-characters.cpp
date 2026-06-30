class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> f(3,0);
        int l=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') f[0]++;
            else if(s[i]=='b') f[1]++;
            else f[2]++;
            while(f[0] && f[1] && f[2]){
                ans+=s.size()-i;
            if(s[l]=='a') f[0]--;
            else if(s[l]=='b') f[1]--;
            else f[2]--;
                l++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxDistance(string s) {
        int a=0;
        int b=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') a-=1;
            else if(s[i]=='U')b+=1;
            else if(s[i]=='D')b-=1;
            else  if(s[i]=='R')a+=1;
            else ans++;
        }
        ans+=abs(a)+abs(b);
        return ans;
    }
};
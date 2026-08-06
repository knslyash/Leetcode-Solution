class Solution {
public:
    int getdigit(int n){
        int p=1;
        
        while(n>1){
            p*=n%10;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<n*t;i++){
            int d=getdigit(i);
            if(d%t==0){
                return i;
            }
        }
        return n*t;
    }
};
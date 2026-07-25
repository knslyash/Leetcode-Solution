class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        while(left<right){
            if(st.count(s[left]) && st.count(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if( st.count(s[left])){
                    right--;
            }
            else if( st.count(s[right])){
                left++;
            }
            else{
                left++;
                right--;
            }
        }
        return s;
    }
};
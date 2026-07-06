class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st;
        for( string c: wordList)
            st.insert(c);
        q.push({beginWord,1});
        int l=beginWord.size();
        while(q.size()){
            auto p=q.front();
            string word=p.first;
            int s=p.second;
            q.pop();
            if(word==endWord) return s;
            for(int i=0;i<l;i++){
                char original=word[i];
                for(char x='a';x<='z';x++){
                    word[i]=x;
                    if(st.find(word)!=st.end()){
                        q.push({word,s+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
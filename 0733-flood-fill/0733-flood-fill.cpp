class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color,int value){
        int r=image.size();
        int c=image[0].size();
        if(i<0 ||j<0 || i>=r ||j>=c || image[i][j]!=value){
            return;
        }
        image[i][j]=color;
        dfs(image,i,j-1,color,value);
        dfs(image,i,j+1,color,value);
        dfs(image,i+1,j,color,value);
        dfs(image,i-1,j,color,value);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int v=image[sr][sc];
        if(v==color){
            return image;
        }
        dfs(image,sr,sc,color,v);
        return image;
    }
};
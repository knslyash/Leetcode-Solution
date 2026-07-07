class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for( auto c:prerequisites){
            int u=c[1];
            int v=c[0];
            adj[u].push_back(v);
            indegree[v]++;

        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(q.size()){
            int node=q.front();
            q.pop();
            c++;
            for(int nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }

       return c==numCourses;

    }
};
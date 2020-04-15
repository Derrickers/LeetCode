class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> empty;
        int indegree[numCourses];
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        for(int i = 0;i<numCourses;i++)
            indegree[i] = 0;
        for(int i = 0;i<prerequisites.size();i++){
            int pre = prerequisites[i][1],p = prerequisites[i][0];
            indegree[p]++;
            graph[pre].push_back(p);
        }
        for(int i = 0;i<numCourses;i++)
            if(indegree[i] == 0)
                q.push(i);
        int courses = 0;
        while(!q.empty()){
            courses++;
            int c = q.front();
            q.pop();
            res.push_back(c);
            for(int i = 0;i<graph[c].size();i++){
                indegree[graph[c][i]]--;
                if(indegree[graph[c][i]] == 0)
                    q.push(graph[c][i]);
            }
        }
        return courses==numCourses?res:empty;
    }
};
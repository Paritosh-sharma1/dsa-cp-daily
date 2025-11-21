Link: https://leetcode.com/problems/path-with-minimum-effort/description/



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        priority_queue<
            pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({0, {0,0}});
        dist[0][0] = 0;

        int delrow[4] = {-1,0,0,1};
        int delcol[4] = {0,1,-1,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) return diff;  // best path reached

            for(int i=0;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newDiff = max(diff, abs(heights[r][c] - heights[nr][nc]));

                    if(newDiff < dist[nr][nc]){
                        dist[nr][nc] = newDiff;
                        pq.push({newDiff, {nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

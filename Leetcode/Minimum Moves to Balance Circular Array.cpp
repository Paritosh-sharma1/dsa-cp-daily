
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long totalSum = 0;
        int n = balance.size();
        int targetIdx = -1;
        long long deficit = 0;
        for(int i = 0; i < n; i++) {
            totalSum += balance[i];
            if(balance[i] < 0) {
                targetIdx = i;
                deficit = -1LL * balance[i];
            }
        }
        if(totalSum < 0) {
            return -1;
        }

        if(targetIdx == -1) {
            return 0;
        }
        vector<pair<int, int>> sources;

        for(int i = 0; i < n; i++) {
            if(balance[i] > 0) {
                int rawDist = abs(targetIdx - i);
                int circularDist = min(rawDist, n - rawDist);
                sources.push_back({circularDist, balance[i]});
            }
        }

        sort(sources.begin(), sources.end());

        long long minimumMovesRequired = 0;

        for(int i = 0; i < sources.size(); i++) {
            int dist = sources[i].first;
            int available = sources[i].second;

            long long take = min((long long)available, deficit);
            
            minimumMovesRequired += (take * dist);
            
            deficit -= take;

            if(deficit == 0) break;
        }

        return minimumMovesRequired;
    }
};
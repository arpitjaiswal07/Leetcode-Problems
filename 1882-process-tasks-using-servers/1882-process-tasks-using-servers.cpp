class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> used;
        
        for (int i = 0; i < servers.size(); ++i) {
            free.push({servers[i], i});
        }
        
        vector<int> ans;
        long long currTime = 0;
        
        for (int i = 0; i < tasks.size(); ++i) {
            currTime = max(currTime, (long long)i);
            
            if (free.empty()) {
                currTime = get<0>(used.top());
            }
            
            while (!used.empty() && get<0>(used.top()) <= currTime) {
                auto [freeTime, weight, idx] = used.top();
                used.pop();
                free.push({weight, idx});
            }
            
            auto [weight, idx] = free.top();
            free.pop();
            
            ans.push_back(idx);
            used.push({currTime + tasks[i], weight, idx});
        }
        
        return ans;
    }
};
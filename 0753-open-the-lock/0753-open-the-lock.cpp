class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1; 

        queue<pair<string,int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while (!q.empty()) {
            auto f = q.front();
            string curr=f.first;
            int turn=f.second;
            q.pop();

            if (curr == target) return turn;

            for (int i = 0; i < 4; i++) {
                string next = curr;
                next[i] = (curr[i] - '0' + 1) % 10 + '0';
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, turn + 1});
                }
                next[i] = (curr[i] - '0' + 9) % 10 + '0';
                if (!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, turn + 1});
                }
            }
        }

        return -1;
    }
};

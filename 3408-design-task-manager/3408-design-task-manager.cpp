class TaskManager {
public:
    priority_queue<pair<pair<int, int>, int>> mx;
    unordered_map<int, pair<int, int>> mp; 

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int user = t[0];
            int task = t[1];
            int pr = t[2];
            add(user, task, pr); 
        }
    }

    void add(int userId, int taskId, int priority) {
        mx.push({{priority, taskId}, userId});
        mp[taskId] = {priority, userId};
    }

    void edit(int taskId, int newPriority) {
       
        int userId = mp[taskId].second;

        mp[taskId] = {newPriority, userId};

        mx.push({{newPriority, taskId}, userId});
    }

    void rmv(int taskId) {
       mp.erase(taskId);
    }

    int execTop() {
        while (!mx.empty()) {
            auto top = mx.top();
            int priority = top.first.first;
            int taskId = top.first.second;
            int userId = top.second;

            if (mp.find(taskId) != mp.end() && mp[taskId].first == priority) {
               
                mp.erase(taskId);
                mx.pop();
                return userId;
            } else {
               
                mx.pop();
            }
        }

       return -1;
    } 
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
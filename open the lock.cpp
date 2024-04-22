class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<pair<string, int>> bfsQueue;

    string start = "0000";
    if (dead.find(start) != dead.end()) {
        return -1;
    }

    bfsQueue.push(make_pair(start, 0));
    visited.insert(start);

    while (!bfsQueue.empty()) {
        auto current = bfsQueue.front();
        string currentLock = current.first;
        int currentSteps = current.second;
        bfsQueue.pop();

        if (currentLock == target) {
            return currentSteps;
        }

        for (int i = 0; i < 4; ++i) {
            string next1 = currentLock, next2 = currentLock;
            next1[i] = (next1[i] == '9') ? '0' : next1[i] + 1;
            next2[i] = (next2[i] == '0') ? '9' : next2[i] - 1;

            if (visited.find(next1) == visited.end() && dead.find(next1) == dead.end()) {
                visited.insert(next1);
                bfsQueue.push(make_pair(next1, currentSteps + 1));
            }
            if (visited.find(next2) == visited.end() && dead.find(next2) == dead.end()) {
                visited.insert(next2);
                bfsQueue.push(make_pair(next2, currentSteps + 1));
            }
        }
    }

    return -1;
        
    }
};

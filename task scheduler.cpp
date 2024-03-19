class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char, int> taskCounts;
    for (char task : tasks) {
        taskCounts[task]++;
    }

    // Find the maximum frequency
    int maxFreq = 0;
    for (auto& task : taskCounts) {
        maxFreq = max(maxFreq, task.second);
    }

    // Count how many tasks have the maximum frequency
    int maxCount = 0;
    for (auto& task : taskCounts) {
        if (task.second == maxFreq) {
            maxCount++;
        }
    }

    // Calculate the minimum intervals required
    int partCount = maxFreq - 1; // Number of full parts, excluding the last one
    int partLength = n - (maxCount - 1); // The length of each part, adjusted for multiple max tasks
    int emptySlots = partCount * partLength; // Total number of empty slots
    int availableTasks = tasks.size() - (maxFreq * maxCount); // Total tasks minus the most frequent ones
    int idles = max(0, emptySlots - availableTasks); // Calculate the idles needed

    return tasks.size() + idles;
        
    }
};

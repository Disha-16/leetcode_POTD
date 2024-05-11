class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
    vector<pair<double, int>> worker;
    for (int i = 0; i < n; ++i) {
        worker.emplace_back((double)wage[i] / quality[i], quality[i]);
    }
    // Sort workers by their wage to quality ratio
    sort(worker.begin(), worker.end());

    double minCost = 1e9, qualitySum = 0;
    // Max heap to store and remove the largest qualities to maintain the k smallest qualities
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; ++i) {
        double ratio = worker[i].first;
        int qual = worker[i].second;

        qualitySum += qual;
        maxHeap.push(qual);

        if (maxHeap.size() > k) {
            qualitySum -= maxHeap.top(); // Remove the largest quality to keep only k
            maxHeap.pop();
        }

        // Calculate the minimum cost when we have exactly k workers in the heap
        if (maxHeap.size() == k) {
            minCost = min(minCost, qualitySum * ratio);
        }
    }

    return minCost;
        
    }
};

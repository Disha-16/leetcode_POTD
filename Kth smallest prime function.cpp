class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
         auto comp = [&arr](pair<int, int> a, pair<int, int> b) {
        return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    int n = arr.size();
    // Push all fractions with the first element (1) as numerator
    for (int j = 1; j < n; ++j) {
        pq.push({0, j});
    }

    // Extract the smallest k times
    for (int count = 1; count < k; ++count) {
        auto smallest = pq.top();
        pq.pop();
        int i = smallest.first;
        int j = smallest.second;

        if (i + 1 < j) {
            pq.push({i + 1, j});
        }
    }

    // The k-th smallest fraction
    pair<int, int> kth = pq.top();
    return {arr[kth.first], arr[kth.second]};
    }
};

class Solution {
public:
    string customSortString(string order, string s) {
         unordered_map<char, int> orderMap;
    for (int i = 0; i < order.size(); ++i) {
        orderMap[order[i]] = i;
    }

    // Sorting 's' based on the order defined in 'order'
    // Characters not in 'order' are placed at the end as per their ASCII values
    sort(s.begin(), s.end(), [&orderMap](const char &a, const char &b) {
        auto it_a = orderMap.find(a), it_b = orderMap.find(b);
        if (it_a != orderMap.end() && it_b != orderMap.end()) {
            return it_a->second < it_b->second;
        } else if (it_a != orderMap.end()) {
            return true; // 'a' is in 'order' and 'b' is not
        } else if (it_b != orderMap.end()) {
            return false; // 'b' is in 'order' and 'a' is not
        }
        return a < b; // Neither 'a' nor 'b' is in 'order', maintain original order
    });

    return s;
        
    }
};

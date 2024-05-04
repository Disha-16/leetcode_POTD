class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
    
    int i = 0;                      // Start pointer for the lightest person
    int j = people.size() - 1;      // End pointer for the heaviest person
    int boats = 0;                  // Count of boats used
    
    while (i <= j) {
        // Check if the lightest and the heaviest person can share the same boat
        if (people[i] + people[j] <= limit) {
            i++;  // Lightest person now accounted for
        }
        j--;      // Heaviest person now accounted for
        boats++;   // One more boat is used
    }
    
    return boats;
        
    }
};

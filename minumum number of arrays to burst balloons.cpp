class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty()) return 0;
    
    // Sort the balloons by their end positions
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int arrows = 1;
    int arrowPos = points[0][1]; // Position to shoot the first arrow
    
    for (const vector<int>& balloon : points) {
        // If the start of the current balloon is greater than the arrow position,
        // it means the current arrow cannot burst this balloon. Shoot a new arrow.
        if (balloon[0] > arrowPos) {
            arrows++;
            arrowPos = balloon[1]; // Update the arrow position to the end of the current balloon
        }
    }
    
    return arrows;
        
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
    for (int i = 0; i < tickets.size(); ++i) {
        if (i <= k) {
            // For people before and including person k, 
            // we add the minimum of their ticket count or the ticket count of person k.
            time += min(tickets[i], tickets[k]);
        } else {
            // For people after person k, 
            // we add the minimum of their ticket count or one less than the ticket count of person k 
            // (since person k would finish buying their last ticket before these people get to buy their nth ticket).
            time += min(tickets[i], tickets[k] - 1);
        }
    }
    return time;
        
    }
};

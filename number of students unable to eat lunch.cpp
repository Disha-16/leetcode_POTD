class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        for (int student : students) {
            studentQueue.push(student);
        }

        int sandwichIndex = 0;
        int stepsWithoutEating = 0; // Counter to track the number of steps nobody eats a sandwich.

        while (!studentQueue.empty() && stepsWithoutEating < studentQueue.size()) {
            if (studentQueue.front() == sandwiches[sandwichIndex]) {
                // The student at the front takes the sandwich and leaves.
                studentQueue.pop();
                ++sandwichIndex;
                stepsWithoutEating = 0; // Reset the counter since someone ate.
            } else {
                // The student at the front doesn't like the sandwich, moves to the end of the line.
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                ++stepsWithoutEating;
            }
        }

        // The remaining number of students in the queue are unable to eat.
        return studentQueue.size();
        
    }
};

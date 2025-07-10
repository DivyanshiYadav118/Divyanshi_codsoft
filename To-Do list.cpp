#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to hold description and status
struct Task {
    string description;
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice;

    cout << "Welcome to your Simple To-Do List Manager! \n";

    while (true) {
        // Show menu
        cout << "\n------------------------------------\n";
        cout << "What would you like to do?\n";
        cout << "1  Add a new task\n";
        cout << "2  View all tasks\n";
        cout << "3  Mark a task as completed\n";
        cout << "4  Delete a task\n";
        cout << "5  Exit\n";
        cout << "Please enter your choice (1-5): ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore(); // clear input buffer
            string desc;
            cout << "Enter your task description: ";
            getline(cin, desc);
            tasks.push_back({desc, false});
            cout << " Task added successfully!\n";
        } 
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << " Your to-do list is empty. Add some tasks!\n";
            } else {
                cout << " Here are your tasks:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i].description 
                         << " [" << (tasks[i].completed ? " Completed" : " Pending") << "]\n";
                }
            }
        } 
        else if (choice == 3) {
            int num;
            cout << "Enter the task number to mark as completed: ";
            cin >> num;
            if (num >= 1 && num <= tasks.size()) {
                tasks[num - 1].completed = true;
                cout << " Task marked as completed!\n";
            } else {
                cout << " Invalid task number. Please try again.\n";
            }
        } 
        else if (choice == 4) {
            int num;
            cout << "Enter the task number to delete: ";
            cin >> num;
            if (num >= 1 && num <= tasks.size()) {
                tasks.erase(tasks.begin() + num - 1);
                cout << " Task deleted!\n";
            } else {
                cout << " Invalid task number. Please try again.\n";
            }
        } 
        else if (choice == 5) {
            cout << " Thank you for using the To-Do List Manager. Goodbye!\n";
            break;
        } 
        else {
            cout << " Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
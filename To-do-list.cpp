#include <iostream>
#include <vector>

using namespace std;

class Task {
public:
    Task(string description, string status = "pending") : description(description), status(status) {}

    string get_description() { return description; }
    string get_status() { return status; }

    void set_status(string status) { this->status = status; }

private:
    string description;
    string status;
};

class TaskList {
public:
    void add_task(Task task) { tasks.push_back(task); }
    void view_tasks() {
        cout << "To-do list:\n";
        for (Task task : tasks) {
            cout << task.get_description() << " (" << task.get_status() << ")\n";
        }
    }
    void mark_task_as_completed(int task_index) { tasks[task_index].set_status("completed"); }
    void remove_task(int task_index) { tasks.erase(tasks.begin() + task_index); }

private:
    vector<Task> tasks;
};

string input_task() {
    cout << "Task description: ";
    string description;
    cin >> description;
    return description;
}

int main() {
    TaskList task_list;

    while (true) {
        cout << "> ";
        string command;
        cin >> command;

        if (command == "add") {
            string description = input_task();
            Task task(description);
            task_list.add_task(task);
        } else if (command == "view") {
            task_list.view_tasks();
        } else if (command == "mark_as_completed") {
            int task_index;
            cout << "Task index to mark as completed: ";
            cin >> task_index;
            task_list.mark_task_as_completed(task_index);
        } else if (command == "remove") {
            int task_index;
            cout << "Task index to remove: ";
            cin >> task_index;
            task_list.remove_task(task_index);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command\n";
        }
    }

    return 0;
}
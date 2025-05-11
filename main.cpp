#include <iostream>
#include <vector>
#include <string>

using namespace std;

// TODO: define Task
struct Task {
    string name;
    bool completed;
    string details;
    string dueDate;
    string priority;
    string type;
};

// TODO: function declaration
void addTask(vector<Task>& tasks){
    Task newTask;
    while (newTask.name.empty()){
        cout << "Enter the name or title of the task: ";
        getline(cin, newTask.name);
    }
    cout << "Enter the task details: ";
    getline(cin, newTask.details);
    cout << "When is the task due? ";
    getline(cin, newTask.dueDate);
    cout << "Enter the task priority (high, medium, low): ";
    getline(cin, newTask.priority);
    cout << "Enter the task type (work, school, personal, other): ";
    getline(cin, newTask.type);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks){
    if (tasks.empty()) {
        cout << "You have no tasks!" << endl;
        return;
    }
    for (int i = 0; i < tasks.size(); ++i) {
        cout << tasks[i].name << endl;
        if(!tasks[i].details.empty()){
            cout << "Details: " << tasks[i].details << endl;
        }
        if (!tasks[i].dueDate.empty()){
            cout << "Due Date: " << tasks[i].dueDate << endl;
        }
        cout << tasks[i].priority << " Priority" << endl;
        if (!tasks[i].type.empty()){
            cout << "Type: " << tasks[i].type << endl;
        }
        cout << (tasks[i].completed ? "Completed" : "Not Completed") << endl;
        cout << endl;
    }
}

void viewTask(const vector<Task>& task, int index){
    cout << "(1) Name: " << task[index].name << endl;
    cout << "(2) Details: " << (task[index].details.empty() ? "[empty]" : task[index].details) << endl;
    cout << "(3) Type: " << (task[index].type.empty() ? "[empty]" : task[index].type) << endl;
    cout << "(4) Priority: " << (task[index].priority.empty() ? "[empty]" : task[index].priority) << endl;
    cout << "(5) Due Date: " << (task[index].dueDate.empty() ? "[empty]" : task[index].dueDate) << endl;
    cout << "(6) Status: " << (task[index].completed ? "Completed" : "Not Completed") << endl;
}

void updateTask(vector<Task>& tasks, int index, int fieldIndex, string newValue){
    
}

void editTask(const vector<Task>& task, int index){
    int fieldIndex = -1;
    string newValue;
    viewTask(task, index);
    cout << "(0) [cancel]" << endl;
    while(fieldIndex < 0 || fieldIndex > 6){
        cout << "Select which field to edit: ";
        cin >> fieldIndex;
        cin.ignore();
    }
    
    if (fieldIndex == 0) {
        cout << "canceled edit" << endl;
        return;
    }
    cout << "(0) [cancel]" << endl;
    if (fieldIndex == 1) {
        while (newValue.empty()){
            cout << "Enter the new name or title of the task: ";
            getline(cin, newValue);
        }
    }
    else if (fieldIndex == 2) {

    }
    else if (fieldIndex == 3) {

    }
    else if (fieldIndex == 4) {

    }
    else if (fieldIndex == 5) {

    }
    else if (fieldIndex == 6) {

    }
}

main() {
    viewTasks(); // TODO: only view non-completed tasks
}

// TODO: Function definitions
/*
    addTask
    viewTasks
    updateTask
    deleteTask
*/
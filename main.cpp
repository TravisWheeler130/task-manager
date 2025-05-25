#include <iostream>
#include <vector>
#include <string>

using namespace std;

// TODO: define Task
struct Task {
    string name;
    bool completed;
    string details;
    string priority;
    string type;
};

// TODO: function declaration
string selectPriority() {
    int priorityChoice = 0;
    while (priorityChoice < 1 || priorityChoice > 3){
        cout << "Set task priority:\n(1) HIGH\n(2) MEDIUM\n(3) LOW" << endl;
        cin >> priorityChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            priorityChoice = 0;
        } else {
            cin.ignore();
        }
    }
    if (priorityChoice == 1){return "HIGH";}
    else if (priorityChoice == 2){return "MEDIUM";}
    else {return "LOW";}
}

string selectType() {
    int typeChoice = 0;
    while (typeChoice < 1 || typeChoice > 4) {
        cout << "Set task type:\n(1) Work\n(2) School\n(3) Personal\n(4) Other" << endl;
        cin >> typeChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            typeChoice = 0;
        } else {
            cin.ignore();
        }
    }
    if (typeChoice == 1){return "Work";}
    else if (typeChoice == 2){return "School";}
    else if (typeChoice == 3){return "Personal";}
    else {return "Other";}
}

int selectMenu() {
    int menuChoice = -1;
    while (menuChoice < 0 || menuChoice > 2) {
        cout << "Menu:\n" << "(1) Add Task\n(2) View Task\n(0) Exit" << endl;
        cin >> menuChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            menuChoice = -1;
        } else {
            cin.ignore();
        }
    }
    return menuChoice;
}

void toggleCompleted(Task& task) {
    task.completed = !task.completed;
}

void addTask(vector<Task>& tasks){
    Task newTask;
    while (newTask.name.empty()){
        cout << "Enter the name or title of the task: ";
        getline(cin, newTask.name);
    }
    cout << "Enter the task details: ";
    getline(cin, newTask.details);
    newTask.priority = selectPriority();
    newTask.type = selectType();
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
        cout << "\n#" << i << ": " << tasks[i].name << endl;
        if(!tasks[i].details.empty()){
            cout << "Details: " << tasks[i].details << endl;
        }
        cout << tasks[i].priority << " Priority" << endl;
        cout << "Type: " << tasks[i].type << endl;
        cout << (tasks[i].completed ? "Completed" : "Not Completed") << endl;
        cout << endl;
    }
}

void viewTask(const Task& task, bool edit){
    if (edit) {
        cout << "(1) Name: " << task.name << endl;
        cout << "(2) Details: " << (task.details.empty() ? "[empty]" : task.details) << endl;
        cout << "(3) Priority: " << task.priority << endl;
        cout << "(4) Type: " << task.type << endl;
        cout << "(5) Status: " << (task.completed ? "Completed" : "Not Completed") << endl;
    } else {
        cout << "Name: " << task.name << endl;
        cout << "Details: " << (task.details.empty() ? "[empty]" : task.details) << endl;
        cout << "Priority: " << task.priority << endl;
        cout << "Type: " << task.type << endl;
        cout << "Status: " << (task.completed ? "Completed" : "Not Completed") << endl;
    }
}

void updateTask(Task& task, int fieldIndex, string newValue){
    switch(fieldIndex) {
        case 1: task.name = newValue; break;
        case 2: task.details = newValue; break;
        case 3: task.priority = newValue; break;
        case 4: task.type = newValue; break;
        case 5: break;
        default: cout << "Invalid field index.\n";
    }
}

void editTask(Task& task){
    int fieldIndex = -1;
    string newValue;
    viewTask(task, true);
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
    if (fieldIndex == 1) { // name
        while (newValue.empty()){
            cout << "Enter the new name or title of the task: ";
            getline(cin, newValue);
        }
    }
    else if (fieldIndex == 2) { // details
        int addReplace = -1;
        while (addReplace < 0 || addReplace > 2) {
            cout << task.details << endl;
            cout << "(1) [Add Details]" << endl;
            cout << "(2) [Replace Details]" << endl;
            cout << "(0) [cancel]" << endl;
            cin >> addReplace;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                addReplace = -1;
            } else {
                cin.ignore();
            }
        }
        if (addReplace == 1) {
            cout << "Enter additional details: " << endl;
            getline(cin, newValue);
            newValue = task.details + "\n" + newValue;
        } else if (addReplace == 2) {
            cout << "Enter the task details: " << endl;
            getline(cin, newValue);
        } else if (addReplace == 0) {
            cout << "canceled edit" << endl;
            return;
        }
    }
    else if (fieldIndex == 3) { // priority
        newValue = selectPriority();
    }
    else if (fieldIndex == 4) { // type
        newValue = selectType();
    }
    else if (fieldIndex == 5) { // status
        toggleCompleted(task);
        return;
    }
    updateTask(task, fieldIndex, newValue);
    cout << "Task updated successfully!" << endl;
}

void deleteTask(vector<Task>& tasks, int index) {
    cout << "Are you sure you want to delete the task: \"" << tasks[index].name << "\"? (y/n): ";
    char confirm;
    cin >> confirm;
    cin.ignore();

    if (confirm == 'y' || confirm == 'Y') {
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted." << endl;
    } else {
        cout << "Task saved." << endl;
    }
}


int main() {
    vector<Task> tasks;
    while (true) {
        viewTasks(tasks); // TODO: only view non-completed tasks
        int menu = selectMenu();
        if (menu == 1) {
            addTask(tasks);
        } else if (menu == 2) {
            int index = -1;
            cout << "Enter task number to view: ";
            cin >> index;
            cin.ignore();

            if (index >= 0 && index < tasks.size()) {
                viewTask(tasks[index], false);
                int action;
                cout << "(1) Edit\n(2) Toggle Completed\n(3) Delete\n(0) Go Back" << endl;
                cin >> action;
                cin.ignore();

                if (action == 1) {
                    editTask(tasks[index]);
                } else if (action == 2) {
                    toggleCompleted(tasks[index]);
                } else if (action == 3) {
                    deleteTask(tasks, index);
                }
            } else {
                cout << "Invalid task number." << endl;
            }
        } else {break;}
    } return 0;
}
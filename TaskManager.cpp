#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void newTask(string newName, string newSymbol, string newDesc, int newPriority);
void markAsDone(int req);
void showCurrentTask();
void showAllTasks();
void changePriority(int req);
void deleteTask(int req);
void deleteAllTasks();
bool checkSymbol(string s);
bool checkPriority(int pr);
void updateTaskList();

class task {
private:
    string name, symbol, desc;
    int priority;
public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setSymbol(string s) {
        symbol = s;
    }

    string getSymbol() {
        return symbol;
    }

    void setDesc(string d) {
        desc = d;
    }

    string getDesc() {
        return desc;
    }

    void setPriority(int p) {
        priority = p;
    }

    int getPriority() {
        return priority;
    }
};

vector<task> taskList;

int main()
{
    int tmp;

    cout << "___________________Task Manager____________________" << endl;
    cout << "___________________BY WHEESKEEY____________________\n" << endl;
    cout << "1] New task" << endl;
    cout << "2] Mark as done" << endl;
    cout << "3] Show current task" << endl;
    cout << "4] Show all tasks" << endl;
    cout << "5] Change priority" << endl;
    cout << "6] Exit\n" << endl;
    cout << "_________!!!DANGER ZONE!!!_________\n" << endl;
    cout << "7] Delete task" << endl;
    cout << "8] Delete all tasks\n" << endl;
    cout << "_________Dev tools_________\n" << endl;
    cout << "9] Update task list\n" << endl;
    cout << ": ";
    cin >> tmp;

    switch (tmp) {
    case 1:
    {
        system("cls");
        string taskName, taskSymbol, taskDesc;
        int taskPriority;
        cout << "-----------------------------------------" << endl;
        cout << "Task name: ";
        cin >> taskName;
        cout << "Task symbol (A-Z, eg. BC): ";
        cin >> taskSymbol;
        cout << "Task description: ";
        cin >> taskDesc;
        cout << "Task priority (1-5; 1 meaning urgent, 5 meaning irrelevant): ";
        cin >> taskPriority;
        if (!checkSymbol(taskSymbol) || !checkPriority(taskPriority)) {
            cout << "Input incorrect. Check following:" << endl << "- symbol is made out of 2 letters and is A-Z" << endl << 
                "- there are no letters put into priority" << endl << "- priority is not a negative number" << endl;
        }
        else {
            newTask(taskName, taskSymbol, taskDesc, taskPriority);
            cout << "New task added!" << endl;
        }
        system("pause");
        system("cls");
        main();
        break;
    }
    case 2:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        markAsDone(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 3:
        system("cls");
        showCurrentTask();
        system("pause");
        system("cls");
        main();
        break;
    case 4:
        system("cls");
        showAllTasks();
        system("pause");
        system("cls");
        main();
        break;
    case 5:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        changePriority(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 6:
        return 0;
        break;
    case 7:
    {
        int req;
        system("cls");
        cout << "Task id: ";
        cin >> req;
        deleteTask(req);
        system("pause");
        system("cls");
        main();
        break;
    }
    case 8:
        system("cls");
        deleteAllTasks();
        system("pause");
        system("cls");
        main();
        break;
    case 9:
        updateTaskList();
        cout << "Done" << endl;
        system("pause");
        system("cls");
        main();
        break;
    default:
        cout << "Err" << endl;
        main();
        break;
    }

    return 0;
}

void newTask(string newName, string newSymbol, string newDesc, int newPriority) {
    task tmpTask;
    tmpTask.setName(newName);
    tmpTask.setSymbol(newSymbol);
    tmpTask.setDesc(newDesc);
    tmpTask.setPriority(newPriority);

    taskList.push_back(tmpTask);
    updateTaskList();
}

void markAsDone(int req) {
    if ((req > taskList.size()) || (req < 0)) {
        cout << "Task with provided id wasn't found" << endl;
        system("pause");
        system("cls");
    }
    else {
        string tmp;
        task currentTask;
        try {
            currentTask = taskList.at(req);
        }
        catch (const out_of_range& e) {
            cout << "Task with provided id wasn't found" << endl;
            system("pause");
            system("cls");
            main();
        }
        
        cout << "Name: " << currentTask.getName() << endl;
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << endl << "Description: " << currentTask.getDesc() << endl;
        cout << "Priority: " << currentTask.getPriority() << endl;

        cout << "Is this the task that you want to mark as done? (y/n): ";
        cin >> tmp;

        if ((tmp == "y") || (tmp == "yes")) {
            taskList.at(req).setPriority(6);
            taskList.at(req).setDesc("| DONE | " + taskList.at(req).getDesc());
            updateTaskList();
        }
        else if ((tmp == "n") || (tmp == "no")) {
            main();
        }
    }
}

void showCurrentTask() {
    if (taskList.size() <= 0) {
        cout << "There are no tasks at the moment" << endl;
    }
    else {
        task currentTask = taskList.front();
        cout << "Name: " << currentTask.getName() << endl;
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << endl << "Description: " << currentTask.getDesc() << endl;
        cout << "Priority: " << currentTask.getPriority() << endl;
    }
}

void showAllTasks() {
    for (int i = 0; i < taskList.size(); i++) {
        task currentTask = taskList.at(i);
        cout << i << "]" << endl;
        cout << "Name: " << currentTask.getName() << endl;
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << endl << "Description: " << currentTask.getDesc() << endl;
        cout << "Priority: " << currentTask.getPriority() << endl;
    }
}

void changePriority(int req) {
    if ((req > taskList.size()) || (req < 0)) {
        cout << "Task with provided id wasn't found" << endl;
        system("pause");
        system("cls");
    }
    else {
        int newPriority;
        task currentTask;
        try {
            currentTask = taskList.at(req);
        }
        catch (const out_of_range& e) {
            cout << "Task with provided id wasn't found" << endl;
            system("pause");
            system("cls");
            main();
        }
        
        cout << "Name: " << currentTask.getName() << endl;
        cout << "Symbol: ";
        for (int i = 0; i < currentTask.getSymbol().size(); i++) {
            putchar(toupper(currentTask.getSymbol()[i]));
        }
        cout << endl << "Description: " << currentTask.getDesc() << endl;
        cout << "Priority: " << currentTask.getPriority() << endl;
        
        cout << endl << "Change priority to? (1-5): ";
        cin >> newPriority;
        taskList.at(req).setPriority(newPriority);
        updateTaskList();
    }
}

void deleteTask(int req) {
    string tmp;
    task currentTask;
    try {
        currentTask = taskList.at(req);
    }
    catch (const out_of_range& e) {
        cout << "Task with provided id wasn't found" << endl;
        system("pause");
        system("cls");
        main();
    }

    cout << "Name: " << currentTask.getName() << endl;
    cout << "Symbol: ";
    for (int i = 0; i < currentTask.getSymbol().size(); i++) {
        putchar(toupper(currentTask.getSymbol()[i]));
    }
    cout << endl << "Description: " << currentTask.getDesc() << endl;
    cout << "Priority: " << currentTask.getPriority() << endl;

    cout << "Are you sure? (y/n): ";
    cin >> tmp;

    if ((tmp == "y") || (tmp == "yes")) {
        taskList.erase(taskList.begin() + req);
        updateTaskList();
    }
    else if ((tmp == "n") || (tmp == "no")) {
        main();
    }
}

void deleteAllTasks() {
    if (taskList.size() <= 0) {
        cout << "There are no tasks at the moment" << endl;
    }
    else {
        taskList.clear();
    }
}

bool checkSymbol(string s) {
    if (s.size() == 2) {
        for (int i = 0; i < s.size(); i++) {
            if (((s[i] >= 65) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122))) {
                return true;
            }
        }
    }
    return false;
}

bool checkPriority(int pr) {
    if ((pr >= 1) && (pr <= 5)) {
        return true;
    }
    else {
        return false;
    }
}

void updateTaskList() {
    sort(taskList.begin(), taskList.end(),
        [](task a, task b) {
        return a.getPriority() < b.getPriority();
    });
}
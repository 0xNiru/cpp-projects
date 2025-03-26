#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

void readList() {
    string line;
    ifstream myfile("todo.txt");
    if (myfile.is_open()) {
        int taskNum = 1;
        while (getline(myfile, line)) {
            cout << taskNum << ". " << line << '\n';
            taskNum++;
        }
        myfile.close();
        if (taskNum == 1) {
            cout << "No tasks in the list!\n";
        }
    } else {
        cout << "Unable to open file\n";
    }
}

void addList(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "No task provided...\n";
        return;
    }

    ofstream myfile("todo.txt", ios::app);
    if (myfile.is_open()) {
        for (int i = 2; i < argc; i++) {
            myfile << argv[i] << " ";
        }
        myfile << "\n";
        myfile.close();
    }
    cout << "Task added successfully...\n";
    readList();
}

void remList(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "ERROR: Please provide the task number to remove\n";
        return;
    }
    int taskIndex = stoi(argv[2]);

    ifstream myfile("todo.txt");
    vector<string> tasks;
    string line;

    while(getline(myfile, line)) {
        tasks.push_back(line);
    }
    myfile.close();

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "ERROR: Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskIndex - 1);

    ofstream outFile("todo.txt");
    for (const string& task : tasks) {
        outFile << task << "\n";
    }
    outFile.close();
    cout << "Task " << taskIndex << " removed successfully...\n";
    readList();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        readList();
        return 0;
    }

    if (strcmp(argv[1], "list") == 0) {
        readList();
    } else if (strcmp(argv[1], "add") == 0) {
        addList(argc, argv);
    } else if (strcmp(argv[1], "rem") == 0) {
        remList(argc, argv);
    } else {
        cout << "Invalid command! use : list | add \"task\" | rem <index>\n";
    }

    return 0;
}

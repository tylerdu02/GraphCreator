/*
* Tyler Du
* 6/7/23
* Graph Creator
*/

#include <iostream>
#include <cstring>

struct Node{
    char* name;
    Node(char* newName) {
        name = newName;
    }
};

void addVertex(Node** List, int graphTable[21][21]);
void removeVertex(Node** List, int graphTable[21][21]);
void addEdge(Node** List, int graphTable[21][21]);
void removeEdge(Node** List, int graphTable[21][21]);
void print(int graphTable[21][21]);

using namespace std;

int main() {
    int input;
    bool running = true;

    Node** List = new Node*[21]; // 20 is max number of vertices
    int graphTable[21][21];
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            graphTable[i][j] = 0;
        }
    }

    while (running == true) { // loops until user quits the program
        cout << "Enter the number:" << endl;
        cout << "1. Add vertex" << endl;
        cout << "2. Add edge" << endl;
        cout << "3. Remove vertex" << endl;
        cout << "4. Remove edge" << endl;
        cout << "5. Print graph" << endl;

        cin >> input;
        cin.ignore(1, '\n');

        if (input == 1) { // add vertex
            addVertex(List, graphTable);
        }
        else if (input == 2) { // add edge
            addEdge(List, graphTable);
        }
        else if (input == 3) { // remove vertex
            removeVertex(List, graphTable);
        }
        else if (input == 4) { // remove edge
            removeEdge(List, graphTable);
        }
        else if (input == 5) { // prints
            print(graphTable);
        }
        else {
            cout << "Invalid input. Try again." << endl;

        }
    }
}

void addVertex(Node** List, int graphTable[21][21]) { // adds vertex 
    char* name = new char[4];
    cout << "What is the label name of your vertex?" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    for (int i = 0; i < 21; i++) { 
        if (List[i] == NULL) {
            List[i] = new Node(name);
            break;
        }
    }
}

void removeVertex(Node** List, int graphTable[21][21]) { // removes vertex
    char* name = new char[4];
    cout << "What vertex would you like to remove?" << endl;
    cin.get(name, 4);
    cin.ignore(1, '\n');

    int index = -1;
    for (int i = 0; i < 21; i++) { 
        if (strcmp(List[i]->name, name) == 0) {
            delete(List[i]);
            List[i] = NULL;
            index = i;
            cout << "Vertex has been removed" << endl;
            break;
        }
    }

    for (int i = 0; i < 21; i++) { 
        graphTable[i][index] = 0;
        graphTable[index][i] = 0;
  }
}

void addEdge(Node** List, int graphTable[21][21]) { // adds edge 
    char* name1 = new char[4];
    char* name2 = new char[4];
    int edgeWeight;
    cout << "What is the label name of your FIRST vertex?" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What is the label name of your SECOND vertex?" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');
    cout << "What the weight of the edge?" << endl;
    cin >> edgeWeight;
    cin.ignore(1, '\n');

    int index1 = 398121;
    int index2 = 398121;
    for (int i = 0; i < 21; i++) {
        if (List[i] != NULL) {
            if (strcmp(List[i]->name, name1) == 0) {
                index1 = i;
            }
            else if (strcmp(List[i]->name, name2) == 0) {
                index2 = i;
            }
        }
    }

    if (index1 != 398121 && index2 != 398121) { // adds edge weight
        graphTable[index1][index2] = edgeWeight;
        graphTable[index2][index1] = edgeWeight;
    }
    else {
        cout << "Invalid input. Try again." << endl;
    }
}

void removeEdge(Node** List, int graphTable[21][21]) { // removes edge
    char* name1 = new char[4];
    char* name2 = new char[4];
    cout << "What is the label name of the FIRST vertex?" << endl;
    cin.get(name1, 4);
    cin.ignore(1, '\n');
    cout << "What is the label name of your SECOND vertex?" << endl;
    cin.get(name2, 4);
    cin.ignore(1, '\n');

    int index1 = 398121;
    int index2 = 398121;
    for (int i = 0; i < 21; i++) { 
        if (List[i] != NULL) {
            if (strcmp(List[i]->name, name1) == 0) {
                cout << "Edge has been removed" << endl;
                index1 = i;
            }
            else if (strcmp(List[i]->name, name2) == 0) {
                cout << "Edge has been removed" << endl;
                index2 = i;
            }
        }
    }

    if (index1 != 398121 && index2 != 398121) { // removes the edge weight 
        graphTable[index1][index2] = 0;
        graphTable[index2][index1] = 0;
    }
    else {
        cout << "Invalid input. Try again." << endl;
    }
}

void print(int graphTable[21][21]) { // prints 
    cout << "   ";
    for (int i = 0; i < 21; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 21; i++) {
        if (i < 10) {
            cout << i << "  ";
        }
        else {
            cout << i << " ";
        }
        for (int j = 0; j < 21; j++) {
            if (j < 9) {
                cout << graphTable[i][j] << " ";
            }
            else {
                cout << graphTable[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

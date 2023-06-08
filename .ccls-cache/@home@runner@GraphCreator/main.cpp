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

void addNode(Node** List, int graphTable[21][21]);
void remNode(Node** List, int graphTable[21][21]);
void addEdge(Node** List, int graphTable[21][21]);
void remEdge(Node** List, int graphTable[21][21]);
void print(int graphTable[21][21]);

using namespace std;

int main() {
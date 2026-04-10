#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void addVertex();
void addEdge();
void removeVertex();
void removeEdge();
void djikstra();

int main() {

  vector<vector<int>> table = {};
  
  bool run = true;
  char input[99] = "";

  const char* ADD = "ADD";
  const char* REM = "REMOVE";
  const char* CON = "CONNECT";
  const char* QUIT = "QUIT";
  
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, ADD) == 0) {
    } else if (strcmp(input, REM) == 0) {
    } else if (strcmp(input, CON) == 0) {
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}

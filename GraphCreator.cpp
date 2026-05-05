#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int getIndex(vector<char[99]> labels, char label[99]);

void addVertex();
void addEdge();
void removeVertex();
void removeEdge();
void djikstra();

int main() {

  // Start x Destination Adjaceny matrix
  vector<vector<int>> table = {};

  vector<char[99]> labels = {}; 
  
  bool run = true;
  char input[99] = "";
  char start[99] = "";
  char end[99] = "";
  int num = 0;
  
  const char* ADD = "ADD";
  const char* REM = "REMOVE";
  const char* PATH = "PATH";
  const char* QUIT = "QUIT";

  const char* VERTEX = "VERTEX";
  const char* EDGE = "EDGE";
  
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, ADD) == 0) {
      cout << "VERTEX or EDGE?: ";
      cin >> input;
      cout << endl;

      if (strcmp(input, VERTEX) == 0) {
	cout << "Enter label: ";
	cin >> input;
	cout << endl;

	// fx
      } else if (strcmp(input, EDGE) == 0) {
	cout << "Enter start label: ";
	cin >> start;
	cout << endl;

	cout << "Enter end label: ";
	cin >> end;
	cout << endl;

	cout << "Enter weight: ";
	cin >> num;
	cout << endl;

	//fx
      }
    } else if (strcmp(input, REM) == 0) {
    } else if (strcmp(input, PATH) == 0) {
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}

int getIndex(vector<char[99]> labels, char label[99]) {

  for (int i = 0; i < labels.size(); i++) {
    if (strcmp(labels.at(i), label) == 0) {
      return i;
    }
  }

  return -1;

}

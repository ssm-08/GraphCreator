#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int getIndex(vector<char*> labels, char label[99]);

void addVertex(vector<vector<int>>& table);
void addEdge(vector<vector<int>>& table, int src, int dst, int weight);
void removeVertex();
void removeEdge();
void djikstra();

int main() {

  // Source x Destination Adjaceny matrix
  vector<vector<int>> table;

  vector<char*> labels; 
  
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

	char* label = new char[99];
	strcpy(label, input);
	labels.push_back(label);
	addVertex(table);
	
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

	int src = getIndex(labels, start);
	int dst = getIndex(labels, end);
	
	if (src > -1 && dst > -1) {
	  addEdge(table, src, dst, num);
	}
      }
    } else if (strcmp(input, REM) == 0) {
    } else if (strcmp(input, PATH) == 0) {
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
    }
  }
}

int getIndex(vector<char*> labels, char label[99]) {

  for (int i = 0; i < labels.size(); i++) {
    if (strcmp(labels.at(i), label) == 0) {
      return i;
    }
  }

  return -1;

}

void addVertex(vector<vector<int>>& table) {

  // Create new column for vertex
  int newSize = table.size() + 1;

  vector<int> vertex;

  for (int i = 0; i < newSize; i++) {
    vertex.push_back(0);
  }

  // Increment destination spots for current vertices
  for (auto it = table.begin(); it != table.end(); ++it) {
    it->push_back(0);
  }

  // Add vertex
  table.push_back(vertex);
}

void addEdge(vector<vector<int>>& table, int src, int dst, int weight) {

  table.at(src).at(dst) = weight;
  
}

/*
 * References:
 * Djikstra's Algorithm Wikipedia
 */


#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Program functions
int getIndex(vector<char*> labels, char label[99]);
void print(vector<vector<int>> table, vector<char*> labels);

void addVertex(vector<vector<int>>& table);
void addEdge(vector<vector<int>>& table, int src, int dst, int weight);
void removeVertex(vector<vector<int>>& table, int vertex);
void removeEdge(vector<vector<int>>& table, int src, int dst);
void djikstra(vector<vector<int>> table, int src, int dst);

int main() {

  // Program variables
  
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
  const char* PRINT = "PRINT";
  const char* QUIT = "QUIT";

  const char* VERTEX = "VERTEX";
  const char* EDGE = "EDGE";

  cout << "Commands: ADD REMOVE PATH PRINT QUIT" << endl;
  
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, ADD) == 0) { // Add vertex or edge
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
	
	addEdge(table, src, dst, num);
	
      }
    } else if (strcmp(input, REM) == 0) { // Remove vertex or edge
      cout << "VERTEX or EDGE?: ";
      cin >> input;
      cout << endl;

      if (strcmp(input, VERTEX) == 0) {
	cout << "Enter label: ";
	cin >> input;
	cout << endl;

	int vertex = getIndex(labels, input);
	delete[] labels.at(vertex);
	labels.erase(labels.begin() + vertex);
	removeVertex(table, vertex);
	
      } else if (strcmp(input, EDGE) == 0) {
	cout << "Enter start label: ";
	cin >> start;
	cout << endl;

	cout << "Enter end label: ";
	cin >> end;
	cout << endl;

	int src = getIndex(labels, start);
	int dst = getIndex(labels, end);
	
	removeEdge(table, src, dst);
      }
    } else if (strcmp(input, PATH) == 0) { // Shortest path
      cout << "Enter start label: ";
      cin >> start;
      cout << endl;

      cout << "Enter end label: ";
      cin >> end;
      cout << endl;

      int src = getIndex(labels, start);
      int dst = getIndex(labels, end);

      djikstra(table, src, dst);
	
    } else if (strcmp(input, PRINT) == 0) { // Print
      print(table, labels);
    } else if (strcmp(input, QUIT) == 0) { // Quit
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

void print(vector<vector<int>> table, vector<char*> labels) {

  // Columns
  
  for (auto it = labels.begin(); it != labels.end(); ++it) {
    cout << "\t" << *it;
  }

  cout << endl;

  // Rows
  for (int i = 0; i < table.size(); i++) {
    cout << labels.at(i);

    for (int j = 0; j < table.size(); j++) {
      cout << "\t" << table.at(j).at(i);
    }

    cout << endl;
  }
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

  if (src > -1 && dst > -1) {
    // Set weight at source and destination location
    table.at(src).at(dst) = weight;
  }
}

void removeVertex(vector<vector<int>>& table, int vertex) {
  if (vertex > -1) {
  
    // Remove destination for each column
    for (int i = 0; i < table.size(); i++) {
      table.at(i).erase(table.at(i).begin() + vertex);
    }

    // Remove vertex
    table.erase(table.begin() + vertex);

  }
}

void removeEdge(vector<vector<int>>& table, int src, int dst) {

  if (src > -1 && dst > -1) {
    // Reset weight to 0
    table.at(src).at(dst) = 0;
  }
}

void djikstra(vector<vector<int>> table, int src, int dst) {

  if (src <= -1 && dst <= -1) {
    return;
  }
  
  vector<int> unvisited;

  cout << "filling" << endl;
  
  for (int i = 0; i < table.size(); i++) {
    unvisited.push_back(i);
    cout << unvisited.at(i) << endl;
  }

  int distance[table.size()] = {};
  int vertex = src;

  cout << "setup" << endl;
  
  while (!unvisited.empty()) {
    
    // Reached
    if (vertex == dst) {
      cout << "Distance is " << distance[dst] << endl;
      return;
    }

    vector<int> n;
    vector<int> column = table.at(vertex);

    cout << "finding" << endl;
    
    for (auto it = unvisited.begin(); it != unvisited.end(); ++it) {
      for (int i = 0; i < column.size(); i++) {
	// Check if destination is a neighbor and in unvisted
	if (*it == i && column.at(i) != 0) {
	  // Update neighbors
	  n.push_back(i);
	  // Check if distance is smaller
	  if (distance[vertex] + column.at(i) < distance[i] || distance[i] == 0) {
	    distance[i] = distance[vertex] + column.at(i);
	  }
	}
      }
    }

    // Unreachble to other vertices
    if (n.empty()) {
      break;
    }

    cout << "remove" << endl;
    
    // Remove current from unvisited
    for (auto it = unvisited.begin(); it != unvisited.end(); ++it) {
      if (*it == vertex) {
	unvisited.erase(it);
	break;
      }
    }

    cout << "select" << endl;
    
    // Select new vertex
    auto v = n.begin();
    for (auto it = n.begin() + 1; it != n.end(); ++it) {
      if (column.at(*it) < column.at(*v)) {
	v = it;
      } 
    }

    vertex = *v;
  }

  cout << "No path exisis" << endl;
}

/*
Задача 2. Съставете програма за работа с ориентиран граф, 
представен чрез списъци на съседство, която да предлага меню с основните операции
със структурата граф. Да се напише функция, която брои и визуализира изолирани 
върхове в дадения граф и се добави към менюто.
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<unordered_set<int> > adjList; // Adjacency lists

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].insert(v);
    }

    void displayIsolatedVertices() {
        vector<int> isolatedVertices;
        for (int i = 0; i < V; ++i) {
            if (adjList[i].empty()) {
                isolatedVertices.push_back(i);
            }
        }

        if (isolatedVertices.empty()) {
            cout << "No isolated vertices found.\n";
        } else {
            cout << "Isolated vertices: ";
            for (int v : isolatedVertices) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void displayMenu() {
        cout << "Menu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Isolated Vertices\n";
        cout << "3. Exit\n";
    }
};

int main() {
    int vertices, choice, u, v;

    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    do {
        graph.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                graph.addEdge(u, v);
                break;
            case 2:
                graph.displayIsolatedVertices();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
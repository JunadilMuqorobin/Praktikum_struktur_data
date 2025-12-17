#include <iostream>
#include "graph.h"
#include "graph.cpp"
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    adrNode A = G.first;
    adrNode B = A->next;
    adrNode C = B->next;
    adrNode D = C->next;
    adrNode E = D->next;

    ConnectNode(G, A, B);
    ConnectNode(G, A, C);
    ConnectNode(G, B, D);
    ConnectNode(G, C, E);

    cout << "=== STRUKTUR GRAPH ===" << endl;
    PrintInfoGraph(G);

    cout << "\n=== DFS dari A ===" << endl;
    ResetVisited(G);
    PrintDFS(G, A);

    cout << "\n\n=== BFS dari A ===" << endl;
    ResetVisited(G);
    PrintBFS(G, A);

    return 0;
}

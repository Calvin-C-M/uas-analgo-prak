#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V;
    int E;
    Edge *edge;
};

Graph *createGraph(int V, int E) {
    Graph *g=new Graph();
    g->V=V;
    g->E=E;
    g->edge=new Edge[E];
    return g;
}

void addEdge(Edge &edge, int src, int dest, int weight) {
    edge.src=src;
    edge.dest=dest;
    edge.weight=weight;
}

void printGraph(int dist[], int n) {
    std::cout << "Vertex\t\tDistance from Source\n";
    for(int i=0; i<n; i++) 
        std::cout << i << "\t\t" << dist[i] << "\n";
}

int minDistance(int dist[], bool sptSet[], int V) {
    int min=INT_MAX;
    int minIndex=0;

    for(int v=0; v<V; v++) {
        if(sptSet[v] == false && dist[v] <= min) {
            min=dist[v];
            minIndex=v;
        }
    }

    return minIndex;
}

void djikstra(Graph *graph, int source) {
    int V=graph->V;
    int E=graph->E;
    int dist[V];
    bool sptSet[V];
    // std::queue<int> q;


    for(int i=0; i<V; i++) {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[source]=0;

    for(int i=0; i<V-1; i++) {
        int u=minDistance(dist,sptSet,V);
        sptSet[u]=true;
        for(int v=0; v<V; v++) {
            int weight=graph->edge[v].weight;
            if(dist[u] + weight < dist[v]) {
                dist[v]=dist[u]+weight;
            }
        }
    }

}

int main() {

}
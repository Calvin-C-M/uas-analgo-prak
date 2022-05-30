#include <iostream>

const int V=9;

int minDistance(int dist[], bool sptSet[]) {
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

void printGraph(int dist[]) {
    std::cout << "Vertex\t\tDistance from Source\n";
    for(int v=0; v<V; v++) 
        std::cout << v << "\t\t" << dist[v] << "\n";
}

void djikstra(int graph[V][V], int source) {
    int dist[V];
    bool sptSet[V];

    for(int i=0; i<V; i++) {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[source]=0;

    for(int i=0; i<V-1; i++) {
        int u=minDistance(dist,sptSet);

        sptSet[u]=true;

        for(int v=0; v<V; v++) {
            int weight=graph[u][v];
            if(!sptSet[v] && weight && dist[u] != INT_MAX && dist[u]+weight < dist[v]) {
                dist[v]=dist[u]+weight;
            }
        }
    }
    
    printGraph(dist);
}

int main() {
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    djikstra(graph,0);
}
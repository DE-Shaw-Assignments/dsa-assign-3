class Solution {
public:
    int minDistance(int distance[], int vertices, bool sptSet[]) {
        int minimum = INT_MAX, minIndex = -1; 
        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && distance[v] <= minimum) {
                minimum = distance[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    int dijkstra(vector<vector<int>>& graph, int vertices, int source) {
        int distance[vertices];
        bool sptSet[vertices];
        for (int i = 0; i < vertices; i++) {
            distance[i] = INT_MAX;
            sptSet[i] = false;
        }
        distance[source] = 0;
        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(distance, vertices, sptSet);
            if (u == -1) {
                return -1;
            }
            sptSet[u] = true;
            for (int v = 0; v < vertices; v++) {
                if (!sptSet[v] && graph[u][v] > -1 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
        int max = INT_MIN;
        for (int i = 0; i < vertices; i++) {
            if (distance[i] == INT_MAX) 
                return -1;
            if (distance[i] > max)
                max = distance[i];
        }
        return max;
    }

    int networkDelayTime(vector<vector<int>>& times, int nodes, int source) {
        vector<vector<int>> graph(nodes, vector<int>(nodes));
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                graph[i][j] = -1;
            }
        }
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            graph[u][v] = times[i][2];
        }
        return dijkstra(graph, nodes, source - 1);
    }
};

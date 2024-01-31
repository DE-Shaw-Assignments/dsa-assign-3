class Solution {
public:
    void depthFirstSearch(int vertex, bool visited[], vector<vector<int>>& adjacencyList) {
        visited[vertex] = true;

        for (int neighbor = 0; neighbor < adjacencyList.size(); neighbor++) {
            int connectedVertex = adjacencyList[vertex][neighbor];
            if (!visited[neighbor] && connectedVertex)
                depthFirstSearch(neighbor, visited, adjacencyList);
        }
    }

    int findCircleNum(vector<vector<int>>& adjacencyList) {
        int numVertices = adjacencyList.size();
        bool* visited = new bool[numVertices];

        int count = 0;
        for (int vertex = 0; vertex < numVertices; vertex++)
            visited[vertex] = false;

        for (int vertex = 0; vertex < numVertices; vertex++) {
            if (!visited[vertex]) {
                depthFirstSearch(vertex, visited, adjacencyList);
                count++;
            }
        }

        delete[] visited;
        return count;
    }
};

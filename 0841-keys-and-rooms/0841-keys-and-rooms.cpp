class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v])
            if (!visited[u])
                dfs(u, adj, visited);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};
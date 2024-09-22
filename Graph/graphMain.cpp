/******Graph********/
void TC() {
    /* dfs =>
     *Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
     *Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list
     */

    /* bfs =>
     *Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
     *Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
     */

    /* Connected Component =>
     *Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E).
     *Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
     */

    /* Dijkstra - shortest distance of all the vertices from the source vertex S. 
     *Time Complexity : O( E log(V) ) Space Complexity : O( |E| + |V| ) 
    */

    /* detect cycle in undirected graph =>
     *Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
     *Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
     */

    /* detect cycle in directed graph => Kahn’s Algorithm =>
     *Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
     *Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
     */

    /* Topological Sort | Kahn’s Algorithm =>
     *Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
     *Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
     */

    /* Bellman Ford Algorithm =>
     *Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.
     *Note: If the Graph contains a negative cycle then return an array consisting of only -1.
     *Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.
     *Space Complexity: O(V) for the distance array which stores the minimized distances.
     */

    /* Floyd Warshall Algorithm =>
     *The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
     *Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.
     *Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
     */

    /* Prim’s Algorithm | Minimum Spanning Tree =>
     *Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
     *Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices.
     *Prim's algorithm is faster in calculating the minimum spanning tree for dense graphs.
     */

    /* Disjoint Set | Union by Rank | Union by Size | Path Compression =>
     *Time Complexity:  The time complexity is O(4) which is very small and close to 1. So, we can consider 4 as a constant.
     */

    /* Strongly Connected Components – Kosaraju’s Algorithm =>
     *Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.
     *Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list
     */
}

//* check for 0- based indexing and one based indexing//
class Graph {
   public:
    int noOfNode = 0;
    vector<vector<int>> adj;
    vector<int> vis;

    void input(int n, int e = 0) {
        noOfNode = n;
        adj.resize(n + 1);
        vis.resize(n + 1);
        if (e == 0) e = n - 1;
        for (int i = 1; i <= e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void reset(int n) {
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            // adj[i].clear();
        }
    }

    void dfs(int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it);
            }
        }
        vis[node] = 2;
    }

    void bfsOfGraph(int node) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int noOfConnectedComponent() {
        int cnt = 0;
        for (int i = 1; i <= noOfNode; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }

    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int S) {
        set<pair<int, int>> st;
        vector<int> dist(V+1, 1e9);

        st.insert({0, S});
        dist[S] = 0;
        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgW = it.second;
                if (dis + edgW < dist[adjNode]) {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

   private:
    bool detectForUDG(int src) {
        vis[src] = 1;
        // store <source node, parent node>
        queue<pair<int, int>> q;
        q.push({src, -1});
        // traverse until queue is not empty
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // go to all adjacent nodes
            for (auto adjacentNode : adj[node]) {
                // if adjacent node is unvisited
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode) {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        // there's no cycle
        return false;
    }

   public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicForUDG() {
        for (int i = 1; i <= noOfNode; i++) {
            if (!vis[i]) {
                if (detectForUDG(i)) return true;
            }
        }
        return false;
    }

   public:
    // Function to detect cycle in a directed graph.
    bool isCyclicForDG() {
        vector<int> indegree(noOfNode + 1);
        for (int i = 1; i <= noOfNode; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= noOfNode; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        // o(v + e)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (cnt == noOfNode) return false;
        return true;
    }

    /*
     *Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
     *Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).*/
   public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort() {
        vector<int> indegree(noOfNode + 1);
        for (int i = 1; i <= noOfNode; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= noOfNode; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }

   public:
    //   Function to implement Bellman Ford
    //    edges: vector of vectors which represents the graph
    //    S: source vertex to start traversing graph with
    // V: number of vertices

    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dist(V + 1, 1e8);
        dist[S] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }

   public:
    void shortest_distance(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if (i == j) matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }

   public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<pair<int, int>>> &adj) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> mst;

        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, {1, -1}});
        int sum = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            auto node = it.second;
            int wt = it.first;

            if (vis[node.first] == 1) continue;
            // add it to the mst
            vis[node.first] = 1;
            sum += wt;

            if (node.second != -1) {
                mst.push_back({node.first, node.second, wt});
            }

            for (auto it : adj[node.first]) {
                int adjNode = it.first;
                int edW = it.second;
                if (!vis[adjNode]) {
                    pq.push({edW, {adjNode, node.first}});
                }
            }
        }
        debug(mst) return sum;
    }

   private:
    void dfsForSCC(int node, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsForSCC(it, st);
            }
        }

        st.push(node);
    }

   private:
    void dfs3ForSCC(int node, vector<int> &vis, vector<vector<int>> &adjT) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3ForSCC(it, vis, adjT);
            }
        }
    }

   public:
    // Function to find number of strongly connected components in the graph.
    int numOfStronglyConnectedComp() {
        stack<int> st;
        for (int i = 1; i <= noOfNode; i++) {
            if (!vis[i]) {
                dfsForSCC(i, st);
            }
        }

        vector<vector<int>> adjT(noOfNode + 1);
        for (int i = 1; i <= noOfNode; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3ForSCC(node, vis, adjT);
            }
        }
        return scc;
    }
};

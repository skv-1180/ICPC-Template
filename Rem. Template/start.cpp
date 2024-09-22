#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include<bits/debugger.h>
#else
#define cl()
#define setio
#define graph(x,y)
#define debug(x...)
#define debugptr(x,y)
#endif

void comment(){
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
//* for converting (r,c) to a node use (row*m+c) where m is row length
void usefulTool(){
	/*
	bool isvalid(int row , int col , int n , int m){
		if(row >=0 && row<n && col >= 0 && col <m)return true ;
		return false;}
	*/

	/*for converting (r,c) to a node use (row*m+c) where m is row length*/
	/*
	 int trow[] = {-1,0,1,0};
     int tcol[] = {0,1,0,-1};
	 for(int i =0;i<4 ; i++){
                int nrow = trow[i] + row;
                int ncol = tcol[i] + col;
                
                if(isvalid(nrow ,ncol , n , m)){
                    if(visited[nrow][ncol]==1){
                        int nodeno = row *m +col ;
                        int adjnodeno = nrow * m + ncol;
                        if(ds.find_parent(nodeno) != ds.find_parent(adjnodeno)){
                            count--;
                            ds.unionbyrank(nodeno,adjnodeno);
                        }
                    }
                }
            }
	*/

}
//* check for 0- based indexing and one based indexing//
class Solution {
   public: 

    vector<int> Dfs;
    vector<int> bfs;

    void dfs(int node, vector<int> adj[], int vis[]) {
        vis[node] = 1; 
        Dfs.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis); 
            }
        }
    }

  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        dfs(start, adj, vis); 
        return Dfs; 
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); 
         
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }

     int noOfConnectedComponent(vector <int> adj[], int V) {
        
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adj, vis); 
            }
        }
        return cnt; 
        
    }

  private: 
  bool detectForUDG(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
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
    bool isCyclicForUDG(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detectForUDG(i, adj, vis)) return true; 
            }
        }
        return false; 
    }

    public:
	// Function to detect cycle in a directed graph.
	bool isCyclicForDG(int V, vector<int> adj[]) {
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
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
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (cnt == V) return false;
		return true;
	}

    /*
     Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
     Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).
    */
   public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}

    public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
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
				return { -1};
			}
		}


		return dist;
	}

    public:
	void shortest_distance(vector<vector<int>>&matrix) {
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
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>> > , greater<pair<int, pair<int,int>>>> pq;
		vector<vector<int>> mst;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, {0, -1}});
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

			if(node.second != -1){
				mst.push_back({node.first,node.second,wt});
			}

			for (auto it : adj[node.first]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, {adjNode,node.first}});
				}
			}
		}
		debug(mst)
		return sum;
	}

	private:
    void dfsForSCC(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsForSCC(it, vis, adj, st);
            }
        }

        st.push(node);
    }
private:
    void dfs3ForSCC(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3ForSCC(it, vis, adjT);
            }
        }
    }
public:
    //Function to find number of strongly connected components in the graph.
    int numOfStronglyConnectedComp(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsForSCC(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
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


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

class DisjointSet {
	//* we can use either union by rank or union by size & it works for both 0 and 1 based indexing*//
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        /* rank.resize(n + 1, 0); */
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
	//ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    /* void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    } */

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
}

int main() 
{
    // vector <int> adj[6];
    
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 4, 3);
    // addEdge(adj, 2, 1);

    // Solution obj;
    // vector <int> bans = obj.bfsOfGraph(5, adj);
    // printAns(bans);

    // vector <int> dans = obj.dfsOfGraph(5, adj);
    // printAns(dans);

    // cout<<obj.noOfConnectedComponent(adj,5)<<endl;

    // vector<int> adj1[4] = {{}, {2}, {1, 3}, {2,1}};

    // bool ans = obj.isCyclicForUDG(4, adj1);
    // if (ans)
    //     cout << "1\n";
    // else
    //     cout << "0\n";

    // vector<int> adj2[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    // Solution obj;
	// int V = 11;
	// int ans = obj.isCyclicForDG(V, adj2);

	// if (ans)
	// 	cout << "True\n";
	// else
	// 	cout << "False\n";

    // vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	// int V = 6;
	// Solution obj;
	// vector<int> ans = obj.topoSort(V, adj);

	// for (auto node : ans) {
	// 	cout << node << " ";
	// }
	// cout << endl;

    // int V = 6;
	// vector<vector<int>> edges(7, vector<int>(3));
	// edges[0] = {3, 2, 6};
	// edges[1] = {5, 3, 1};
	// edges[2] = {0, 1, 5};
	// edges[3] = {1, 5, -3};
	// edges[4] = {1, 2, -2};
	// edges[5] = {3, 4, -2};
	// edges[6] = {2, 4, 3};

	// int S = 0;
	// Solution obj;
	// vector<int> dist = obj.bellman_ford(V, edges, S);
	// for (auto d : dist) {
	// 	cout << d << " ";
	// }
	// cout << endl;

    // 	int V = 4;
	// vector<vector<int>> matrix(V, vector<int>(V, -1));
	// matrix[0][1] = 2;
	// matrix[1][0] = 1;
	// matrix[1][2] = 3;
	// matrix[3][0] = 3;
	// matrix[3][1] = 5;
	// matrix[3][2] = 4;

	// Solution obj;
	// obj.shortest_distance(matrix);

	// for (auto row : matrix) {
	// 	for (auto cell : row) {
	// 		cout << cell << " ";
	// 	}
	// 	cout << endl;
	// }


	//! MST
	// int V = 5;
	// vector<vector<int>> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
	// vector<vector<int>> adj[V];
	// //convert edges => adj;
	// for (auto it : edges) {
	// 	vector<int> tmp(2);
	// 	tmp[0] = it[1];
	// 	tmp[1] = it[2];
	// 	adj[it[0]].push_back(tmp);

	// 	tmp[0] = it[0];
	// 	tmp[1] = it[2];
	// 	adj[it[1]].push_back(tmp);
	// }

	// Solution obj;
	// int sum = obj.spanningTree(V, adj);
	// cout << "The sum of all the edge weights: " << sum << endl;

	//! DSU
	// DisjointSet ds(7);
    // ds.unionBySize(1, 2);
    // ds.unionBySize(2, 3);
    // ds.unionBySize(4, 5);
    // ds.unionBySize(6, 7);
    // ds.unionBySize(5, 6);
    // // if 3 and 7 same or not
    // if (ds.findUPar(3) == ds.findUPar(7)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";

    // ds.unionBySize(3, 7);

    // if (ds.findUPar(3) == ds.findUPar(7)) {
    //     cout << "Same\n";
    // }
    // else cout << "Not same\n";

	//!SCC
	 int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.numOfStronglyConnectedComp(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
  
    return 0;
}




// made by Santhosh And Yashwanth
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <cstdlib>

using namespace std;

int main() {


	int n,m;
	cin>>n>>m;

	vector<vector<int> > adj(n, vector<int>());

	int prev;
	int *number_of_edges = (int*)malloc(n*sizeof(int));
	cin>>prev;

	for(int i = 0; i < n; i++) {
		int temp;
		cin>>temp;
		number_of_edges[i] = temp-prev;
		prev = temp;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < number_of_edges[i]; j++) {
			int temp;
			cin>>temp;
			fflush(stdout);
			adj[i].push_back(temp);
		}
	}

	queue<int> q;
	int *d = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++) d[i] = 1e9;
	bool *vis = (bool*)malloc(n*sizeof(bool));
	for(int i = 0; i < n; i++) vis[i] = false;
	q.push(0);
	vis[0] = true;
	d[0] = 0;

	int depth = 0;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto u:adj[v]) {
			if(!vis[u]) {
				vis[u] = true;
				q.push(u);
				d[u] = d[v]+1;
				if(d[u] > depth) {
					depth = d[u];
				}
			}
		}
	}

	cout<<"The depth of the given graph from node 0 is "<<depth<<endl;

	std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

	cout<<"Time taken for serial BFS: "<<(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count())/1000<<"ms\n";





	return 0;
}

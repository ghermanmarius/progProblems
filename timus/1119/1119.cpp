#include <iostream>

#define MAX_DIST 999999999

int main() {
	int N, M;
	std::cin >> N >> M;
	
	long long dist[N][M];
	memset(dist, 0, N * M * sizeof(long long));
	
	bool visited[i][j];
	memset(visited, 0, N * M * sizeof(bool));
	
	//set initial distances
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			dist[i][j] = MAX_DIST;
		}
	//initial node distances
	dist[0][0] = 0;
	
	int currentX = 0;
	int currentY = 0;	
	int numVisted = 1;
	
	while (numVisited < N * M - 1) { // what is the number of nodes that you need to visit??
		//select current node as the node with the minimum dist value]
		int minDist = MAX_DIST;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (dist[i][j] < minDist) {
					currentX = i;
					currentY = j;
				}
			}
		visited[i][j] = true;
	
		//each node has a maximum of 3 neighbors
		
		//get distance for top neghbor if it exists
		if (j < M - 2) { 
			if (dist[i][j] + 1 < dist[i][j + 1]) {
				dist[i][j + 1] = dist[i][j] + 1;
			}
		}
		
		//get distance for right neighbor if it exists
		if (i < N - 2) {
			if (dist[i][j] + 1 < dist[i + 1][j]) {
				dist[i + 1][j] = dist[i][j] + 1;
			}
		}
		
		//get distance for diagonal neighbor if it exists
		
		
		
		
		
	} 
	
	
	
		

	return 0;
}

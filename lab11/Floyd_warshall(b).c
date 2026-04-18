// Perform the Floyd warshall all path shortest distance algorithm

#include <stdio.h>

#define MAX 10
#define INF 99999

int main() {
    int n, dist[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {          // intermediate vertex
        for (int i = 0; i < n; i++) {      // source
            for (int j = 0; j < n; j++) {  // destination
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Output shortest distance matrix
    printf("\nAll-Pairs Shortest Distance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// bfs algo of c
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

// enqueue
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// dequeue
int dequeue() {
    if (front == -1)
        return -1;
    int item = queue[front++];
    if (front > rear)
        front = rear = -1;
    return item;
}

// BFS function
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
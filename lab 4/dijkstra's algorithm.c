#include <stdio.h>
#define MAX 10
#define INF 999

void dijkstra(int cost[MAX][MAX], int n, int start);

int main() {
    int cost[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(cost, n, start);

    return 0;
}

void dijkstra(int cost[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX];
    int i, j, count, min, nextnode;

    for(i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(distance[i] < min && !visited[i]) {
                min = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i]) {
                if(min + cost[nextnode][i] < distance[i]) {
                    distance[i] = min + cost[nextnode][i];
                }
            }
        }

        count++;
    }

    printf("\nShortest distances from node %d:\n", start);
    for(i = 0; i < n; i++) {
        if(i != start) {
            printf("%d -> %d = %d\n", start, i, distance[i]);
        }
    }
}

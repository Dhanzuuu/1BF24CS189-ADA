#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void topologicalSort(int n, int graph[MAX][MAX]) {
    int indegree[MAX] = {0};
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            push(i);
        }
    }

    printf("Topological sort sequence: ");

    while (!isEmpty()) {
        int u = pop();
        printf("%d ", u);

        for (i = 0; i < n; i++) {
            if (graph[u][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    push(i);
                }
            }
        }
    }

    printf("\n");
}

int main() {
    int n, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(n, graph);

    return 0;
}

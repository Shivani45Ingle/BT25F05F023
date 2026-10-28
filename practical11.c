
#include <stdio.h>

int graph[20][20], visited[20];
int queue[20], front = -1, rear = -1;
int n;

void BFS(int start)
{
    int i, vertex;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear)
    {
        vertex = queue[++front];
        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}


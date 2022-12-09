#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define VER 9
void display(int firstMatrix[][100], int rowFirst, int
columnSecond);
struct Edge
{
int u;
int v;
};
struct Graph
{
int V;
int E;
struct Edge *edge;
};
struct Graph *g;
void writeToFile()
{
FILE *fptr;
fptr = fopen("petnames.txt", "w");
if (fptr == NULL)
{
printf("Error\n");
}
else
{
fprintf(fptr, "Name of head child %s data of node of head 
child %d", g->V, g->E);
while (g->edge != NULL)
{
fprintf(fptr, "\nName of child sibling node %s\nno of 
int data %d\n", g->edge->u, g->edge->v);
}
}
fclose(fptr);
}
void printGraph(struct Graph *graph)
{
int v;
for (v = 0; v < graph->V; v++)
{
struct Edge *temp = graph->edge;
printf("\n Adjacency list of vertex for hotel %d\n ", temp-
>v);
while (temp != NULL)
{
printf("%d -> ", temp->v);
printf("%d -> ", temp->u);
}
printf("\n");
}
}
void display(int firstMatrix[][100], int rowFirst, int columnFirst)
{
int i, j;
printf("\nOutput Matrix of given hotel data:\n");
for (i = 0; i < rowFirst; i++)
{
for (j = 0; j < columnFirst; j++)
{
printf("%d ", firstMatrix[i][j]);
if (j == columnFirst - 1)
printf("\n\n");
}
}
}
int minDistance(int dist[], int sptSet[])
{
int min = INT_MAX, min_index;
int v;
for (v = 0; v < VER; v++)
if (sptSet[v] == 0 && dist[v] <= min)
min = dist[v], min_index = v;
return min_index;
}
void printSolution(int dist[], int n)
{
printf("Vertex Distance from Source\n");
int i;
FILE *fptr;
fptr = fopen("graph.txt", "w");
if (fptr == NULL)
{
printf("Error\n");
}
for (i = 0; i < VER; i++)
{
printf("%d \t\t %d\n", i, dist[i]);
fprintf(fptr, "%d \n", dist[i]);
}
fclose(fptr);
}
// Funtion that implements MIN_PATH's single source shortest path 
algorithm
// for a graph represented using adjacency matrix representation
void MIN_PATH(int graph[VER][VER], int src)
{
int dist[VER]; // The output array. dist[i] will hold the 
shortest distance from src to i
int sptSet[VER]; // sptSet[i] will 1 if vertex i is included in 
shortest path tree or shortest distance from src to i is finalized
// Initialize all distances as INFINITE and stpSet[] as 0
int i, count, v;
for (i = 0; i < VER; i++)
dist[i] = INT_MAX, sptSet[i] = 0;
// Distance of source vertex from itself is 0
dist[src] = 0;
// Find shortest path for all vertices
for (count = 0; count < VER - 1; count++)
{
int u = minDistance(dist, sptSet); // u is always equal to 
src in first iteration.
sptSet[u] = 1; // Mark the picked vertex 
as processed
// Update dist value of the adjacent vertices of the picked 
vertex.
for (v = 0; v < VER; v++)
if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}
printSolution(dist, VER);
}
int main()
{
struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
g->V = 4;
g->E = 5;
int firstMatrix[10][100], rowFirst, columnFirst, i, j, k;
printf("Enter rows and column for first matrix: ");
scanf("%d %d", &rowFirst, &columnFirst);
display(firstMatrix, rowFirst, columnFirst);
int graph[VER][VER] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
{4, 0, 8, 0, 0, 0, 0, 11, 0},
{0, 8, 0, 7, 0, 4, 0, 0, 2},
{0, 0, 7, 0, 9, 14, 0, 0, 0},
{0, 0, 0, 9, 0, 10, 0, 0, 0},
{0, 0, 4, 0, 10, 0, 2, 0, 0},
{0, 0, 0, 14, 0, 2, 0, 1, 6},
{8, 11, 0, 0, 0, 0, 1, 0, 7},
{0, 0, 2, 0, 0, 0, 6, 7, 0}};
MIN_PATH(graph, 0);
writeToFile();
return 0;
}

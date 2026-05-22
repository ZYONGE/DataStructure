/* 그래프 인접 행렬 표현 (Adjacency Matrix Representation) */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char VElement;

int vsize = 5;

VElement vdata[MAX_SIZE] = {'U','V','W','X','Y'};

/* 인접 행렬: adj[i][j] == 1이면 정점 i와 j 사이에 간선 존재 */
int adj[MAX_SIZE][MAX_SIZE] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0},
};

/* 정점 v의 차수: v행에서 1의 개수 */
int degree(int v){
    int count = 0;
    for(int i=0; i<vsize;i++){
        if (adj[v][i] == 1){
            count++;
        }
    }
    return count;
}

int main (void){
    /* 각 정점의 인접 행렬 행을 출력: 정점이름(차수): 행 값들 */
    printf("graph nearby matrix\n");

    for(int i = 0; i<vsize;i++){
        printf("%c(%d): ", vdata[i], degree(i));
        for(int j = 0;j<vsize;j++){
            printf("%2d", adj[i][j]);
        }
        printf("\n");
    }
}

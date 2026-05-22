/* 그래프 인접 리스트 표현 (Adjacency List Representation) */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char VElement;

/* 인접 리스트의 노드: 연결된 정점 id와 다음 노드 포인터 */
typedef struct GNode{
    int id;
    struct GNode *link;
}GNode;

int vsize = 5;

VElement vdata[MAX_SIZE] = {'U','V','W','X','Y'};

/* 각 정점의 인접 리스트 헤드 포인터 배열 */
GNode *adj[5] = {NULL,NULL,NULL,NULL,NULL};

/* 리스트 앞에 노드를 삽입하고 새 헤드를 반환 */
GNode * prepend_node(GNode *head, int v){
    GNode *n = (GNode *)malloc(sizeof(GNode));
    n -> id = v;
    n -> link = head;
    return n;
}

/* 무방향 간선 (u, v) 삽입: 양쪽 리스트에 추가 */
void insert_edge(int u, int v){
    adj[u] = prepend_node(adj[u],v);
    adj[v] = prepend_node(adj[v],u);
}

/* 정점 v의 차수(연결된 간선 수) 반환 */
int degree(int v){
    int count = 0;
    for(GNode *p = adj[v];p!=NULL;p=p->link){
        count++;
    }
    return count;
}

int main(void){
    /* 간선 삽입 */
    insert_edge(0,1);
    insert_edge(0,2);
    insert_edge(1,2);
    insert_edge(1,3);
    insert_edge(2,4);

    /* 각 정점의 인접 리스트 출력: 정점이름(차수): 인접정점들 */
    printf("Graph nearby list\n");
    for(int i=0;i<vsize;i++){
        printf("%c(%d): ", vdata[i], degree(i));
        for(GNode *p=adj[i];p!=NULL;p=p->link){
            printf("%c ", vdata[p->id]);
        }
        printf("\n");
    }

    return 0;
}

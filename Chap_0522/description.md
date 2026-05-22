# 그래프 (Graph)

## 그래프의 정의

- 정점(Vertex)과 간선(Edge)으로 구성된 자료구조
- G = (V, E) 로 표현
- 무방향 그래프(Undirected Graph): 간선에 방향이 없음 → (u, v) = (v, u)

## 그래프의 구조

이번 실습의 그래프 (정점: U V W X Y)

```
U — V — X
|\ |
| \|
W — Y
```

간선 목록: (U,V), (U,W), (V,W), (V,X), (W,Y)

## 그래프의 특징

| 표현 방식 | 공간복잡도 | 간선 확인 | 적합한 그래프 |
|-----------|-----------|-----------|--------------|
| 인접 행렬 | O(V²) | O(1) | 밀집(Dense) |
| 인접 리스트 | O(V + E) | O(degree) | 희소(Sparse) |

## 그래프의 차수

- **차수(Degree)**: 한 정점에 연결된 간선의 수
- 인접 행렬: `adj[v]` 행에서 1의 개수를 셈 → O(V)
- 인접 리스트: `adj[v]` 리스트의 노드 수를 셈 → O(degree(v))

## 그래프의 연산

```
method list
```

### 인접 행렬 (GraphRepAM.c)

```c
// 간선 존재 여부: O(1)
adj[u][v] == 1

// 차수 계산: O(V)
int degree(int v) {
    for (int i = 0; i < vsize; i++)
        if (adj[v][i] == 1) count++;
}
```

### 인접 리스트 (GraphRepAL.c)

```c
// 노드 구조체
typedef struct GNode {
    int id;
    struct GNode *link;
} GNode;

// 간선 삽입 (무방향): 양쪽 리스트에 prepend
void insert_edge(int u, int v) {
    adj[u] = prepend_node(adj[u], v);
    adj[v] = prepend_node(adj[v], u);
}

// 차수 계산: O(degree(v))
int degree(int v) {
    for (GNode *p = adj[v]; p != NULL; p = p->link)
        count++;
}
```

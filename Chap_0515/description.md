# tree

## 트리란:
노드(Node)와 간선(Edge)으로 이루어진 **계층적(hierarchical) 비선형 자료구조**이다.
하나의 루트 노드에서 시작하여 자식 노드들이 뻗어 나가는 형태로, 사이클(cycle)이 없다.
실생활 예: 파일 시스템의 디렉토리 구조, 조직도, HTML DOM 트리 등.

---

## 트리 자료형의 특징:
- 노드가 N개이면 간선은 항상 **N-1개**이다.
- 루트(Root)는 단 하나이며, 부모가 없는 유일한 노드이다.
- 임의의 두 노드 사이에는 **유일한 경로**가 존재한다.
- 사이클(cycle)이 존재하지 않는다 (비순환 그래프).

## 트리 노드 종류:
| 종류 | 설명 |
|---|---|
| 루트 노드 (Root) | 부모가 없는 최상위 노드. 트리당 1개 |
| 내부 노드 (Internal) | 자식이 하나 이상 있는 노드 |
| 단말 노드 (Leaf) | 자식이 없는 노드 (리프 노드) |
| 부모 노드 (Parent) | 자신보다 한 단계 위의 연결된 노드 |
| 자식 노드 (Child) | 자신보다 한 단계 아래의 연결된 노드 |
| 형제 노드 (Sibling) | 같은 부모를 가진 노드 |
| 조상 노드 (Ancestor) | 루트까지 경로 상에 있는 모든 노드 |

---

## 이진 트리:
각 노드의 자식 노드 수가 **최대 2개(왼쪽, 오른쪽)**인 트리.
모든 이진 트리 노드는 `left` 포인터와 `right` 포인터를 가진다.

## 이진 트리의 특징:
- 높이가 h인 이진 트리의 최대 노드 수: **2^(h+1) - 1**
- 높이가 h인 이진 트리의 최소 노드 수: **h + 1** (한쪽으로 치우친 경사 트리)
- n개의 노드를 가진 이진 트리의 높이: 최소 **⌊log₂n⌋**, 최대 **n-1**
- **포화 이진 트리(Full BT)**: 모든 레벨이 꽉 찬 트리. 노드 수 = 2^(h+1) - 1
- **완전 이진 트리(Complete BT)**: 마지막 레벨을 제외하고 모두 채워져 있으며, 마지막 레벨은 왼쪽부터 채워진 트리
- **경사 이진 트리(Skewed BT)**: 모든 노드가 왼쪽 또는 오른쪽 한 방향으로만 이어진 트리

## 이진 트리의 높이, 레벨, 깊이:
- **레벨(Level)**: 루트 노드를 레벨 0(또는 1)으로 시작하여 아래로 내려갈수록 1씩 증가
- **높이(Height)**: 트리에서 가장 깊은 노드의 레벨 (리프 노드까지의 최대 거리)
- **깊이(Depth)**: 특정 노드에서 루트까지의 거리 (루트의 깊이 = 0)

```
       A        ← 레벨 0 (루트)
      / \
     B   C      ← 레벨 1
    / \ /
   D  E F       ← 레벨 2 (높이 = 2)
```

---

## 이진트리의 표현방법:

### 1. 배열 표현법 (Array Representation)
노드를 배열 인덱스로 매핑한다.
- 루트: 인덱스 1
- 노드 i의 왼쪽 자식: 인덱스 **2i**
- 노드 i의 오른쪽 자식: 인덱스 **2i + 1**
- 노드 i의 부모: 인덱스 **⌊i/2⌋**
- 단점: 경사 트리일 경우 배열 공간 낭비가 심하다.

### 2. 링크 표현법: 노드를 이용
각 노드가 `data`, `left 포인터`, `right 포인터`를 가지는 구조체로 표현한다.
동적 메모리 할당을 사용하여 필요한 노드만큼만 공간을 사용한다.

---

## TreeRep.c 코드에 대해서 기능을 설명

```c
typedef char TElement;
typedef struct TNode {
    TElement data;       // 노드가 저장하는 데이터 (문자형)
    struct TNode* left;  // 왼쪽 자식 노드를 가리키는 포인터
    struct TNode* right; // 오른쪽 자식 노드를 가리키는 포인터
} TNode;
```
- `TNode` 구조체가 이진 트리 노드를 표현하는 링크 표현법의 핵심이다.

```c
TNode *create_tree(TElement data, TNode* left, TNode* right) {
    TNode* node = (TNode*)malloc(sizeof(TNode));
    if (node != NULL) {
        node->data = data;
        node->left = left;
        node->right = right;
    }
    return node;
}
```
- `malloc`으로 힙 메모리에 새 노드를 동적 할당한다.
- `data`, `left`, `right`를 인자로 받아 노드를 초기화한 뒤 포인터를 반환한다.

```c
void delete_tree(TNode* node) {
    if (node != NULL) {
        delete_tree(node->left);
        delete_tree(node->right);
        free(node);
    }
}
```
- **후위 순회(postorder)** 방식으로 자식 노드부터 먼저 해제하고, 마지막에 자신을 `free`한다.
- 이 순서가 중요한 이유: 부모를 먼저 해제하면 자식 노드의 주소를 잃어버려 메모리 누수가 발생한다.

```c
// main()에서 구성하는 트리 구조:
//        A
//       / \
//      B   C
//     / \ / \
//    D  E F  G
TNode* d = create_tree('D', NULL, NULL); // 리프 노드
TNode* e = create_tree('E', NULL, NULL); // 리프 노드
TNode* b = create_tree('B', d, e);       // D, E를 자식으로 갖는 B
TNode* f = create_tree('F', NULL, NULL); // 리프 노드
TNode* g = create_tree('G', NULL, NULL); // 리프 노드
TNode* c = create_tree('C', f, g);       // F, G를 자식으로 갖는 C
TNode* root1 = create_tree('A', b, c);   // B, C를 자식으로 갖는 루트 A
```
- 리프 노드부터 bottom-up 방식으로 트리를 조립한다.
- 출력: `Root: A`, `Left Child: B`, `Right Child: C`

---

## 순회(Traversal):
트리의 모든 노드를 **정해진 순서대로 한 번씩 방문**하는 것.
이진 트리의 순회는 현재 노드(V), 왼쪽 서브트리(L), 오른쪽 서브트리(R)의 방문 순서에 따라 구분된다.

## 전위 순회 (Preorder): V → L → R
현재 노드를 **먼저** 방문한 뒤 왼쪽, 오른쪽 순으로 재귀 호출한다.
- 용도: 트리를 복사하거나 직렬화(serialize)할 때 유용

## 중위 순회 (Inorder): L → V → R
왼쪽 서브트리를 다 방문한 뒤 현재 노드, 그다음 오른쪽 서브트리를 방문한다.
- 용도: **이진 탐색 트리(BST)**에서 중위 순회하면 오름차순 정렬된 결과를 얻는다.

## 후위 순회 (Postorder): L → R → V
왼쪽·오른쪽 서브트리를 모두 방문한 뒤 현재 노드를 방문한다.
- 용도: 트리를 삭제하거나 디렉토리의 크기를 계산할 때 유용 (자식 먼저 처리)

## 레벨 순회 (Level-order):
루트부터 레벨 순서대로(위→아래, 왼→오른쪽) 방문한다.
- **큐(Queue)**를 사용하여 구현한다 (BFS 방식).

---

## TreeTraversal.c 코드에 대해서 기능을 설명

```c
#define VisitNode(n) (printf("[%c] ", (n)->data))
```
- 노드를 "방문"하는 동작을 매크로로 추상화. 출력 형식 변경 시 한 곳만 수정하면 된다.

```c
void preorder(TNode* node) {    // 전위: V → L → R
    if (node != NULL) {
        VisitNode(node);          // 1. 현재 노드 방문
        preorder(node->left);     // 2. 왼쪽 서브트리
        preorder(node->right);    // 3. 오른쪽 서브트리
    }
}
```

```c
void inorder(TNode* node) {     // 중위: L → V → R
    if (node != NULL) {
        inorder(node->left);      // 1. 왼쪽 서브트리
        VisitNode(node);          // 2. 현재 노드 방문
        inorder(node->right);     // 3. 오른쪽 서브트리
    }
}
```

```c
void postorder(TNode* node) {   // 후위: L → R → V
    if (node != NULL) {
        postorder(node->left);    // 1. 왼쪽 서브트리
        postorder(node->right);   // 2. 오른쪽 서브트리
        VisitNode(node);          // 3. 현재 노드 방문
    }
}
```

```c
// main()에서 구성하는 트리 구조 (스택 변수로 직접 생성):
//        A
//       / \
//      B   C
//     / \ /
//    D  E F
TNode d = {'D', NULL, NULL};
TNode e = {'E', NULL, NULL};
TNode b = {'B', &d, &e};
TNode f = {'F', NULL, NULL};
TNode c = {'C', &f, NULL};   // C의 오른쪽 자식은 없음
TNode a = {'A', &b, &c};
TNode* root = &a;
```
- TreeRep.c와 달리 `malloc` 없이 **스택(지역변수)**으로 노드를 생성했다. 함수 종료 시 자동 해제되므로 `delete_tree`가 필요 없다.

**순회 결과:**
```
IN-order  (L→V→R): [D] [B] [E] [A] [F] [C]
PRE-order (V→L→R): [A] [B] [D] [E] [C] [F]
POST-order(L→R→V): [D] [E] [B] [F] [C] [A]
```

**결과 도출 과정 (트리 기준):**
```
       A
      / \
     B   C
    / \ /
   D  E F
```
| 순회 | 방문 순서 이유 |
|---|---|
| 전위 | A → (B → D → E) → (C → F) |
| 중위 | (D → B → E) → A → (F → C) |
| 후위 | (D → E → B) → (F → C) → A |

---

## 노드 개수 구하기: 왼쪽 서브 노드 수 + 오른쪽 서브 노드 수 + 1
재귀적으로 정의된다:
```c
int count_nodes(TNode* node) {
    if (node == NULL) return 0;
    return count_nodes(node->left) + count_nodes(node->right) + 1;
}
```
- 기저 조건: 노드가 `NULL`이면 0을 반환.
- 재귀 단계: 왼쪽 서브트리 수 + 오른쪽 서브트리 수 + 자기 자신(1).

---

## 이진 탐색 트리 정의(조건):
이진 탐색 트리(Binary Search Tree, BST)는 아래 4가지 조건을 동시에 만족하는 이진 트리이다.

1. **모든 노드는 유일한 키를 갖는다** → 중복 키를 허용하지 않아 각 노드를 키로 특정할 수 있다.
2. **왼쪽 서브 트리의 모든 키는 루트 노드의 키보다 작다** → `left->key < node->key`
3. **오른쪽 서브 트리의 모든 키는 루트 노드의 키보다 크다** → `right->key > node->key`
4. **왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다** → 조건이 재귀적으로 적용됨

**BST 예시:**
```
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13
```
- 중위 순회(inorder) 시 → `1 3 4 6 7 8 10 13 14` (오름차순 정렬)
- 탐색 시간복잡도: 평균 **O(log n)**, 최악(경사 트리) **O(n)**

삭제 연산
case 1: 삭제할 노드가 (단말 노드)리프 노드인 경우 → 단순히 노드를 제거한다.
case 2: 삭제할 노드가 자식이 하나인 경우 → 자식 노드를 삭제할 노드의 위치로 올린다.
case 3: 삭제할 노드가 자식이 둘인 경우 → 오른쪽 서브 트리에서 가장 작은 노드(후계자)를 찾아 삭제할 노드의 위치로 올린다. 후계자는 삭제할 노드보다 크지만 오른쪽 서브 트리에서 가장 작은 노드이므로 삭제할 노드의 왼쪽 서브 트리보다 작다. 후계자를 삭제할 노드의 위치로 올린 뒤, 후계자가 원래 있던 위치에서는 case 1 또는 case 2로 처리한다.

BinSrchTree.c 기능 설명:
'''c
'''
'''c
'''
'''c
'''
...

// 노드의 키(데이터) 접근 매크로 — lvalue로도 사용 가능하여 값 변경에도 쓰임
#define KEY(n) ((n)->data)
// 노드 방문 시 데이터를 출력하는 매크로
#define VisitNode(n) (printf("[%c] ", (n)->data))

#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

// 새 노드를 동적 할당하고 data, left, right를 초기화하여 반환
TNode *create_tree(TElement data, TNode* left, TNode* right) {
    TNode* node = (TNode*)malloc(sizeof(TNode));
    if (node != NULL) {
        node->data = data;
        node->left = left;
        node->right = right;
    }
    return node;
}

// 후위 순회(post-order)로 모든 노드를 재귀적으로 해제
void delete_tree(TNode* node) {
    if (node != NULL) {
        delete_tree(node->left);
        delete_tree(node->right);
        free(node);
    }
}

// BST 탐색: key < 현재 노드 → 왼쪽, key > 현재 노드 → 오른쪽으로 재귀 탐색
// 찾으면 해당 노드 포인터 반환, 없으면 NULL 반환
TNode* search_bst(TNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == KEY(root)) {
        return root;
    }
    if (key < KEY(root)) {
        return search_bst(root->left, key);
    } else {
        return search_bst(root->right, key);
    }
}

// BST 삭제: 삭제 후 변경된 루트를 반환
// 삭제 대상이 없으면 트리를 그대로 반환
TNode *delete_bst(TNode *root, int key) {
    TNode *n = root;
    TNode *parent = NULL;

    // 삭제할 노드(n)와 그 부모(parent)를 탐색
    while (n != NULL && KEY(n) != key) {
        parent = n;
        if (key < KEY(n)) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    if (n == NULL) {
        return root; // 키가 트리에 없음
    }

    if (n->left == NULL && n->right == NULL) {
        // Case 1: 단말 노드(자식 없음) — 부모 링크를 끊고 해제
        if (parent == NULL) {
            root = NULL; // 루트 자체가 유일한 노드
        } else {
            if (parent->left == n) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        free(n);

    } else if (n->left == NULL || n->right == NULL) {
        // Case 2: 자식이 하나 — 자식으로 바이패스하고 해제
        TNode *child = (n->left != NULL) ? n->left : n->right;
        if (parent == NULL) {
            root = child; // 루트를 자식으로 교체
        } else {
            if (parent->left == n) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        free(n);

    } else {
        // Case 3: 자식이 둘 — 중위 후계자(오른쪽 서브트리의 최솟값)로 대체

        // 후계자 = 오른쪽 서브트리에서 가장 왼쪽 노드
        TNode *successor = n->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        TElement temp = KEY(successor);
        root = delete_bst(root, temp); // 후계자 노드를 재귀적으로 삭제
        KEY(n) = temp;                 // 현재 노드의 키를 후계자 키로 덮어씀
    }
    return root;
}

void preorder(TNode* node) {
    if (node != NULL) {
        VisitNode(node);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {

    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    // BST 생성: A(50) → B(30), C(70) → D(20), E(40), F(60), G(80)
    TNode* d = create_tree(keys[0], NULL, NULL);
    TNode* e = create_tree(keys[1], NULL, NULL);
    TNode* b = create_tree(keys[2], d, e);
    TNode* f = create_tree(keys[3], NULL, NULL);
    TNode* g = create_tree(keys[4], NULL, NULL);
    TNode* c = create_tree(keys[5], f, g);
    TNode* root = create_tree(keys[6], b, c);

    printf("Pre-order before deletion: ");
    preorder(root);
    printf("\n");

    // 노드 삭제 테스트
    root = delete_bst(root, keys[2]); // 자식 2개인 노드 삭제
    printf("Pre-order after deleting 'B': ");
    preorder(root);
    printf("\n");

    root = delete_bst(root, keys[3]); // 단말 노드 삭제
    printf("Pre-order after deleting 'F': ");
    preorder(root);
    printf("\n");

    root = delete_bst(root, keys[5]); // 자식 2개인 노드 삭제
    printf("Pre-order after deleting 'C': ");
    preorder(root);
    printf("\n");

    delete_tree(root); // 메모리 해제
    return 0;
}



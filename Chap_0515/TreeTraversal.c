#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define VisitNode(n) (printf("[%c] ", (n)->data))

void preorder(TNode* node) {
    if (node != NULL) {
        VisitNode(node);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(TNode* node) {
    if (node != NULL) {
        inorder(node->left);
        VisitNode(node);
        inorder(node->right);
    }
}

void postorder(TNode* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        VisitNode(node);
    }
}

int main() {
    TNode d = {'D', NULL, NULL};
    TNode e = {'E', NULL, NULL};
    TNode b = {'B', &d, &e};
    TNode f = {'F', NULL, NULL};
    TNode c = {'C', &f, NULL};
    TNode a = {'A', &b, &c};
    TNode* root = &a;

    printf("IN-order: ");
    inorder(root);
    printf("\n");

    printf("PRE-order: ");
    preorder(root);
    printf("\n");
    
    printf("POST-order: ");
    postorder(root);
    printf("\n");

    return 0;
}
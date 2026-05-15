#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode *create_tree(TElement data, TNode* left, TNode* right) {
    TNode* node = (TNode*)malloc(sizeof(TNode));
    if (node != NULL) {
        node->data = data;
        node->left = left;
        node->right = right;
    }
    return node;
}

void delete_tree(TNode* node) {
    if (node != NULL) {
        delete_tree(node->left);
        delete_tree(node->right);
        free(node);
    }
}

int main() {
    TNode* d = create_tree('D', NULL, NULL);
    TNode* e = create_tree('E', NULL, NULL);
    TNode* b = create_tree('B', d, e);
    TNode* f = create_tree('F', NULL, NULL);
    TNode* g = create_tree('G', NULL, NULL);
    TNode* c = create_tree('C', f, g);
    TNode* root1 = create_tree('A', b, c);

    printf("Root: %c\n", root1->data);
    printf("Left Child: %c\n", root1->left->data);
    printf("Right Child: %c\n", root1->right->data);

    delete_tree(root1);
    return 0;
}

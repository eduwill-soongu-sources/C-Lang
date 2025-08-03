#include <stdio.h>
#include <stdlib.h>

// 이진 트리의 노드를 표현하는 구조체
typedef struct TreeNode {
    int data;              // 노드가 저장할 데이터
    struct TreeNode* left; // 왼쪽노드를 가리키는 포인터
    struct TreeNode* right; // 오른쪽노드를 가리키는 포인터
} TreeNode;

int main(void) {

    TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    // n1을 루트로 만들고 n2와 n3를 연결
    n1->left = n2;
    n1->right = n3;

    // 리프노드는 반드시 명시적으로 자식을 NULL로 초기화합니다.
    n2->left = NULL;
    n2->right = NULL;

    n3->left = NULL;
    n3->right = NULL;

    printf("루트 노드의 데이터: %d\n", n1->data);
    printf("루트의 왼쪽 노드의 데이터: %d\n", n1->left->data);
    printf("루트의 오른쪽 노드의 데이터: %d\n", n1->right->data);

    // 사용이 끝난 노드들의 메모리 해제
    free(n1);
    free(n2);
    free(n3);
    
    return 0;
}
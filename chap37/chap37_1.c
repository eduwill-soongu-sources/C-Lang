#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;              // 노드가 저장할 데이터
    struct TreeNode* left; // 왼쪽노드를 가리키는 포인터
    struct TreeNode* right; // 오른쪽노드를 가리키는 포인터
} TreeNode;

// 새로운 트리의 노드를 생성하고 포인터처리를 해주는 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// 트리구조를 만들기위해 포인터를 연결해주는 함수
void linkNodes(TreeNode* parent, TreeNode* left, TreeNode* right) {
    parent->left = left;
    parent->right = right;
}


// 전위 순회 함수
void preorder(TreeNode* node) {
    // 재귀를 멈추는 조건: 더이상 내려갈곳이 없으면 중단
    if (node == NULL) return;

    // 1. 중 : 현재 노드를 처리
    printf("[%d] ", node->data);

    // 2. 왼 : 왼쪽 서브트리로 재귀 이동
    preorder(node->left);

    // 3. 오 : 오른쪽 서브트리로 재귀 이동
    preorder(node->right);
}

// 중위 순회 함수
void inorder(TreeNode* node) {
    // 재귀를 멈추는 조건: 더이상 내려갈곳이 없으면 중단
    if (node == NULL) return;

    // 1. 왼 : 왼쪽 서브트리로 재귀 이동
    inorder(node->left);

    // 2. 중 : 현재 노드를 처리
    printf("[%d] ", node->data);

    // 3. 오 : 오른쪽 서브트리로 재귀 이동
    inorder(node->right);
}

// 후위 순회 함수
void postorder(TreeNode* node) {
    // 재귀를 멈추는 조건: 더이상 내려갈곳이 없으면 중단
    if (node == NULL) return;

    // 1. 왼 : 왼쪽 서브트리로 재귀 이동
    postorder(node->left);

    // 2. 오 : 오른쪽 서브트리로 재귀 이동
    postorder(node->right);

    // 3. 중 : 현재 노드를 처리
    printf("[%d] ", node->data);
}



int main(void) {

        /*
        
                10
               /  \
              20  30
              /\    \
            40 50   60
        */
    // 1단계: 트리에 필요한 노드를 생성합니다.
    TreeNode* root = createNode(10);
    TreeNode* n20 = createNode(20);
    TreeNode* n30 = createNode(30);
    TreeNode* n40 = createNode(40);
    TreeNode* n50 = createNode(50);
    TreeNode* n60 = createNode(60);

    // 2단계: 생성된 노드들을 연결하여 트리구조 완성
    linkNodes(root, n20, n30);
    linkNodes(n20, n40, n50);
    linkNodes(n30, NULL, n60);

    printf("### 전위 순회 결과 ###\n");
    preorder(root);
    printf("끝! \n\n");

    printf("### 중위 순회 결과 ###\n");
    inorder(root);
    printf("끝! \n\n");

    printf("### 후위 순회 결과 ###\n");
    postorder(root);
    printf("끝! \n\n");

    
    return 0;
}
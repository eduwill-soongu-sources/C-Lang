#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트의 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 특정 노드(prev_node) 바로 뒤에 새 노드를 삽입하는 함수
void insertAfter(Node* prev_node, int new_data) {
    // 1. 새 노드 생성 및 데이터 세팅
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;

    // 2. 새 노드에 next, prev를 먼저 세팅
    // 새 노드의 next는 원래 prev_node가 갖고있던 next
    newNode->next = prev_node->next;
    // 새 노드의 prev는 원래 prev_node 주소 그자체를 세팅
    newNode->prev = prev_node;

    // 3. 뒷노드의 연결고리 변경
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    // 4. 앞노드의 연결고리 변경
    prev_node->next = newNode;
}

// 정방향 출력
void printForward(Node* node) {
    printf("정방향 출력: [ ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("]\n");
}

// 특정 노드를 삭제하는 함수
void deleteNode(Node** head, Node* target_node) {
    // 리스트가 비어있거나 삭제할노드가 없으면 강제종료
    if (*head == NULL || target_node == NULL) return;

    // 경우1: 삭제대상이 head인 경우
    if (*head == target_node) {
        *head = target_node->next;
    }

    // 경우2: 삭제할 노드가 마지막 노드가 아닌 경우
    if (target_node->next != NULL) {
        target_node->next->prev = target_node->prev;
    }
    // 경우3: 삭제할 노드가 첫노드가 아닌경우
    if (target_node->prev != NULL) {
        target_node->prev->next = target_node->next;
    }
    free(target_node);

}

// 리스트를 역방향으로 출력하는 함수
void printBackward(Node* head) {

    // 1. 마지막 노드 찾기
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // 2. 마지막 노드부터 역방향으로 순회하며 출력
    printf("역방향 출력: [ ");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("]\n");
}


int main(void) {

    Node* firstNode = (Node*)malloc(sizeof(Node));
    firstNode->data = 10;
    firstNode->prev = NULL;
    firstNode->next = NULL;

    Node* head = firstNode;

    insertAfter(firstNode, 20);
    insertAfter(firstNode->next, 35);
    insertAfter(firstNode->next->next, 47);
    insertAfter(firstNode->next->prev, 13);

    printf("# 삭제 전: ");
    printForward(head);

    deleteNode(&head, head->next);

    printf("# 삭제 후: ");
    printForward(head);
    printBackward(head);

    return 0;
}
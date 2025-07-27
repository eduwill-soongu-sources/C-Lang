#include <stdio.h>
#include <stdlib.h>

// 연결리스트의 기본 단위 노드 구조체 정의
typedef struct Node {
    int data;    // 실제로 저장할 값
    struct Node* next; // 다음 노드의 주소를 저장할 포인터
} Node;

// 맨 앞에 새 데이터를 추가하는 로직
void insertAtBeginning(Node** head, int new_data) {
    // 1. 새노드 동적 할당, 실제 데이터를 저장
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;

    // 2. 새 노드의 next포인터를 기존 헤드가 가지고있던 주소로 저장
    newNode->next = *head;
    *head = newNode;
}

// 연결리스트의 모든 값을 출력하는 함수
void printList(Node* node) {
    while( node != NULL ) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 맨 뒤에 노드를 추가하는 함수
void insertAtEnd(Node** head, int new_data) {
    // 1. 새 노드 생성 및 데이터 세팅
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new_data;
    newNode->next = NULL; // 이 노드는 맨 뒤에 추가되는 노드이므로

    // 만약 리스트가 비어있는 상태라면 새노드가 head가 됨
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // 2. 마지막 노드를 찾기 위해 head부터 반복 탐색 시작
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // 3. 마지막 노드를 찾았으면 그 next에 새 노드를 연결
    last->next = newNode;
}

// 연결리스트의 모든 노드 메모리를 해제하는 함수
void freeList(Node** head) {
    // 해제해버리면 next의 주소가 없어지니까 next를 백업하면서 처리
    Node* current = *head;
    Node* next_node;  // next주소 백업용

    while(current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    // head의 주소를 NULL로 만들어서 리스트가 비었음을 표시
    *head = NULL;
}

int main(void) {

    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 5);

    insertAtEnd(&head, 999);
    insertAtEnd(&head, 7777);
    insertAtEnd(&head, 8000);

    insertAtBeginning(&head, -456);

    printList(head);
    freeList(&head);
    
    return 0;
}
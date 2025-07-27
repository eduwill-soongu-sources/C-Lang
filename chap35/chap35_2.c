#include <stdio.h>
#include <stdlib.h>

// 연결리스트의 노드 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 큐 구조체
typedef struct {
    Node* front;  // 큐의 시작점 (head)
    Node* rear;   // 큐의 끝점   (tail)
} LinkedQueue;

// 큐 초기화 함수
void init_queue(LinkedQueue* q) {
    q->front = q->rear = NULL;
}

// 큐가 비었는지 확인
int is_empty(LinkedQueue* q) {
    return q->front == NULL && q->rear == NULL;
}

// 연결리스트로 구현한 enqueue
void enqueue(LinkedQueue* q, int item) {
    // 1. 새 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    // 2. 큐가 비었는지 확인
    if (is_empty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 연결리스트 큐로 dequeue 구현
int dequeue(LinkedQueue* q) {
    if (is_empty(q)) {
        printf("큐가 비어있습니다.\n");
        exit(1);
    }
    // 1. 임시포인터에 제거할 노드를 백업
    Node* temp = q->front;
    int removed = temp->data;

    // 2. front를 다음 노드로 이동
    q->front = q->front->next;

    // 3. 만약 dequeue후 큐가 비어있게 된다면
    if (q->front == NULL) {
        q->rear = NULL;
    }
    // 4. 제거된 노드를 메모리해제
    free(temp);
    return removed;
}

int main(void) {

    LinkedQueue q;
    init_queue(&q);

    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    enqueue(&q, 400);
    enqueue(&q, 500);

    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));

    enqueue(&q, 9999);
    printf("dequeue: %d\n", dequeue(&q));
    
    return 0;
}
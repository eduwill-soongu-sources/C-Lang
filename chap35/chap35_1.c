#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} CircularQueue;

// 큐 초기화 함수
void init_queue(CircularQueue* q) {
    q->front = q->rear = 0;
}

// 큐가 비어있는지 확인
int is_empty(CircularQueue* q) {
    return q->front == q->rear;
}
// 큐가 꽉찼는지 확인
int is_full(CircularQueue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
// 큐에 데이터를 넣는 기능
void enqueue(CircularQueue* q, int item) {
    if (is_full(q)) {
        printf("큐가 꽉찼습니다!\n");
        return;
    }
    // rear를 한 칸 이동
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    // 이동한 자리로 데이터를 삽입
    q->data[q->rear] = item;
}

// 큐에서 데이터를 뽑아내는 기능
int dequeue(CircularQueue* q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다!");
        exit(1);
    }
    // front를 한 칸 이동
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 원형 큐의 모든 요소를 출력하는 함수
void print_queue(CircularQueue* q) {
    if (is_empty(q)) {
        printf("Queue [ ]\n");
    }
    printf("Queue: [ ");
    int i = q->front;
    // front의 다음 위치부터 시작해서 rear까지 순회
    while (i != q->rear) {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%d ", q->data[i]);
    }
    printf("]\n");
}

int main(void) {

    CircularQueue q;
    init_queue(&q);

    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);

    print_queue(&q);

    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));

    enqueue(&q, 88);
    print_queue(&q);
    
    return 0;
}
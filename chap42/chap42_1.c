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

#define MAX_VERTICES 50

// 간선 연결리스트의 노드를 위한 구조체
typedef struct GraphNode {
    int vertex; // 연결된 정점의 번호
    struct GraphNode* link; // 다음 노드를 가리킬 포인터
} GraphNode;

// 인접 리스트 그래프를 관리하는 구조체
typedef struct {
    int n; // 실제 정점 개수
    GraphNode* adj_list[MAX_VERTICES]; // 각 정점의 연결리스트 시작주소를 담을 포인터배열
} GraphList;

// 그래프 초기화 함수
void init_graph(GraphList* g) {
    g->n = 0;
    // 모든 연결리스트의 시작주소를 NULL로 초기화
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

// 정점을 추가하는 함수
void insert_vertex(GraphList* g) {
    if (g->n + 1 > MAX_VERTICES) {
        printf("그래프: 정점 개수 초과!\n");
        return;
    }
    g->n++;
}

// 간선을 추가하는 함수 (무방향 그래프)
void insert_edge(GraphList* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        printf("그래프: 정점 번호 오류!\n");
        return;
    }

    // start를 end의 인접리스트에 추가 (맨 앞 삽입)
    GraphNode* node1 = (GraphNode*)malloc(sizeof(GraphNode));
    node1->vertex = end;
    node1->link = g->adj_list[start];
    g->adj_list[start] = node1;

    // end를 start의 인접리스트에 추가
    GraphNode* node2 = (GraphNode*)malloc(sizeof(GraphNode));
    node2->vertex = start;
    node2->link = g->adj_list[end];
    g->adj_list[end] = node2;
}

// ===== 방문 배열 만들기 ===== //
int visited[MAX_VERTICES];


// 너비 우선 탐색 (bfs 구현)
void bfs(GraphList* g, int v) {
    LinkedQueue q;
    GraphNode* w;

    init_queue(&q);

    // 1. 시작 정점 v를 방문 처리하고 큐에 삽입
    visited[v] = 1;
    printf("vertex %d -> ", v);
    enqueue(&q, v);

    // 2. 큐가 빌 때까지 이웃들을 너비우선으로 반복탐색
    while(!is_empty(&q)) {
        // 3. 큐에 가장 오래대기한 정점을 꺼냄
        v = dequeue(&q);

        // 4. 큐에서 꺼낸 정점의 모든 이웃들을 반복순회
        for (w = g->adj_list[v]; w != NULL; w = w->link) {
            // 5. 만약 이웃 w가 아직 방문되지 않았다면
            if (!visited[w->vertex]) {
                // 6. 방문처리하고 큐에 삽입
                visited[w->vertex] = 1;
                printf("vertex %d -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}


int main(void) {
    
    GraphList g;

    init_graph(&g);

    // 7개의 정점 생성
    for (int i = 0; i < 7; i++) {
        insert_vertex(&g);
    }

    /*    
          0
        /   \
       1      2
       | \    |
       3  4 - 5
               \
                6
     */
    insert_edge(&g, 0, 1);
    insert_edge(&g, 0, 2);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 5);
    insert_edge(&g, 4, 5);
    insert_edge(&g, 5, 6);

    // 탐색 시작전 visited배열을 모두 false(0)으로 세팅
    for (int i = 0; i < g.n; i++) {
        visited[i] = 0;
    }


    printf("\n===== bfs queue version ====\n");
    bfs(&g, 0);

    return 0;
}
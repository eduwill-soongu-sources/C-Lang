#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// 연결리스트의 노드 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top; 
} LinkedStack;

void init_stack(LinkedStack* s) {
    s->top = NULL;
}
int is_empty(LinkedStack* s) {
    return s->top == NULL;
}
// is_full: 안만들어도 됨

void push(LinkedStack* s, int item) {
    // 1. 새 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;

    // 2. 새 노드가 기존의 top을 가리키도록 연결
    newNode->next = s->top;
    // 3. top포인터가 새 노드를 가리키도록 함
    s->top = newNode;
}

int pop(LinkedStack* s) {
    if (is_empty(s)) {
        printf("스택이 텅 비었습니다!\n");
        exit(1);
    }

    // 1. 임시포인터에 현재 top노드를 백업한 뒤 값추출
    Node* temp = s->top;
    int item = temp->data;

    // 2. top을 이동
    s->top = s->top->next;

    // 3. 이전 top의 메모리 해제
    free(temp);
    return item;
}


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

// 인접 리스트를 출력하는 함수
void print_adj_list(GraphList* g) {
    for (int i = 0; i < g->n; i++) {
        printf("정점 %d의 인접 리스트: ", i);
        GraphNode* p = g->adj_list[i];
        while (p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

// ===== 방문 배열 만들기 ===== //
int visited[MAX_VERTICES];



// ===== dfs 스택 버전 ==== //
void dfs_stack(GraphList* g, int v) {
    // 스택을 생성
    LinkedStack s;

    GraphNode* w;

    init_stack(&s);
    // 1. 시작 정점 v를 스택에 push
    push(&s, v);

    // 2. 스택이 빌 때까지 DFS를 반복
    while (!is_empty(&s)) {
        // 3. 스택에서 정점을 pop해서 방문
        v = pop(&s);

        // 4. pop한 정점이 아직 방문하지 않은 곳이라면
        if (!visited[v]) {
            // 5. 방문 처리
            visited[v] = 1;
            printf("vertex %d -> ", v);

            // 6. 그 정점의 모든 방문하지 않은 이웃들을 스택에 push
            for (w = g->adj_list[v]; w != NULL; w = w->link) {
                if (!visited[w->vertex]) {
                    push(&s, w->vertex);
                }
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


    printf("\n===== dfs stack version ====\n");
    dfs_stack(&g, 0);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

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

// 재귀함수를 통한 깊이 우선 탐색     v: 방문할 정점
void dfs_recursive(GraphList* g, int v) {

    // 노드를 저장할 변수
    GraphNode* w;    

    // 1. 현재 정점 v를 방문했음으로 체크
    visited[v] = 1; // 1은 true를 의미
    printf("vertex %d visited -> ", v);

    // 2. 현재 방문한 정점 v의 인접(연결된) 정점들을 순회
    for (w = g->adj_list[v]; w != NULL; w = w->link) {
        // 3. 만약 방문한 w가 아직 방문하지 않은 곳이라면
        if (!visited[w->vertex]) {
            // 4. 다시 그곳으로 이동해서 dfs를 재수행
            dfs_recursive(g, w->vertex);
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


    printf("\n===== dfs 재귀버전 ====\n");
    dfs_recursive(&g, 0);


    return 0;
}
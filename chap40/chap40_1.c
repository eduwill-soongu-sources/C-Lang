#include <stdio.h>

// 최대 정점 개수 정의
#define MAX_VERTICES 50

// 인접 행렬 그래프를 표현하는 구조체
typedef struct {
    int n; // 실제 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphMatrix;

// 그래프 초기화 함수
void init_graph(GraphMatrix* g) {
    g->n = 0;
    for (int r = 0; r < MAX_VERTICES; r++) {
        for (int c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점을 추가하는 함수
void insert_vertex(GraphMatrix* g) {
    if (g->n + 1 > MAX_VERTICES) {
        printf("그래프: 정점 개수 초과!\n");
        return;
    }
    g->n++;
}

// 간선을 추가하는 함수 (무방향 그래프)
void insert_edge(GraphMatrix* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        printf("그래프: 정점 번호 오류!\n");
        return;
    }

    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 그래프를 출력하는 함수
void print_adj_mat(GraphMatrix* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}


int main(void) {

    GraphMatrix g;

    init_graph(&g);

    // 5개의 정점 생성
    for (int i = 0; i < 5; i++) {
        insert_vertex(&g);
    }

    // 간선 연결
    /*
             0
            / \
           1---2
           | \
           3--4 
    */
   insert_edge(&g, 0, 1);
   insert_edge(&g, 0, 2);
   insert_edge(&g, 1, 2);
   insert_edge(&g, 1, 3);
   insert_edge(&g, 1, 4);
   insert_edge(&g, 3, 4);
    
    printf("## 인접 행렬 출력:\n");
    print_adj_mat(&g);

    return 0;
}
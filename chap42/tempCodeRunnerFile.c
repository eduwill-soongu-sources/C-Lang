void bfs(GraphList* g, int v) {
    LinkedQueue q;
    GraphNode* w;

    init_queue(&q);
    // 1. 시작 정점 v를 방문 처리하고 큐에 삽입
    visited[v] = 1;
    printf("vertex %d -> ", v);
    enqueue(&q, v);

    // 2. 큐가 빌 때까지 반복
    while (!is_empty(&q)) {
        // 3. 큐에서 정점을 하나 꺼냄
        v = dequeue(&q);

        // 4. 꺼낸 정점의 모든 이웃 w를 확인
        for (w = g->adj_list[v]; w != NULL; w = w->link) {
            // 5. 만약 이웃 w가 아직 방문하지 않았다면
            if (!visited[w->vertex]) {
                // 방문 처리하고 큐에 삽입
                visited[w->vertex] = 1;
                printf("vertext %d -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }
}




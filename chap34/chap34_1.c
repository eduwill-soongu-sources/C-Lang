#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct {
    int data[MAX_STACK_SIZE]; // 데이터를 쌓을 배열
    int top;    // 스택의 꼭대기를 저장할 인덱스
} Stack;

// 스택 초기화 함수
void init_stack(Stack* s) {
    s->top = -1;  // 스택이 비어있다는 의미
}

// 스택이 가득찼는지 확인하는 함수
int is_full(Stack* s) {
    return (s->top == MAX_STACK_SIZE - 1);
}

// 스택이 비었는지 확인하는 함수
int is_empty(Stack* s) {
    return s->top == -1;
}
// 스택에 데이터를 넣는 함수
void push(Stack* s, int item) {
    if (is_full(s)) {
        printf("스택이 가득 찼습니다!!");
        return;
    }

    // top을 먼저 1 증가시키고 그 자리에 데이터를 넣음
    // s->top++;
    s->data[++(s->top)] = item;
}

// 스택에서 데이터를 꺼내는 함수
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("스택이 텅 비었습니다.\n");
        exit(1);
    }
    
    return s->data[(s->top)--];
}

int main(void) {

    Stack s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printf("stack->top: %d\n", s.data[s.top]);

    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    printf("pop: %d\n", pop(&s));
    
    return 0;
}
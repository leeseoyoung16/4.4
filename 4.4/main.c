#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STACK 100

typedef char element;
typedef struct {
    element data[MAX_STACK];
    int top;
}Stacktype;

void init_stack(Stacktype* s) {
    s->top = -1;
}

int is_full(Stacktype* s) {
    return (s->top == (MAX_STACK - 1));
}
int is_empty(Stacktype* s) {
    return(s->top == -1);
}

void push(Stacktype* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
    }
    else s->data[++(s->top)] = item; //���� �����ڴ� ��� ���� ������Ŵ
}

element pop(Stacktype* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);

    }
    else return s->data[(s->top)--]; //���� �����ڴ� ��� �Ŀ� ���ҽ�Ŵ
}


//���� ǥ�� ���� ��� �Լ�
int eval(char exp[]) {
    int op1, op2, value, i = 0;
    size_t len = strlen(exp);
    char ch;
    Stacktype s;

    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            if (ch < '0' || ch > '9') {
                fprintf(stderr, "Error: Invalid character\n");
                exit(1);
            }

            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }

    }
    return pop(&s);

}

int main(void) {
    char exp[MAX_STACK];
    int re;
    printf("Postfix expression : ");
    scanf_s("%s", exp, sizeof(exp));
    re = eval(exp);
    printf("Result : %d", re);

    return 0;

}
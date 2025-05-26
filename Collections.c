#include <stdio.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

typedef struct {
    Node* Top;
} Stack;

typedef struct {
    Node* header;
    Node* tail;
} Queue;

Node* NodeIndex(int Index, Node* start) {
    if (!start)
        return NULL;
    if (Index == 0)
        return start;
    return NodeIndex(Index - 1, start->next);
}

Node* ListIndex(int Index, List* list) {
    return NodeIndex(Index, list->head);
}

int SizeOfNode(Node* start) {
    if (!start)
        return 0;
    return 1 + SizeOfNode(start->next);
}

int SizeOfList(List* list) {
    return SizeOfNode(list->head);
}

Node* Last(Node* start) {
    if (!start || !start->next)
        return start;
    return Last(start->next);
}

void AddAt(int Index, List* list, Node* newChain) {
    Node* newChainLast = Last(newChain);

    if (Index == 0) {
        newChainLast->next = list->head;
        list->head = newChain;
        return;
    }

    Node* before = NodeIndex(Index - 1, list->head);
    if (!before) return;

    newChainLast->next = before->next;
    before->next = newChain;
}

void StackPush(Stack* s, Node* n) {
    n->next = s->Top;
    s->Top = n;
}

void StackPop(Stack* s) {
    if (!s->Top) return;
    s->Top = s->Top->next;
}

Node* StackTop(Stack* s) {
    return s->Top;
}

int StackEmpty(Stack* s) {
    return s->Top == NULL;
}


void QueueInit(Queue* q) {
    q->header = NULL;
    q->tail = NULL;
}

void Enqueue(Queue* q, Node* n) {
    n->next = NULL;
    if (q->tail)
        q->tail->next = n;
    else
        q->header = n;
    q->tail = n;
}

void Dequeue(Queue* q) {
    if (!q->header) return;
    q->header = q->header->next;
    if (!q->header)
        q->tail = NULL;
}

Node* Front(Queue* q) {
    return q->header;
}

int QueueEmpty(Queue* q) {
    return q->header == NULL;
}


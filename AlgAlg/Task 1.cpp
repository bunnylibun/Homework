#include <iostream>
using namespace std;

struct Node {
    double value;
    Node* next;
};

struct Stack {
    int size;
    int capacity;
    Node* top;
};

void init (struct Stack* s, int cap = 100) {
    s->size = 0;
    s->capacity = cap;
    s->top = NULL;
}

void push (struct Stack* s, double val) {
    if (s->size == s->capacity) {
        cout << "The stack is overflowed" << endl;
        return;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = s->top;
    s->top = newy;
    s->size++;
}

double pop (struct Stack* s, double defval = 0.0) {
    if (s->top == NULL) {
        cout << "The stack is underflowed, mistake ";
        return defval;
    }
    Node* tmp = s->top;
    double val = tmp->value;
    s->top = s->top->next;
    delete tmp;
    s->size--;
    return val;
}

double peek (struct Stack* s, double defval = 0.0) {
    if (s->top == NULL) {
        cout << "The stack is underflowed, mistake ";
        return defval;
    }
    return s->top->value;
}

int main() {
     Stack* st =  new Stack;
     init(st);
     push(st, 67);
     cout << pop(st) << endl;
     cout << pop(st) << endl;
     delete st;
     return 0;
}

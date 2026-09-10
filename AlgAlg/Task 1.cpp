#include <iostream>
using namespace std;

#define MISTAKE -1
#define SUCCESS 1
#define INTMAX 10^308

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
    s->top = nullptr;
}

int push (struct Stack* s, double val) {
    if (s->size == s->capacity) {
        return MISTAKE;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = s->top;
    s->top = newy;
    s->size++;
    return SUCCESS;
}

int pop (struct Stack* s, double &b) {
    if (s->top == nullptr) {
        return MISTAKE;
    }
    Node* tmp = s->top;
    b = tmp->value;
    s->top = s->top->next;
    delete tmp;
    s->size--;
    return SUCCESS;
}

int peek (struct Stack* s, double &b) {
    if (s->top == NULL) {
        return MISTAKE;
    }
    b = s->top->value;
    return SUCCESS;
}

int clear(struct Stack* s, double &b) {
    if (s->top == NULL) {
        return MISTAKE;
    }
    while (s->top != NULL) {
        pop(s, b);
    }
    return SUCCESS;
}

int main(void) {
    Stack* st =  new Stack;
    int size = -1, command = -1;
    double val = 0.0, b;
    int fl = 0;
    cin >> size;
    if (size <= 0) init(st);
    else init(st, size);
    do {
        cin >> command;
        switch (command){
            case 1:
                cin >> val;
                fl = push(st, val);
                if (fl == -1) cout << "The stack is overflowed" << endl;
                else cout << "Success! " << endl;
                break;
            case 2:
                if (pop(st, b) == 0) cout << "The stack is underflowed" << endl;
                else cout << "The popped value: " << b << endl;
                break;
            case 3:
                if (peek(st, b) == 0) cout << "The stack is underflowed" << endl;
                else cout << "The top is : " << b << endl;
                break;
            case 4:
                if (clear(st, b) == 0) cout << "The stack is underflowed" << endl;
                else cout << "Success! " << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Non existing command" << endl;
                break;
         }
    } while (command != 0);
    clear(st, b);
    delete(st);
    return 0;
}

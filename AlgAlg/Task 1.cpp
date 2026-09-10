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

double push (struct Stack* s, double val, double m = -1.0, double g = 1.0) {
    if (s->size == s->capacity) {
        return m;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = s->top;
    s->top = newy;
    s->size++;
    return g;
}

double pop (struct Stack* s, double defval = 0.0) {
    if (s->top == NULL) {
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
        return defval;
    }
    return s->top->value;
}

double clear(struct Stack* s, double defval = 0.0) {
    if (s->top == NULL) {
        return defval;
    }
    while (s->top != NULL) {
        pop(s);
    }
    return 1.0;
}

int main(void) {
    Stack* st =  new Stack;
    int size = -1, command = -1;
    double val = 0.0, a = 0.0;
    cin >> size;
    if (size == 0) init(st);
    else init(st, size);
    do {
        cin >> command;
        switch (command){
            case 1:
                cin >> val;
                a = push(st, val);
                if (a == -1.0) cout << "The stack is overflowed" << endl;
                else cout << "Success! " << a << endl;
                break;
            case 2:
                val = pop(st);
                if (val == 0.0) cout << "The stack is underflowed" << endl;
                else cout << "The popped value: " << val << endl;
                break;
            case 3:
                a = peek(st);
                if (a == 0.0) cout << "The stack is underflowed" << endl;
                else cout << "The top is : " << a << endl;
                break;
            case 4:
                a = clear(st);
                if (a == 0.0) cout << "The stack is underflowed" << endl;
                else cout << "Success! " << a << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Non existing command" << endl;
                break;
         }
    } while (command != 0);
    clear(st);
    delete(st);
    return 0;
}

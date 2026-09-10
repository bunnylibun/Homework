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

double push (struct Stack* s, double val, double defval = -1.0) {
    if (s->size == s->capacity) {
        return defval;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = s->top;
    s->top = newy;
    s->size++;
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
     cin >> size >> endl;
     if (size == 0) init(st);
     else init(st);
     do {
         cin >> command >>  endl;
         switch (command){
             case 1:
                 double val = 0.0;
                 cin >> val >> endl;
                 if (push(st, val) == -1.0) cout << "The stack is overflowed" << endl;
             case 2:
                 if (pop(st) == 0.0) cout << "The stack is underflowed" << endl;
                 else cout << "The popped value: " << pop(st) << endl;
             case 3:
                 if (peek(st) == 0.0) cout << "The stack is underflowed" << endl;
                 else cout << "The top is : " << peek(st) << endl;
             case 4:
                 if (clear(st) == 0.0) cout << "The stack is underflowed" << endl;
                 else cout << "Success! " << clear(st) << endl;
         }
     } while (command != 0);
     clear(st);
     return 0;
}

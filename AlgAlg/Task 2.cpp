#include <iostream>
using namespace std;

#define OVERFLOW 2
#define UNDERFLOW -1
#define SUCCESS 1

enum bunny {
    white = 0,
    black = 1
};

class Stack {
private: 
    struct Node {
        bunny value;
        Node* next;
    };
    int size;
    int capacity;
    Node* top;
public:
    Stack(int cap = 100) : size(0), capacity(cap), top(nullptr) {}
    ~Stack();

    int push(bunny val);
    int pop(bunny &b);
    int peek(bunny &b);
    int clear();
};

Stack::~Stack() {
    clear();
}

int Stack::push (bunny val) {
    if (size == capacity) {
        return OVERFLOW;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = top;
    top = newy;
    size++;
    return SUCCESS;
}

int Stack::pop (bunny &b) {
    if (top == nullptr) {
        return UNDERFLOW;
    }
    Node* tmp = top;
    b = tmp->value;
    top = top->next;
    delete tmp;
    size--;
    return SUCCESS;
}

int Stack::peek (bunny &b) {
    if (top == nullptr) {
        return UNDERFLOW;
    }
    b = top->value;
    return SUCCESS;
}

int Stack::clear() {
    if (top == nullptr) {
        return UNDERFLOW;
    }
    bunny d;
    while (top != nullptr) {
        pop(d);
    }
    return SUCCESS;
}

int main(void) {
    int size = -1, command = -1, input = -1;
    bunny val, b;
    int fl = 0;
    cin >> size;
    Stack st(size > 0 ? size : 100);
    for (int i=0; i < 1000; i++) {
        cout << "Type 0 for white bunny or 1 for black one" << endl;
        cin >> input;
        if (st.push(input) == OVERFLOW) cout << "The stack is overflowed" << endl;
        else cout << "Success! " << endl;
    }
    for (int i=0; i < 1000; i++) {
        if (st.pop(b) == UNDERFLOW) cout << "The stack is underflowed" << endl;
        else cout << "The popped value: " << b << endl;
    }
    do {
        cin >> command;
        switch (command){
            case 1:
                cin >> val;
                if (st.push(val) == OVERFLOW) cout << "The stack is overflowed" << endl;
                else cout << "Success! " << endl;
                break;
            case 2:
                if (st.pop(b) == UNDERFLOW) cout << "The stack is underflowed" << endl;
                else cout << "The popped value: " << b << endl;
                break;
            case 3:
                if (st.peek(b) == UNDERFLOW) cout << "The stack is underflowed" << endl;
                else cout << "The top is : " << b << endl;
                break;
            case 4:
                if (st.clear() == UNDERFLOW) cout << "The stack is underflowed" << endl;
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
    return 0;
}

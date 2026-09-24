#include <iostream>
using namespace std;

#define OVERFLOW -2
#define UNDERFLOW -1
#define SUCCESS 2
#define NONEXIST 3

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
    if (val != 0 && val != 1) {
        return NONEXIST;
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
    int size = -1, command = -1, input = -1, output = -10;
    bunny val, b;
    int fl = 0;
    cin >> size;
    Stack st(size > 0 ? size : 100);
    for (int i=0; i < 1000; i++) {
        if (st.push((bunny)1) == OVERFLOW) cout << "The stack is overflowed" << endl;
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
                cout << "Type '0' for white bunny and '1' for black one: ";
                cin >> input;
                output = st.push((bunny)input);
                if (output == OVERFLOW) cout << "No room for more bunnies" << endl;
                else if (output == NONEXIST) cout << "We don't have bunny in this colour" << endl;
                else cout << "Success! " << endl;
                break;
            case 2:
                output = st.pop(b);
                if (output == UNDERFLOW) cout << "There's no bunnies in here" << endl;
                else {
                    if (b == 0) cout << "The popped value: 0, white bunny" << endl;
                    else cout << "The popped value: 1, black bunny" << endl;
                }
                break;
            case 3:
                output = st.peek(b);
                if (output == UNDERFLOW) cout << "There's no bunnies in here" << endl;
                else {
                    if (b == 0) cout << "The peeked value: 0, white bunny" << endl;
                    else cout << "The peeked value: 1, black bunny" << endl;
                }
                break;
            case 4:
                if (st.clear() == UNDERFLOW) cout << "There's no bunnies in here" << endl;
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

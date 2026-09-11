#include <iostream>
using namespace std;

#define MISTAKE -1
#define SUCCESS 1

class Stack {
private: 
    struct Node {
        double value;
        Node* next;
    };
    int size;
    int capacity;
    Node* top;
public:
    Stack(int cap = 100) : size(0), capacity(cap), top(nullptr) {}
    ~Stack();

    int push(double val);
    int pop(double &b);
    int peek(double&b);
    int clear();
};

Stack::~Stack() {
    clear();
}

int Stack::push (double val) {
    if (size == capacity) {
        return MISTAKE;
    }
    Node* newy = new Node;
    newy->value = val;
    newy->next = top;
    top = newy;
    size++;
    return SUCCESS;
}

int Stack::pop (double &b) {
    if (top == nullptr) {
        return MISTAKE;
    }
    Node* tmp = top;
    b = tmp->value;
    top = top->next;
    delete tmp;
    size--;
    return SUCCESS;
}

int Stack::peek (double &b) {
    if (top == nullptr) {
        return MISTAKE;
    }
    b = top->value;
    return SUCCESS;
}

int Stack::clear() {
    if (top == nullptr) {
        return MISTAKE;
    }
    double d;
    while (top != nullptr) {
        pop(d);
    }
    return SUCCESS;
}

int main(void) {
    int size = -1, command = -1;
    double val = 0.0, b = 0.0;
    int fl = 0;
    cin >> size;
    Stack st(size > 0 ? size : 100);    
    do {
        cin >> command;
        switch (command){
            case 1:
                cin >> val;
                if (st.push(val) == -1) cout << "The stack is overflowed" << endl;
                else cout << "Success! " << endl;
                break;
            case 2:
                if (st.pop(b) == -1) cout << "The stack is underflowed" << endl;
                else cout << "The popped value: " << b << endl;
                break;
            case 3:
                if (st.peek(b) == -1) cout << "The stack is underflowed" << endl;
                else cout << "The top is : " << b << endl;
                break;
            case 4:
                if (st.clear() == -1) cout << "The stack is underflowed" << endl;
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
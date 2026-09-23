#include <iostream>
using namespace std;

#define MISTAKE -1
#define SUCCESS 1

class Stack {
public:
    int capacity;
    int top;
    double* data;
    Stack(int cap = 100) : capacity(cap), top(0), data(new double[cap]) {};
    ~Stack();

    Stack(const Stack& st): capacity(st.capacity), top(st.top), data (new double[st.capacity]) {
        for (int i = 0; i < top; i++) {
            data[i] = st.data[i];
        }  
    }
    Stack(Stack&& st) {
        data = st.data;
        capacity = st.capacity;
        top = st.top;
        st.data = nullptr;
        st.top = 0;
        st.capacity = 0;
    }

    void push(double val);
    int pop(double &b);
    int peek(double&b);
    int clear();
};

Stack::~Stack() {
    clear();
    delete[] data;
}

void Stack::push (double val) {
    if (top == capacity) {
        int newcap = 2*capacity + 1;
        double* newdata = new double[newcap];
        for (int i = 0; i < capacity; i++) {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        capacity = newcap;
    }
    data[top] = val;
    top++;
}

int Stack::pop (double &b) {
    if (top == 0) {
        return MISTAKE;
    }
    top--;
    b = data[top];
    return SUCCESS;
}

int Stack::peek (double &b) {
    if (top == 0) {
        return MISTAKE;
    }
    b = data[top-1];
    return SUCCESS;
}

int Stack::clear() {
    if (top == 0) {
        return MISTAKE;
    }
    top = 0;
    return SUCCESS;
}

int main(void) {
    int size = -1, command = -1;
    double val = 0.0, b = 0.0;
    int fl = 0;
    cin >> size;
    Stack st1(size > 0 ? size : 100);
    Stack st2 = st1;
    Stack st = move(st2);
    if (st2.data == nullptr) cout << "You moved st2 to st4" << endl;
    do {
        cin >> command;
        switch (command){
            case 1:
                cin >> val;
                st.push(val);
                cout << "Success! " << endl;
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
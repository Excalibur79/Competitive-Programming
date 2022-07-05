#include <bits/stdc++.h>
using namespace std;

class MyStack {
   public:
    int* st;
    int stSize;
    int id = -1;
    Stack() {
        st = (int*)malloc(1000 * sizeof(int));
        stSize = 0;
    }
    int top() {
        if (!empty()) return st[id];
        return -1;
    }
    void push(int data) {
        st[++id] = data;
        stSize++;
    }
    int pop() {
        if (!empty()) {
            return st[id--];
            stSize--;
        }
        return -1;
    }
    bool empty() { return id == -1; }
    bool size() { return stSize; }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.size() << endl;
}
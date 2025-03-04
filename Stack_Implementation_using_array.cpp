#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
class Stack{
    int top;
    int arr[MAX];
 public:
    Stack(){
        top=-1;
    }
    void push(int x);
    int pop();
    int peak();
    bool isEmpty();
};

void Stack::push(int x){
    if(top >= MAX-1){
        cout<<"Stack Overflow!\n";\
        return;
    }
    arr[++top] = x;
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow!\n";
        return -1;
    }
    int x = arr[top--];
    return x;
}

int Stack::peak(){
    if(top<0){
        cout<<"Stack is Empty!";
        return -1;
    }
    return arr[top];
}

bool Stack::isEmpty(){
    return top<0;
}
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.isEmpty()<<endl;
    cout<<st.peak()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.peak()<<endl;
    return 0;
}

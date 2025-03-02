#include <bits/stdc++.h>
using namespace std;
class Node{
public:
   int val;
   Node* next;

   Node(int val){
    this->val = val;
    next = nullptr;
   }
};

class Stack{
    Node* top;
public:
    Stack(){
        top=nullptr; 
    }
   
    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(!top){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peak(){
        if(!top){
            cout<<"Stack is Empty!";
            return -1;
        }
        return top->val;
    }

    void display(){
        Node* curr = top;
        while(curr){
            cout<<curr->val<<"->";
            curr=curr->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();

    st.pop();
    st.display();

    cout<<st.peak()<<endl;
    return 0;
}

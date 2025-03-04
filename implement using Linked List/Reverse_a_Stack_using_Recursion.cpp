#include <bits/stdc++.h>
using namespace std;
#define max 5

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
    int size;
    int capacity=max;
public:
    Stack(){
        top=nullptr; 
        size=0;
    }
   
    void push(int val){
        if(size == capacity){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop(){
        if(!top){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
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

    // reverse function {{{{{{{{{{{{{{{{{{ start 

    Node* reverseLL(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* newHead = reverseLL(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
    void reverseStack(){
        top = reverseLL(top);
    }

        // reverse function  }}}}}}}}}}}}}}}}}}}}} end  
};
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    st.push(50);
    st.display();
    st.push(60);
    cout<<st.peak()<<endl;

    st.reverseStack();
    cout << "Stack Reversed Successfully 🔥" << endl;
    st.display();
    return 0;
}

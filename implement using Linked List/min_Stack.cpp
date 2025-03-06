#include <bits/stdc++.h>
using namespace std;
#define max 10
class Stack{
    int top;
    int arr[max];
public:
   Stack(){
    top=-1;
   }

    void push(int val){
        if(top == max){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        arr[++top] = val;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        top--;
    }
    int peak(){
        if(top == -1){
            cout<<"Stack is Empty!";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

class MinStack{
    Stack st;
    int top;
    int min_arr[max];
public:
    MinStack(){
        top=-1;
    }

    void push(int val){
        st.push(val);
        if(top == -1 || min_arr[top]>val){
            min_arr[++top] = val; 
        } else{
            min_arr[top+1] = min_arr[top];
            min_arr[top] = val;
            top++;
        }
        
    }
    void pop(){
        int t_ele = st.peak();
        st.pop();
        int idx=-1;
        for(int i=0;i<=top;i++){
            if(min_arr[i] == t_ele){
                idx = i;
                break;
            } 
        }
        cout<<"# : "<<idx<<" "<<top<<endl;
        for(int i=idx;i<top;i++){
            min_arr[i] = min_arr[i+1];
        }
        top--;

    }
    int peak(){
        return st.peak();
    }
    bool isEmpty(){
        return st.isEmpty();
    }

    int getMin(){
        return min_arr[top];
    }
};
int main() {
    // Stack st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.display();

    MinStack s2;
    s2.push(89);
    s2.push(78);
    s2.push(55);
    s2.push(62);
    s2.push(45);
    s2.push(67);
    cout<<s2.peak()<<endl;
    cout<<s2.getMin()<<endl;
    s2.pop();
    cout<<s2.peak()<<endl;
    cout<<s2.getMin()<<endl;

    s2.pop();
    cout<<s2.peak()<<endl;
    cout<<s2.getMin()<<endl;

    s2.pop();
    cout<<s2.peak()<<endl;
    cout<<s2.getMin()<<endl;

    s2.pop();
    cout<<s2.peak()<<endl;
    cout<<s2.getMin()<<endl;
    return 0;
}

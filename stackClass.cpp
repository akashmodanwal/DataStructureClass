#include<iostream>
using namespace std;

class Stack{
    private:
        int arr[20];
        int top =-1;

    public:
        Stack(){
        }
        void push(int n){
            top++;
            arr[top] =  n;
            printf("%d got pushed in the stack\n",n);
        }
        void pop(){
            if(top<=0){
                cout<<"underflow"<<endl;
            }
            else{
                printf("%d popped from the stack\n",arr[top]);
                top--;
            }
        }
        void print(){
            for(int i=top;i>-1;i--){
                cout<<arr[i]<<endl;
            }
        }
};
int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.push(77);
    s.print();
    s.pop();
    s.pop();
    s.push(12);
    s.push(214);
    s.print();
    return 0;
}

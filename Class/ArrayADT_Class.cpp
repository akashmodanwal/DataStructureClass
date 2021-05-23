#include<bits/stdc++.h>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
        Array(){
            size=20;
            A=new int[20];
            length=0;
        }
        Array(int z){
            size=z;
            A= new int[size];
            length = 0;
        }
        ~Array(){
            delete []A;
        }
        
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    void Set(int index,int x);
    int Get(int index);
    int Max();
    int Min();
    int Sum();
    void Reverse();
    void Sort();
    bool isSorted();
    float Avg();
    void ReverseUsingAuxilary();
    int Length();


};

void Array :: Display(){
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int Array :: Length(){
    return length;
}

void Array :: Append(int x){
    A[length] = x;
    length++;
}

void Array :: Insert(int index,int x){
    for(int i=length-1;i>index;i++)
        A[i] = A[i-1];
    A[index] = x;
    length++;
}

int Array :: Delete(int index){
    int x = A[index];
    if(index > 0 && index < length){
        for(int i=index;i<length-1;i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

int Array :: LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            return i;
        }
    }
    return -1;
}

int Array :: Get(int index){
    if(index>=0 && index < length)
        return A[index];
}

void Array :: Set(int index,int x){
    if(index >=0 && index< length)
        A[index]=x;
}

int Array :: Max(){
    int max=A[0];
    for(int i=1;i<length;i++){
        if(max<A[i])
            max = A[i];
    }
    return max;
}

int Array :: Min(){
    int min = A[0];
    for(int i=1;i<length;i++){
        if(min>A[i])
            min = A[i];
    }
    return min;
}

int Array :: Sum(){
    int sum =0;
    for(int i=0;i<length;i++){
        sum = sum + A[i];
    }
    return sum;
}

void Array :: Reverse(){
    int temp;
    for(int i=0,j=length-1;i<j;i++,j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

bool Array :: isSorted(){
    for(int i=0;i<length-1;i++){
        if(A[i]>A[i+1])
            return false;
    }
    return true;
}


void Array :: Sort(){
    int key,i;
    for(int j=1;j<length;j++){
        key = A[j];
        i=j-1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1]=key;
    }
}

float Array :: Avg(){
    return (float)this->Sum()/length;
}

void Array :: ReverseUsingAuxilary(){
    int B[length];
    for(int i=length-1,j=0;i>=0;i--,j++)
        B[j] = A[i];
    for(int i=0;i<length;i++)
        A[i] = B[i];
}

int main(){
    Array arr(10);
    arr.Append(1);
    arr.Append(-1);
    arr.Append(22);
    arr.Append(4);
    arr.Append(5);
    arr.Append(32);
    arr.Append(66);
    arr.Append(2);
    arr.Append(3);
    arr.Sort();
    arr.Display();
    cout<<arr.Max()<<endl;
    cout<<arr.Min()<<endl;
    cout<<arr.Sum()<<endl;
    cout<<arr.LinearSearch(22)<<endl;
    cout<<arr.Avg()<<endl;
    arr.ReverseUsingAuxilary();
    arr.Display();
    arr.Reverse();
    arr.Display();
    cout<<arr.Length();
    return 0;
}
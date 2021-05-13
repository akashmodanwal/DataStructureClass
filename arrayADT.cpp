#include<iostream>
using namespace std;

struct Array{
    int  A[10];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<"  ";
    cout<<endl;
}

void append(struct Array *arr,int x){
    arr->A[arr->length] = x;
    arr->length++;
}

void insert(struct Array *arr,int index,int x){
    for(int i=arr->length;i>index;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
}

int Delete(struct Array *arr,int index){
    int x=arr->A[index];
    if(index > 0 && index < arr->length){
        for(int i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int recursiveBinarySearch(struct Array arr,int l,int h,int key){
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            return recursiveBinarySearch(arr,l,mid-1,key);
        }
        else{
            return recursiveBinarySearch(arr,mid+1,h,key);
        }
    }
    return -1;
}

int get(struct Array arr,int index){
    if(index>=0 && index < arr.length)
        return arr.A[index];
}

void set(struct Array *arr,int index,int x){
    if(index >=0 && index< arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(max<arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(min>arr.A[i])
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum =0;
    for(int i=0;i<arr.length;i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void ReverseUsingAuxilary(struct Array *arr){
    int B[arr->length];
    for(int i=arr->length-1,j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    for(int i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}



int main(){
    struct Array arr = {{2,3,4,5,6},10,5};
    append(&arr,7);
    insert(&arr,0,1);
    cout<<Delete(&arr,2)<<endl;
    insert(&arr,2,3);
    display(arr);
    cout<<LinearSearch(arr,5)<<endl;
    cout<<BinarySearch(arr,6)<<endl;
    cout<<recursiveBinarySearch(arr,0,arr.length-1,7)<<endl;
    cout<<get(arr,4)<<endl;
    set(&arr,3,-1);
    display(arr);
    cout<<Max(arr)<<endl;
    cout<<Min(arr)<<endl;
    cout<<Sum(arr)<<endl;
    cout<<Avg(arr)<<endl;
    ReverseUsingAuxilary(&arr);
    display(arr);




    return 0;
}

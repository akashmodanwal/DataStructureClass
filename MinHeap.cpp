#include<bits/stdc++.h>
using namespace std;


class MinHeap{
    private:
        int arr[100000];
        int size;
        
        void minHeapify(int i){
            if(i > size/2)
                return;
            int l = i*2;
            int r = i*2 + 1;
            int min = i;
            if(arr[min] > arr[l])
                min = l;
            if(r<=size && arr[min] > arr[r])
                min = r;
            
            if(min==i)
                return ;
            swap(arr[i],arr[min]);
            minHeapify(min);
        }
        
        void bubbleUp(int i){
            while(i>1 && arr[i]<arr[i/2]){
                swap(arr[i],arr[i/2]);
                i /=2;
            }
        }
    
    public:
        MinHeap(){
            this->size = 0;
        }
        
        void buildHeap(int arr[],int n){
            for(int i=0;i<n;i++){
                this->arr[i+1] = arr[i];
            }
            this->size = n;
            for(int i=n/2;i>=1;i--)
                minHeapify(i);
        }
        
        int getMin(){
            if(size > 0)
                return this->arr[1];
            return -1;
        }
        
        void insert(int x){
            arr[++size] = x;
            int i = size;
            bubbleUp(i);
        }
        
        void display(){
            for(int i=1;i<size+1;i++)
                cout<<arr[i]<<' ';
        }
        
        void deleteRoot(){
            swap(arr[1],arr[size]);
            size--;
            minHeapify(1);
        }
        
        void deleteAtIndex(int i){
            arr[i] = INT_MAX;
            bubbleUp(i);
            deleteRoot();
        }
        
};


int main(){
    MinHeap* h = new MinHeap();
    int arr[8] = {45,23,1,55,3,2,4,5};
    // for(int i=0;i<8;i++)
    //     h->insert(arr[i]);
    
    h->buildHeap(arr,8);
    h->deleteRoot();
    //h->deleteAtIndex(2);
    h->display();
    
    
    return 0;
}

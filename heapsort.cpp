#include<iostream>
using namespace std;

void heapify(int arr[],int idx,int heapsize){
    int left = 2*idx;
    int right = idx*2+1;
    int largest;
    if(left<=heapsize && arr[left]>arr[idx]){
        largest = left;
    }
    else{
        largest = idx;
    }
    if(right<=heapsize && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != idx){
        swap(arr[idx],arr[largest]);
        heapify(arr,largest,heapsize);
    }
}


void printarr(int arr[],int size){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    int arr[]={0,4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(arr)/sizeof(arr[0])-1;
    int heapsize = size;
    for(int i=size/2;i>=1;i--){
        heapify(arr,i,heapsize);
    }
    for(int i = size;i>=2;i--){
        swap(arr[1],arr[i]);
        heapsize--;
        heapify(arr,1,heapsize);
    }
    printarr(arr,size);
    
}
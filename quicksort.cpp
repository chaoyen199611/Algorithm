#include<iostream>
#include<ctime>
using namespace std;

int partition(int arr[],int p,int r){
    int x = arr[r];
    int i = p-1;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quicksort(int arr[],int p,int r){
    if(p<r){
        int q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int main(void){
    int arr[101]={};
    srand(time(NULL));
    for(int i=1;i<101;i++){
        arr[i]=rand()%1000+1;
    }
    quicksort(arr,1,100);
    for(int i=1;i<101;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
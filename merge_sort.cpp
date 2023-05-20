#include<iostream>
#include<ctime>
using namespace std;

void merge(int arr[],int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int left[n1+2];
    int right[n2+2];
    for(int i=1;i<=n1;i++){
        left[i] = arr[p+i-1];
    }
    for(int j=1;j<=n2;j++){
        right[j] = arr[q+j];
    }
    left[n1+1]=10000;
    right[n2+1]=10000;
    int i=1,j=1;
    for(int k=p;k<=r;k++){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
    }

}

void mergeSort(int arr[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main(void){
    int arr[101]={};
    srand(time(NULL));
    for(int i=1;i<101;i++){
        arr[i]=rand()%1000+1;
    }
    mergeSort(arr,1,100);
    for(int i=1;i<101;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"hello world"<<endl;
}
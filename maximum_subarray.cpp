#include<iostream>
#include<tuple>
using namespace std;

tuple<int,int,int> findCrossSubarray(int arr[],int low,int mid,int high){
    int leftsum = -100000,sum=0;
    int maxleft,maxright;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftsum){
            leftsum=sum;
            maxleft=i;
        }      
    }
    int rightsum = -1000000;
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>rightsum){
            rightsum=sum;
            maxright=i;
        }      
    }
    return make_tuple(maxleft,maxright,leftsum+rightsum);
}


tuple<int,int,int> findMaximumSubarray(int arr[],int low,int high){
    if(high==low){
        return make_tuple(low,high,arr[low]);
    }
    else{
        int mid=(low+high)/2;
        int leftlow,lefthigh,leftsum,rightlow,righthigh,rightsum,crosslow,crosshigh,crosssum;
        tie(leftlow,lefthigh,leftsum)=findMaximumSubarray(arr,low,mid);
        tie(rightlow,righthigh,rightsum)=findMaximumSubarray(arr,mid+1,high);
        tie(crosslow,crosshigh,crosssum)=findCrossSubarray(arr,low,mid,high);
        if(leftsum>=rightsum && leftsum>=crosssum){
            return make_tuple(leftlow,lefthigh,leftsum);
        }
        else if(rightsum>=leftsum && rightsum>=crosssum){
            return make_tuple(rightlow,righthigh,rightsum);
        }
        else{
            return make_tuple(crosslow,crosshigh,crosssum);
        }
    }
}


int main(void){
    int low=0,high=15,maxvalue;
    int A[16]={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4,7};
    tie(low,high,maxvalue) = findMaximumSubarray(A,low,high);

    cout<<"low : "<<low<<" high : "<<high<<" maxvalue = "<<maxvalue<<endl;
}
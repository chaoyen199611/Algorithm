#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char *argv[]){
    cout<<argc<<endl;
    for(int i=1;i<argc;i++){
        cout<<argv[i]<<endl;
    }
    cout<<"hello world"<<endl;
}
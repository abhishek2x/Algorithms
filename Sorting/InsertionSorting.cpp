#include <iostream>
using namespace std;

void insertionsort(int a[1000],int n){
    for(int i=1;i<n;i++){
        int hole=i-1;
        int value=a[i];
        while(hole>=0 && a[hole]>value){
            a[hole+1]=a[hole];
            hole--;
        }
        a[hole+1]=value;
    }
}

int main() {
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertionsort(a,n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

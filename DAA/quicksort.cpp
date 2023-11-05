#include<iostream>
using namespace std;

// pivot can be 1st/last/mid/random element from array 
int partition(int arr[],int i,int j){
    int pivot=arr[i];
    if(i==j) return j-1;
    while(i<j){
        if(arr[i] < pivot && i<j) i++;  //arr[i] is smaller than pivot (from lhs)
        else if(arr[j]>pivot && j>i) j--;  //arr[j] is greater than pivot from rhs
        else if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],pivot);
    return j;
}


int partition2(int arr[],int i,int j){
    int pivot=arr[i];
    if(i==j) return j-1;
    while(i<j){

        while( arr[i] < pivot && i<j) i++;
        while(arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);

    }
    swap(arr[j],pivot);
    return j;
}


void quicksort(int arr[],int i,int j){

    if(i<j){
        int pivot=partition(arr,i,j);
        quicksort(arr,i,pivot-1);
        quicksort(arr,pivot+1,j);
    }
}

int main(){

    int arr[]={10,78,5,4,2,6,1,0,9,3,7};
    for(int i=0;i<=10;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    quicksort(arr,0,10);
    for(int i=0;i<=10;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
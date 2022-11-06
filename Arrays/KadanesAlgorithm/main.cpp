#include <iostream>
#include<climits>
using namespace std;

int KadanesAlgorithm (int* array, int n){
    int sumSoFar= INT_MIN;
    int sumAtEnd=0;
    for (int i=0; i<n; i++){
        sumAtEnd += array[i];
        if (sumSoFar < sumAtEnd){
            sumSoFar = sumAtEnd;
        }
        if(sumAtEnd <0){
            sumAtEnd = 0;
        }
    }
    return sumSoFar;
}

int main(){
    int32_t size = 0;
    cout<<"Please input array size: ";
    cin>> size;

    int array[size];
    cout<<"Please input elements of array"<<endl;
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    cout <<" The largest subarray sum is : "<< KadanesAlgorithm(array, size);

    return 0;
}
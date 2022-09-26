#include <iostream>
using namespace std;

int countSort(int* arr,int n,int max){
    int count[max+1];
    int newArr[n];
    int frequency=0;
    int freqelement;
    for(int i=0;i<max+1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        if(count[arr[i]]>frequency){
            frequency=count[arr[i]];
            freqelement=arr[i];
        }
    }
    for(int i=1;i<max+1;i++){
        count[i]+=count[i-1];
    }
    for (int i = 0;i<n;i++) {
        newArr[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    for(int i=0;i<n;i++){
        arr[i]=newArr[i];
    }
    return freqelement;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freqelement=countSort(arr,n,max);
    float median;
    if(n%2==0){ 
        median=(float)(arr[(n-1)/2]+arr[(n-1)/2 + 1])/2;
    }
    else{
        median=arr[(n-1)/2];
    }
    cout<<"Frequent value:"<<freqelement<<endl<<"Median:"<<median<<endl<<"Difference:"<<freqelement-median<<endl;
    return 0;
}
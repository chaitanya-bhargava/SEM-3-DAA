#include <iostream>
using namespace std;

int countSort(int* arr,int n,int max){
    int count[max+1];
    int newArr[n];
    for(int i=0;i<max+1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        if(count[arr[i]]>1){
            return arr[i];
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
    return -1;
}

int main()
{
    int tot;
    cin>>tot;
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
    int ans=countSort(arr,n,max);
    if(ans==-1){
        cout<<"No student submitted twice";
    }
    else{
        cout<<ans;
    }
    return 0;
}
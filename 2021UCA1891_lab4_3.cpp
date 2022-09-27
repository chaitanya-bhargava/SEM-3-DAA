
#include <iostream>
#include<vector>
using namespace std;
void heapify(vector<string> *arr, int n, int m)
{
    int largest=m;
    int left=2*m+1;
    int right=2*m+2;
    if (left < n && (*arr)[left] > (*arr)[largest])
        largest = left;
    if (right < n && (*arr)[right] > (*arr)[largest])
        largest = right;
    if (largest != m)
    {
        (*arr)[m].swap((*arr)[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<string> *arr, int n)
{
    for (int i=n/2 - 1;i>-1;i--)
        heapify(arr,n, i);
    for (int i=n-1;i>-1;i--)
    {
        (*arr)[0].swap((*arr)[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin>>k;
        arr.push_back(k);
    }
    heapSort(&arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

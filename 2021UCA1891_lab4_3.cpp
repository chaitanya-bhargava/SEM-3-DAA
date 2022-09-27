
#include <iostream>
#include<vector>
using namespace std;
void heapify(vector<string> *arr, int n, int m)
{
    int max=m;
    int l=2*m+1;
    int r=2*m+2;
    if (l < n && (*arr)[l] > (*arr)[max])
        max = l;
    if (r < n && (*arr)[r] > (*arr)[max])
        max = r;
    if (max != m)
    {
        (*arr)[m].swap((*arr)[max]);
        heapify(arr, n, max);
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

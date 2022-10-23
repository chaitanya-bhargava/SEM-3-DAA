#include<iostream>
#include<vector>
using namespace std;

//function to return subarray vector
vector<int> subArray(vector<int> weather,int m,int &bestSum){
    if(m>weather.size()){
        cout<<"Subarray cannot be greater than main array";
        exit(1);
    }

    //calculate sum of first m elements and store in bestsum
    int sum=0;
    for(int i=0;i<m;i++){
        sum+=weather[i];
    }
    bestSum=sum;
    int index=0;
    //remove one element and add another then calculate sum
    for(int i=0;i<weather.size()-m;i++){
        sum=sum-weather[i];
        sum=sum+weather[i+m];
        //if new sum is greater make it bestsum and store starting index
        if(sum>bestSum){
            bestSum=sum;
            index=i+1;
        }
    }
    //make subarray
    vector<int> subarray(m);
    int j=0;
    for(int i=index;i<index+m;i++){
        subarray[j]=weather[i];
        j++;
    }
    return subarray;
}

int main(){
    int n;
    cout<<"Enter no. of days:"<<endl;
    cin>>n;
    vector<int> weather(n);
    cout<<"Enter weather values:"<<endl;
    for(int i=0;i<n;i++){
        cin>>weather[i];
    }
    int m;
    cout<<"Enter size of subarray:"<<endl;
    cin>>m;
    int bestSum;
    vector<int> ans=subArray(weather,m,bestSum);
    cout<<"The required sub-array is:"<<endl;
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"The maximum average found is:"<<(float)bestSum/m;
    return 0;
}
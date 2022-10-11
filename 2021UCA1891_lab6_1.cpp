#include<iostream>
#include<vector>
using namespace std;

int minelem(int x, int y) 
{ 
    if(x>y){
        return y;
    }
    else{
        return x;
    } 
}

int maxelem(int x, int y) 
{ 
    if(x<y){
        return y;
    }
    else{
        return x;
    } 
} 

void maxminbp(vector<int> bp,int &max,int &min,int low,int high){
    if(low==high){
        max=bp[low];
        min=bp[low];
        return;
    }
    if(low==high-1){
        max=maxelem(bp[low],bp[high]);
        min=minelem(bp[low],bp[high]);
        return;
    }
    int mid=(low+high)/2;
    int minleft;
    int maxleft;
    int minright;
    int maxright;
    maxminbp(bp,maxleft,minleft,low,mid);
    maxminbp(bp,maxright,minright,mid+1,high);
    max=maxelem(maxleft,maxright);
    min=minelem(minleft,minright);
}

int main(){
    int k;
    cout<<"Enter number of entries:"<<endl;
    cin>>k;
    vector<int> bp(k);
    cout<<"Enter values:"<<endl;
    for(int i=0;i<k;i++){
        cin>>bp[i];
    }
    int max;
    int min;
    int low=0;
    int high=bp.size()-1;
    maxminbp(bp,max,min,low,high);
    cout<<"Maximum Element :"<<max<<endl;
    cout<<"Minimum Element :"<<min;
    return 0;
}
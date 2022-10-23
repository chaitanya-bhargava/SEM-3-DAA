#include<iostream>
#include<vector>
using namespace std;

// calculate min
int minelem(int x, int y) 
{ 
    if(x>y){
        return y;
    }
    else{
        return x;
    } 
}

//calculate max
int maxelem(int x, int y) 
{ 
    if(x<y){
        return y;
    }
    else{
        return x;
    } 
} 

//function to calculate max and min 
void maxminbp(vector<int> bp,int &max,int &min,int low,int high){
    //if only one element
    if(low==high){
        max=bp[low];
        min=bp[low];
        return;
    }
    //if 2 elements
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
    maxminbp(bp,maxleft,minleft,low,mid); //calculate max and min from left half
    maxminbp(bp,maxright,minright,mid+1,high); //calculate max and min from right half
    max=maxelem(maxleft,maxright); //store max between left and right
    min=minelem(minleft,minright); //store min between left and right
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
#include<iostream>
using namespace std;

//PEAK WEATHER CONDITIONS
void PWC(int * Day,int n){
    int lt=0;
    int rt=n-1;
    int count=0; //FOR MAINTANING NO. OF COMPARISIONS
    while(lt<=rt){
        int mid=(lt+rt)/2;
        if((Day[mid]>Day[mid+1]) && (Day[mid]>Day[mid-1])){
            cout<<mid<<endl;
            count++;
            break;
        }
        else if((Day[mid]<Day[mid-1])){
            rt=mid-1;
            count++;
        }
        else if((Day[mid]<Day[mid+1])){
            count++;
            lt=mid+1;
        }
    }
    cout<<"No. of comparisions:"<<count<<endl;
}

int main(){
    int n;
    cin>>n;
    int * Day=new int(n);
    for(int i=0;i<n;i++){
        cin>>Day[i];
    }
    PWC(Day,n);
    return 0;
}
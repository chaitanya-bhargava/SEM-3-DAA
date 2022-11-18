/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    string text;
    getline(cin, text);
    string pattern;
    getline(cin, pattern);
    int n=text.size();
    int m=pattern.size();
    int shift[256];
    for(int i=0;i<m;i++){
        shift[(int)pattern[i]]=m-i-1;
    }
    int i=m-1;
    int j=m-1;
    int flag=0;
    while(i<n){
        if(text[i]==pattern[j]){
            if(j==0){
                flag=1;
                cout<<"Found at index:"<<i<<endl;
                i=i+m;
                j=m-1;
            }
            else{
                i=i-1;
                j=j-1;
            }
        }
        else{
            i=m+i-min(j,shift[text[i]]+1);
            j=m-1;
        }
    }
    if(flag==0){
        cout<<"Not exist";
    }
    return 0;
}
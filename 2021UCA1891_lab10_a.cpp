/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main(){
    int flag=0;
    string text;
    getline(cin, text);
    string pattern;
    getline(cin, pattern);
    int n=text.size();
    int m=pattern.size();
    for(int i=0;i<n-m;i++){
        if(pattern==text.substr(i,m)){
            flag=1;
            cout<<"Found at index"<<i<<endl;
        }
    }
    if(flag==0){
        cout<<"Not exist";
    }
    return 0;
}
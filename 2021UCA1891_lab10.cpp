/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

bool search(string pattern,char c){
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]==c){
            return true;
        }
    }
    return false;
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

void bruteForce(string text,string pattern,int & cmp1){
    cmp1=0;
    int flag=0;
    int n=text.size();
    int m=pattern.size();
    for(int i=0;i<n-m+1;i++){
        cmp1=cmp1+m;
        if(pattern==text.substr(i,m)){
            flag=1;
            cout<<"Found at index:"<<i<<endl;
        }
    }
    if(flag==0){
        cout<<"Not exist"<<endl;
    }
}

void boyerMoore(string text,string pattern,int & cmp2){
    int flag=0; //FLAG TO CHECK IF PATTERN FOUND
    cmp2=0;
    int n=text.size();
    int m=pattern.size();
    vector<int> shift(256,INT_MAX-1); //HOLDS SHIFT BACK OF EACH CHARACTER DURING BAD CHARACTER MISMATCH
    for(int i=0;i<m;i++){
        shift[(int)pattern[i]]=i;
    }
    int i=m-1;
    int j=m-1;
    while(i<n){
        cmp2++;
        if(text[i]==pattern[j]){ //IF CHARACTER IS SAME
            if(j==0){ // IF CHARACTER IS SAME AND IT IS FIRST CHARACTER OF PATTERN -> PATTERN FOUND
                flag=1;
                cout<<"Found at index:"<<i<<endl;
                i=i+m;
                j=m-1;
            }
            else{ //MOVE ONE CHARACTER LEFT IN BOTH TEXT AND PATTERN
                i=i-1;
                j=j-1;
            }
        }
        else{ //BAD CHARACTER JUMP TO CREATE MATCH OR SKIP OVER MISMATCH
            if(search(pattern,text[i])){ //IF CURRENT TEXT CHARACTER IN PATTERN
                if((m+i-shift[text[i]]-1)>i+m-j){ // NO NEGATIVE SHIFTS
                    i=m+i-shift[text[i]]-1;
                }
                else{ // IN CASE OF NEGATIVE SHIFT JUST MOVE FORWARD ONE
                    i=m+i-j;
                }
            }
            else{
                i=m+i;
            }
            j=m-1;
        }
    }
    if(flag==0){
        cout<<"Not exist"<<endl;
    }
}

void KMP(string text,string pattern,int & cmp3){
    int flag=0;
    cmp3=0;
    int n = text.size();
    int m = pattern.size();
    vector<int> preprocess(m + 1); // PREPROCESS ARRAY
    // MAKING PREPROCESS ARRAY
    int i = 0; 
    int j = -1;
    preprocess[i] = j; //MAKE 0 INDEX OF ARRAY -1
    while (i < m)
    {
        while (j >= 0 && pattern[i] != pattern[j]){ //IF CHARACTER NOT EQUAL THEN JUMP TO INDEX STORED TILL CHARACTER MATCHES
            j = preprocess[j];
        }
        i++; //AS CHARACTER MATCHED MOVE FORWARD
        j++;
        preprocess[i] = j;
    }
    // for (int i = 0; i < m+1; i++)
    // {
    //     cout << preprocess[i] << " ";
    // }
    // cout << endl;
    i=0;
    j=0;
    while (i < n)
    {
        while (j >= 0 && text[i] != pattern[j]){// JUMP TO INDEX TILL CHARACTER MATCHES OR START OF ARRAY
            cmp3++;
            j = preprocess[j];
        }
        cmp3++;
        i++; // AS PATTERN MATCHED MOVE FORWARD
        j++;
        if (j == m) // ALL CHARACTERS OF PATTERN MATCHED
        {
            flag=1;
            cout<<"Found at index:"<<i-j<<endl;
            cout<<"No of comparisions:"<<cmp3-1<<endl;
            j = preprocess[j]; //JUMP TO INDEX IN PREPROCESS ARRAY TO CONTINUE
        }
    }
    if (flag == 0)
    {
        cout << "Not exist"<<endl;
    }
}

int main(){
    string text;
    getline(cin, text);
    string pattern;
    getline(cin, pattern);
    cout<<"Brute Force:"<<endl;
    int cmp1,cmp2,cmp3;
    bruteForce(text,pattern,cmp1);
    cout<<endl;
    cout<<"Boyer Moore:"<<endl;
    boyerMoore(text,pattern,cmp2);
    cout<<endl;
    cout<<"KMP:"<<endl;
    KMP(text,pattern,cmp3);
    cout<<endl;
    cout<<"Table for no of comparions:"<<endl<<"Brute Force:"<<cmp1<<endl<<"Boyer Moore:"<<cmp2<<endl<<"KMP:"<<cmp3<<endl;
    return 0;
}
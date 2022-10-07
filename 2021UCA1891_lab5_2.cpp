#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void displayMatrix(vector<vector<int>> M,int rows,int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> addZeroes(vector<vector<int>> A,int n){
    vector<int> row(n,0);
    int len=A.size();
    for(int i=0;i<len;i++){
        int len2=A[i].size();
        for(int j=0;j<n-len2;j++){
            A[i].push_back(0);
        }
    }
    for(int i=0;i<n-len;i++){
        A.push_back(row);
    }
    return A;
}

vector<vector<int>> addMatrix(vector<vector<int>> A,vector<vector<int>> B){
    vector<int> row(A.size(),0);
    vector<vector<int>> result(A.size(),row);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> A,vector<vector<int>> B){
    vector<int> rowres(A.size(),0);
    vector<vector<int>> result(A.size(),rowres);
    if(A.size()==1 && B.size()==1){
        result[0][0]=A[0][0]*B[0][0];
        return result;
    }
    int mid=A.size()/2;
    vector<int> row(mid,0);
    vector<vector<int>> a00(mid,row);
    vector<vector<int>> a01(mid,row);
    vector<vector<int>> a10(mid,row);
    vector<vector<int>> a11(mid,row);
    vector<vector<int>> b00(mid,row);
    vector<vector<int>> b01(mid,row);
    vector<vector<int>> b10(mid,row);
    vector<vector<int>> b11(mid,row);
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            a00[i][j]=A[i][j];
            a01[i][j]=A[i][j+mid];
            a10[i][j]=A[i+mid][j];
            a11[i][j]=A[i+mid][j+mid];
            b00[i][j]=B[i][j];
            b01[i][j]=B[i][j+mid];
            b10[i][j]=B[i+mid][j];
            b11[i][j]=B[i+mid][j+mid];
        }
    }
    vector<vector<int>> res00=addMatrix(multiplyMatrix(a00,b00),multiplyMatrix(a01,b10));
    vector<vector<int>> res01=addMatrix(multiplyMatrix(a00,b01),multiplyMatrix(a01,b11));
    vector<vector<int>> res10=addMatrix(multiplyMatrix(a10,b00),multiplyMatrix(a11,b10));
    vector<vector<int>> res11=addMatrix(multiplyMatrix(a10,b01),multiplyMatrix(a11,b11));
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            result[i][j]=res00[i][j];
            result[i][j+mid]=res01[i][j];
            result[i+mid][j]=res10[i][j];
            result[i+mid][j+mid]=res11[i][j];
        }
    }
    return result;
}


int main(){
    int norowsa,nocolumnsa,norowsb,nocolumnsb;
    cout<<"Enter no. of rows in A:"<<endl;
    cin>>norowsa;
    cout<<"Enter no. of columns in A:"<<endl;
    cin>>nocolumnsa;
    cout<<"Enter no. of rows in B:"<<endl;
    cin>>norowsb;
    cout<<"Enter no. of columns in B:"<<endl;
    cin>>nocolumnsb;
    if(nocolumnsa!=norowsb){
        cout<<"Matrix cannot be multiplied"<<endl;
        exit(1);
    }
    cout<<"Enter matrix A:"<<endl;
    vector<vector<int>> A;
    for(int i=0;i<norowsa;i++){
        vector<int> row;
        for(int j=0;j<nocolumnsa;j++){
            int k;
            cin>>k;
            row.push_back(k);
        }
        A.push_back(row);
    }
    cout<<"Enter matrix B:"<<endl;
    vector<vector<int>> B;
    for(int i=0;i<norowsb;i++){
        vector<int> row;
        for(int j=0;j<nocolumnsb;j++){
            int k;
            cin>>k;
            row.push_back(k);
        }
        B.push_back(row);
    }
    int max1;
    if(norowsa>norowsb){
        max1=norowsa;
    }else{
        max1=norowsb;
    }
    int max2;
    if(nocolumnsa>nocolumnsb){
        max2=nocolumnsa;
    }
    else{
        max2=nocolumnsb;
    }
    int max;
    if(max1>max2){
        max=max1;
    }
    else{
        max=max2;
    }
    int pos=ceil(log2(max));
    int p=pow(2,pos);
    A=addZeroes(A,p);
    B=addZeroes(B,p);
    cout<<endl;
    vector<vector<int>> C=multiplyMatrix(A,B);
    displayMatrix(C,norowsa,nocolumnsb);
    return 0;
}
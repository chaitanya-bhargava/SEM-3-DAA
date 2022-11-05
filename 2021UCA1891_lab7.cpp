/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void parenthesis(int i, int j, int n, int* s,char& name)
{
    // IF WE REACH DIAGONAL WE DON'T ADD ANY BRACKET
    if(i==j){
        cout<<name;
        name++;
        return;
    }
    cout << "(";
    // GO TO THE CELL (i,j) IN MATRIX 
    parenthesis(i,*((s+i*n)+j),n,s,name);
    // AFTER RETURNING FROM PREVIOUS FUNCTION WE GO TO NEXT MATRIX 
    parenthesis(*((s+i*n)+j)+1,j,n,s,name);
    cout << ")";
}

int main(){
    int n;
    cin>>n;
    int dim[n]; //ARRAY TO MAINTAIN DIMENSIONS
    cin>>dim[0];
    int ignore;
    for(int i=0;i<n;i++){
        cin>>dim[i+1];
        if(i!=n-1)
        cin>>ignore;
    }
    int m[n+1][n+1]; // MATRIX FOR MEMORISATION
    int s[n+1][n+1]; // HELPER MATRIX FOR BRACKETS
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(int d=1;d<n;d++){ // D REPRESENTS DIFFERENCE BETWEEN HIGHEST AND LOWEST MATRIX MULTIPLIED
        for(int i=1;i<n+1-d;i++){ // I REPRESENTS ROW IN MATRIX
            int j=i+d; // J REPRESENTS COLUMN IN MATRIX
            int min=INT_MAX;
            for(int k=i;k<j;k++){
                int q=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j]; //DYNAMIC PROGRAMMING FORMULA USED
                if(q<min){
                    min=q;
                    s[i][j]=k; //ADD VALUE OF K TO HELPER MATRIX
                }
            }
            m[i][j]=min; // SET VALUE FOR USE LATER
        }
    }
    cout<<m[1][n]<<endl; // FINAL ANSWER STORED IN TOP RIGHT CELL OF MATRIX
    char name='A';
    parenthesis(1, n, n+1, (int*)s, name); // PRINT BRACKETS
    return 0;
}
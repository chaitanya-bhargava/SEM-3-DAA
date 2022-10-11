/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/

#include <iostream>
#include<math.h>
#include<float.h>
#include<vector>
using namespace std;

//boat definition   
class Boat 
{ 
    public:
    float x, y;
    Boat(){
        x=0;
        y=0;
    } 
}; 

//swap function used in sorting boats
void swap(Boat &a,Boat &b){
    Boat temp;
    temp.x=a.x;
    temp.y=a.y;
    a.x=b.x;
    a.y=b.y;
    b.x=temp.x;
    b.y=temp.y;
}

//sort boats according to x
void sortX(vector<Boat>& Boats){
    for(int i=0;i<Boats.size()-1;i++){
        for(int j=0;j<Boats.size()-i-1;j++){
            if(Boats[j].x>Boats[j+1].x){
                swap(Boats[j],Boats[j+1]);
            }
        }
    }
}

//sort boats according to y
void sortY(vector<Boat>& Boats){
    for(int i=0;i<Boats.size()-1;i++){
        for(int j=0;j<Boats.size()-i-1;j++){
            if(Boats[j].y>Boats[j+1].y){
                swap(Boats[j],Boats[j+1]);
            }
        }
    }
}

//function to calculate distance
float manhattanDist(Boat p1, Boat p2) 
{ 
    return abs(p1.x-p2.x)+abs(p1.y-p2.y); 
} 

//function to find minumum of two numbers   
float min(float x, float y) 
{ 
    if(x>y){
        return y;
    }
    else{
        return x;
    } 
} 

//function to find closest pair between two halves(less than d) 
float stripPair(vector<Boat> strip) 
{ 
    float min = FLT_MAX; 
    sortY(strip); 
    for (int i = 0; i < strip.size(); ++i) 
        for (int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j) 
            if (manhattanDist(strip[i],strip[j]) < min) 
                min = manhattanDist(strip[i], strip[j]); 
  
    return min; 
} 

//main recursive function
float closestPair(vector<Boat> Boats) 
{  
    int n=Boats.size();
    //when no. of boats is just 3 we calculate minimum manually
    if (n <= 3){
        float min=FLT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(manhattanDist(Boats[i],Boats[j])<min){
                    min=manhattanDist(Boats[i],Boats[j]);
                }
            }
        }
        return min;
    } 
 
    int mid = n/2; 
    Boat midBoat = Boats[mid];
    //split into two parts and apply closest pair again
    vector<Boat> left;
    vector<Boat> right;
    for(int i=0;i<mid;i++){
        left.push_back(Boats[i]);
        right.push_back(Boats[i+mid]);
    } 
    float dl = closestPair(left); 
    float dr = closestPair(right);  
    float d = min(dl, dr);  
    vector<Boat> strip;  
    for (int i = 0; i < n; i++) 
        if (abs(Boats[i].x - midBoat.x) < d){ 
            strip.push_back(Boats[i]);
        } 
    float s=stripPair(strip); 
    return min(d,s); 
} 
  


int main() 
{ 
    cout<<"Enter no. of boats:"<<endl;
    int num;
    cin>>num;
    vector<Boat> Boats(num);
    cout<<"Enter each boats' x and y coordinate:"<<endl;
    for(int i=0;i<num;i++){
        cin>>Boats[i].x;
        cin>>Boats[i].y;
    }
    if(Boats.size()==0 || Boats.size()==1){
        cout<<"Not enough boats entered!";
        exit(1);
    }  
    sortX(Boats);
    cout << "The smallest distance between the boats is " << closestPair(Boats); 
    return 0; 
} 
  
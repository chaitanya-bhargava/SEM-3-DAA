#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<vector>
using namespace std;

//STRUCTURE DECLARATION
struct Employee{
    string name;
    int id;
    string department;
    int salary;
    string address;
    long long contactno;
    string emailid;
    string position;
    int experience;
};

//STRING SPLITTING
vector<string> split(const string &s,char delim){
    vector<string> elems;
    stringstream ss(s);
    string item;
    while(getline(ss,item,delim)){
        elems.push_back(item);
    }
    return elems;
}

//DISPLAY DATABASE AFTER EACH OPERATION
void displayDatabase(Employee * arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i].name<<","<<arr[i].id<<","<<arr[i].department<<","<<arr[i].salary<<","<<arr[i].address<<","<<arr[i].contactno<<","<<arr[i].emailid<<","<<arr[i].position<<","<<arr[i].experience<<endl;
    }
}

int main(){
    Employee arr[50];
    int size=0;
    string line;
    ifstream myfile ("database.txt");
    if(myfile.is_open()){
        //CONTRUCTING DATABASE USING FILE
        while(getline(myfile,line)){
            vector<string> x=split(line,',');
            unsigned int j;
            for(j=0;j<x.size();j++){
                switch (j)
                {
                case 0:
                    arr[size].name=x[j];
                    break;
                case 1:
                    arr[size].id=stoi(x[j]);
                    break;
                case 2:
                    arr[size].department=x[j];
                    break;
                case 3:
                    arr[size].salary=stoi(x[j]);
                    break;
                case 4:
                    arr[size].address=x[j];
                    break;
                case 5:
                    arr[size].contactno=stoll(x[j]);
                    break;
                case 6:
                    arr[size].emailid=x[j];
                    break;
                case 7:
                    arr[size].position=x[j];
                    break;
                case 8:
                    arr[size].experience=stoi(x[j]);
                    break;
                
                default:
                    break;
                }
            }
        size++;
        }
        myfile.close();
    }
    //displayDatabase(arr,size);
    
    //ARRAY TO STORE COUNTER VALUES
    int counters[9];
    for(int i=0;i<9;i++){
        counters[i]=0;
    }

    //a
    cout<<"a:"<<endl;
    for(int i=0;i<size;i++){
        if(arr[i].id==104){
            cout<<arr[i].name<<endl;
            break;
        }
    }

    //b
    cout<<"b:"<<endl;
    cout<<arr[0].name<<","<<arr[0].id<<","<<arr[0].department<<","<<arr[0].salary<<","<<arr[0].address<<","<<arr[0].contactno<<","<<arr[0].emailid<<","<<arr[0].position<<","<<arr[0].experience<<endl;

    //c
    cout<<"c:"<<endl;
    cout<<arr[size-1].name<<","<<arr[size-1].id<<","<<arr[size-1].department<<","<<arr[size-1].salary<<","<<arr[size-1].address<<","<<arr[size-1].contactno<<","<<arr[size-1].emailid<<","<<arr[size-1].position<<","<<arr[size-1].experience<<endl;

    //d
    size--;
    cout<<"d:"<<endl;
    displayDatabase(arr,size);

    //e
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
        counters[4]++;
    }
    size--;
    cout<<"e:"<<endl;
    displayDatabase(arr,size);
    
    //f
    for(int i=2;i<size-1;i++){
        arr[i]=arr[i+1];
        counters[5]++;
    }
    size--;
    cout<<"f:"<<endl;
    displayDatabase(arr,size);

    //g
    arr[size].name="p31";
    arr[size].id=131;
    arr[size].department="ciot";
    arr[size].salary=70000;
    arr[size].address="USA";
    arr[size].contactno=9746295925;
    arr[size].emailid="p31@gmail.com";
    arr[size].position="graphic designer";
    arr[size].experience=12;
    size++;
    cout<<"g:"<<endl;
    displayDatabase(arr,size);

    //h
    for(int i=size;i>0;i--){
        arr[i]=arr[i-1];
        counters[7]++;
    }
    arr[0].name="p0";
    arr[0].id=100;
    arr[0].department="ciot";
    arr[0].salary=60000;
    arr[0].address="Australia";
    arr[0].contactno=9746255525;
    arr[0].emailid="p0@gmail.com";
    arr[0].position="web designer";
    arr[0].experience=6;
    size++;
    cout<<"h:"<<endl;
    displayDatabase(arr,size);

    //i
    for(int i=size;i>1;i--){
        arr[i]=arr[i-1];
        counters[8]++;
    }
    arr[1].name="p1";
    arr[1].id=101;
    arr[1].department="civil";
    arr[1].salary=15000;
    arr[1].address="Japan";
    arr[1].contactno=9743455525;
    arr[1].emailid="p1@gmail.com";
    arr[1].position="blueprint designer";
    arr[1].experience=14;
    size++;
    cout<<"i:"<<endl;
    displayDatabase(arr,size);
    cout<<endl<<endl;
    cout<<"Required Table:"<<endl;
    for(int i=0;i<9;i++){
        switch (i)
                {
                case 0:
                    cout<<"a:"<<counters[i]<<endl;
                    break;
                case 1:
                    cout<<"b:"<<counters[i]<<endl;
                    break;
                case 2:
                    cout<<"c:"<<counters[i]<<endl;
                    break;
                case 3:
                    cout<<"d:"<<counters[i]<<endl;
                    break;
                case 4:
                    cout<<"e:"<<counters[i]<<endl;
                    break;
                case 5:
                    cout<<"f:"<<counters[i]<<endl;
                    break;
                case 6:
                    cout<<"g:"<<counters[i]<<endl;
                    break;
                case 7:
                    cout<<"h:"<<counters[i]<<endl;
                    break;
                case 8:
                    cout<<"i:"<<counters[i]<<endl;
                    break;
                
                default:
                    break;
                }
    }
    return 0;
}
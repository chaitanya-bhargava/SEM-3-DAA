#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int n){
        data=n;
        next=NULL;
    }
};

//INSERT NODE IN LINKED LIST
void insertNode(Node **head, int n)
{
    Node *temp = new Node(n);
    if ((*head) == NULL)
    {
        (*head) = temp;
    }
    else
    {
        Node *temp2 = (*head);
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

//FIND PEAK ELEMENT
void FPE(Node* head){
    int count=0; //FOR NUMBER OF COMPARISIONS
    int flag=0; //FOR CHECKING IF NO PEAKS WERE FOUND
    if(head->next==NULL){ //IF THERE IS ONLY ONE ELEMENT
        cout<<head->data;
        return;
    }
    while(head->next!=NULL){
        if(head->next->data<head->data){
            cout<<head->data<<endl;
            head=head->next; // TWO PEAK ELEMENTS CANNOT BE TOGETHER
            flag++;
            if(head->next==NULL){
                break;
            }
        }
        count++;
        head=head->next;
    }
    if(flag==0){
    cout<<-1;
    }
    cout<<"No. of comparisions:"<<count<<endl;
}

int main(){
    int n;
    cin>>n;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        insertNode(&head,t);
    }
    FPE(head);
    return 0;
}
/*
Name: Chaitanya Bhargava
Roll no: 2021UCA1891
Batch : CSAI-2
Mobile No. : 9717393877

"I have done this assignment on my own. I have not copied any code
from another student or any online source. I understand if my code is
found similar to somebody else's code, my case can be sent to the
Disciplinary committee of the institute for appropriate action."

*/

#include <iostream>
#include <string.h>
using namespace std;

// LINKED LIST
class Node
{
public:
    string name;
    Node *next;
    Node(string name1)
    {
        name = name1;
        next = NULL;
    }
};

// INSERT NODE
void insertNode(Node **head, string pname)
{
    Node *temp = new Node(pname);
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

// DELETE NODE BY KEY
void deleteNode(Node **head, string pname)
{
    if (pname.compare((*head)->name) == 0)
    {
        (*head) = (*head)->next;
        return;
    }
    Node *curr = *head;
    while (curr->next != NULL)
    {
        if (pname.compare(curr->next->name) == 0)
        {
            curr->next = curr->next->next;
            return;
        }
        curr = curr->next;
    }
}

// COUNT NO. OF NODES
int count(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

// FUNC TO RETURN INDEX OF HEAD POINTER OF REQUIRED FLIGHT LINKED LIST
int llFinder(string fname, int size, string *arrno)
{
    for (int i = 0; i < size; i++)
    {
        if (fname.compare(arrno[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

// DISPLAY DATA OF LINKED LIST
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "No Passenger" << endl;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->name << " ";
            head = head->next;
        }
        cout << endl;
    }
}

int main()
{
    int size;
    cin >> size;
    string arrno[size];  // ARRAY TO STORE FLIGHT NAMES
    Node *flights[size]; // ARRAY TO STORE HEAD POINTERS OF LINKED LISTS
    for (int i = 0; i < size; i++)
    {
        flights[i] = NULL; // MAKE ALL HEAD POINTERS NULL
        string fname;
        cin >> fname;
        arrno[i] = fname; // INSERT FLIGHT NAMES INTO STRING ARRAY
    }

    while (true)
    {
        int ans;
        cout << "----------------------------------------------------------\n1.Book Reservation\n2.Cancel Reservation\n3.Print Names\n4.Print Number of Passengers\n5.Quit\n----------------------------------------------------------\n";
        cin >> ans;
        int index;
        string fname;
        int num;
        switch (ans)
        {
        case 1:
            cin >> fname;
            index = llFinder(fname, size, arrno); // FIND INDEX OF REQUIRED LINKED LIST
            if (index == -1)
            {
                cout << "Enter valid flight name!" << endl;
                exit(1);
            }
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                string pname;
                cin >> pname;
                insertNode(&flights[index], pname); // INSERT NODE TO BOOK RESERVATION
            }
            break;
        case 2:
            cin >> fname;
            index = llFinder(fname, size, arrno); // FIND INDEX OF REQUIRED LINKED LIST
            if (index == -1)
            {
                cout << "Enter valid flight name!" << endl;
                exit(1);
            }
            cin >> num;
            for (int i = 0; i < num; i++)
            {
                string pname;
                cin >> pname;
                deleteNode(&flights[index], pname); // DELETE NODE TO CANCEL RESERVATION
            }
            break;
        case 3:
            cin >> fname;
            index = llFinder(fname, size, arrno); // FIND INDEX OF REQUIRED LINKED LIST
            cout << "OUTPUT:";
            display(flights[index]); // PRINT ALL NAMES
            break;
        case 4:
            cin >> fname;
            index = llFinder(fname, size, arrno); // FIND INDEX OF REQUIRED LINKED LIST
            if (index == -1)
            {
                cout << "Enter valid flight name!" << endl;
                exit(1);
            }
            cout << "OUTPUT:";
            cout << count(flights[index]) << endl; // COUNT NO. OF PASSENGERS
            break;
        case 5:
            cout << "Quitting...";
            exit(0); // EXIT THE PROGRAM
        default:
            cout << "Enter valid choice!" << endl;
            exit(1);
        }
    }
    return 0;
}
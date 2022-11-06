#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void appendNode(int);
    void deleteNode(int);
    void printList();
};
void LinkedList::appendNode(int data)
{
    Node* new_node = new Node(data);

    Node* temp = head;

    if (head == NULL)
        {
            head = new_node;
            return;
        }
    // To traverse till end of list
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    return;

}
void LinkedList::deleteNode(int nodeOffset)
{
    Node* temp1 = head; // Prior position
    Node* temp2 = NULL; // track position after the node to be removed
    int lengthOfList = 0;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
        lengthOfList+=1;
    }
    if(nodeOffset>lengthOfList)
    {
        cout<<"Index out of range"<<endl;
        return;
    }
    temp1= head;
    if(nodeOffset==1)
    {
        head = head->next;
        delete temp1;
        return;
    }
    while(nodeOffset>1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        nodeOffset-=1;
    }
    temp2->next = temp1->next;
    delete temp1;
    return;
}

void LinkedList::printList()
{
    Node* temp = head;
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            cout<<temp->data<<"."<<endl;
        }
        else
        {
            cout<<temp->data<<"->";
        }
        temp=temp->next;
    }
}



int main(){
    int length;
    cout<<"Length of Linked list : ";
    cin>> length;
     
    LinkedList list;
    int32_t data=0;
    while(length!=0){
        cin>> data;
        list.appendNode(data);
        length-=1;
    }
    cout<<"This is your list : ";
    list.printList();
    list.deleteNode(4);
    list.printList();


    return 0;
}
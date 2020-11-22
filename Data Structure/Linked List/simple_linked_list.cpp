#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
    Node *next;
};


void append(Node **head_ref, int new_data){
    Node *new_node = new Node();
    Node *last = (*head_ref);
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        (*head_ref) = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next=new_node;
    return;
}


int push(Node **head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void insert_after(Node *previous_node, int new_data){
    if(previous_node==NULL){
        cout<<"Previous Node can't be null"<<endl;
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = previous_node->next;
    previous_node->next = new_node;

}

void delete_node(Node **head_ref, int key){
    Node *temp = (*head_ref);
    Node *prev = NULL;

    if(temp !=NULL && temp->data == key){
        (*head_ref) = temp->next;
        delete temp;
        return;
    }

    while(temp->next != NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;

    delete temp;

    cout<<"Node: "<<key<<" Deleted!!"<<endl;
}

int print_list(Node *n){
    while(n!=NULL){
        cout << n->data<<" ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;

    append(&head, 6);
    append(&head, 7);
    append(&head, 8);
    append(&head, 9);
    delete_node(&head, 9);
    push(&head,5);
    push(&head,4);
    insert_after(head->next->next, 8);

    print_list(head);
}
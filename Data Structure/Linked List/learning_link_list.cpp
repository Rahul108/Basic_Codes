//**** traversal on link list ****

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printlist(struct Node *n){
    while(n!=NULL){
        cout << n->data << endl;
        n = n -> next;
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printlist(head);

    return 0;
}



// ***** Adding new Node to link list **********

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){
    if(prev_node == NULL){
        cout << "The given previous node cannot be null" << endl;
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printlist(struct Node* node){
    while(node != NULL){
        cout << node->data << endl;
        node = node->next;
    }
}

int main()
{
    struct Node* head = NULL;
    //append(&head,6);
    //push(&head,7);
    //push(&head,1);
    //append(&head,4);
    //insertAfter(head->next,8);
    //printlist(head);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int nn;
        cin >> nn;
        append(&head,nn);
    }
    printlist(head);
}


// ******* Delete a Node by key ********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deletenode(struct Node** head_ref, int key){
    struct Node* temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void printlist(struct Node *node){
    while(node != NULL){
        cout << node->data << " " ;
        node= node -> next;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);

    cout << "Created Link List : " << endl;
    printlist(head);
    deletenode(&head,1);
    cout << "Link List after deletion" << endl;
    printlist(head);
    return 0;
}
*/


//Deleting a node at a given position
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deletenode(struct Node **head_ref, int position){
    if(*head_ref == NULL){
        return;
    }
    struct Node* temp = *head_ref;
    if(position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i=0; temp != NULL && i<position-1; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        return;
    }

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void printlist(struct Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    push(&head,8);

    cout << "created : " << endl;
    printlist(head);
    deletenode(&head,4);
    cout << "After Deleting : " << endl;
    printlist(head);
    return 0;
}
*/


// ******* Delete a whole Link list *********

/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void deletelist(struct Node** head_ref){
    struct Node* current = *head_ref;
    struct Node* next;

    while(current != NULL){
        next = current -> next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct Node* head = NULL;
    push(&head,1);
    push(&head,4);
    push(&head,1);
    push(&head,12);
    push(&head,1);
    deletelist(&head);
}
*/

// **** Count the Number of node in Link list  ******
/*

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int getcount(struct Node* head){
    if(head == NULL){
        return 0;
    }
    return  1 + getcount(head->next);
}

int main()
{
    struct Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    cout << getcount(head) << endl;
    return 0;
}
*/

// ******** Write a function to get Nth node in a Linked List ********
/*
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int getTh(Node* head, int index){
    Node* current = head;
    int count = 0;
    while(current != NULL){
        if(count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0);
}

int main(){
    Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    int n;
    cin >> n;

    cout << "Element at index "<< n << " is: "<< getTh(head,3);
    return 0;
}
*/

// ******** Write a function to get Nth node in a Linked List (recursive) ********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int getTh(struct Node* head, int n){
    int count = 1;
    if(count==n){
        return head->data;
    }
    return getTh(head->next,n-1);
}

int main()
{
    struct Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,1);
    push(&head,5);

    int th;
    cin >> th;
    cout << th <<"'th element: " << getTh(head,th) << endl;
    return 0;
}
*/

// ******* Program for n’th node from the end of a Linked List (using length) ********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void prinfnthfromlast(struct Node* head, int n){
    int len = 0, i;
    struct Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    if(len<n){
        return;
    }

    temp = head;

    for(int i=1;i<len-n+1;i++){
        temp = temp->next;
    }

    cout << temp->data << endl;
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
   struct Node* head = NULL;
   push(&head,1);
   push(&head,3);
   push(&head,5);
   push(&head,7);
   push(&head,9);

   int th;
   cin >> th;

   prinfnthfromlast(head,th);
   return 0;
}
*/

// ******* Program for n’th node from the end of a Linked List (using length #RECURSIVE#) ********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printnthfromlast(struct Node* head, int n){
    static int i=0;
    if(head==NULL)
        return;
    printnthfromlast(head->next, n);
    if(++i == n){
        cout << head->data << endl ;
    }
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
   struct Node* head = NULL;
   push(&head,1);
   push(&head,3);
   push(&head,5);
   push(&head,7);
   push(&head,9);

   int th;
   cin >> th;

   printnthfromlast(head,th);
   return 0;
}
*/

// ******* Program for n’th node from the end of a Linked List (using two pointer) ********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printnthfromlast(struct Node *head, int n){
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    int count = 0;
    if(head != NULL){
        while(count < n){
            if(ref_ptr == NULL){
                cout << "N is greater than number of nodes in the list" <<endl;
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        while(ref_ptr != NULL){
            main_ptr = main_ptr->next;
            ref_ptr  = ref_ptr->next;
        }
        cout << main_ptr->data;
    }
}

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


int main()
{
   struct Node* head = NULL;
   push(&head,1);
   push(&head,3);
   push(&head,5);
   push(&head,7);
   push(&head,9);

   int th;
   cin >> th;

   printnthfromlast(head,th);
   return 0;
}
*/


// *********** Find the middle of a given linked list (using Two pointer) **********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printmiddle(struct Node* head){
    struct Node* fast_ptr = head;
    struct Node* slow_ptr = head;
    if(head != NULL){
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout<<slow_ptr->data<<endl;
    }
}


void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printlist(struct Node* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}


int main()
{
    struct Node* head = NULL;
    int i;
     for(int i=5;i>0;i--){
        push(&head,i);
        printlist(head);
        printmiddle(head);
     }
     return 0;
}
*/

// *********** Find the middle of a given linked list (using odd number method) **********
/*
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printmiddle(struct Node* head){
    int count = 0;
    struct Node* mid = head;

    while(head != NULL){
        if(count & 1){
            mid = mid->next;
        }
        count++;
        head=head->next;
    }
    if(mid != NULL){
        cout<<mid->data<<endl;
    }
}


void push(struct Node** head_ref,int new_data){
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printlist(struct Node* ptr){
    while(ptr != NULL){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL"<<endl;
}

int main()
{
    struct Node* head = NULL;
    int i;
    for(i=5;i>0;i--){
        push(&head,i);
        printlist(head);
        printmiddle(head);
    }
    return 0;
}
*/

// ********* Merge two sorted link list ************



/* C++ program to merge two sorted linked lists */

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* pull off the front node of
the source and put it in dest */
void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node* SortedMerge(Node* a, Node* b)
{
	/* a dummy first node to hang the result on */
	Node dummy;

	/* tail points to the last result node */
	Node* tail = &dummy;

	/* so tail->next is the place to
	add new nodes to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

Affter calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(Node** destRef, Node** sourceRef)
{
	/* the front source node */
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}


/* Function to insert a node at
the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	/* Let us create two sorted linked lists
	to test the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}


















#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node *next;
};

void printList(node *n){
    while(n != NULL){
        cout<<n -> data<<"\n";
        n = n -> next;
    }
}

void pushBack(node** head, int d){
    node *n = new node();
    node *l = *head;

    n -> data = d;

    if(*head == NULL){
        *head = n;
        return;
    }

    while(l -> next != NULL){
        l = l -> next;
    }

    l -> next = n;
    return;
}

void pushFront(node** head, int d){
    node *n = new node();
    n -> data = d;
    n -> next = (*head);
    (*head) = n;
}

void insertAfter(node *prev, int d){
    node *n = new node();
    n -> data = d;
    n -> next = prev -> next;
    prev -> next = n;
}

void deleteKey(node *head, int key){
    while(1){
        if(head->next->data == key){
            node *n = head->next;
            head->next = head->next->next;
            free(n);
            break;
        }
        head = head->next;
    }
}

void deleteLinkedList(node** head){
    node *n = (*head);
    while(n->next != NULL){
        node *nxt = n->next;
        free(n);
        n = nxt;
    }
}

int length(node *head){
    int l = 0;
    while(head != NULL){
        l++;
        head = head->next;
    }
    return l;
}

bool detectLoop(node** head){
    map<node*,bool> m;
    node *n = (*head);
    while(n != NULL){
        if(m[n] == true) return true;
        m[n] = true;
        n = n->next;
    }
    return false;
}


int main()
{
    node* head = NULL;
    pushBack(&head,2);
    pushFront(&head,1);
    pushBack(&head,1);
    insertAfter(head->next,3);
    //head->next->next->next = head->next;
    //deleteKey(head,3);
    //deleteLinkedList(&head);
    //cout<<length(head)<<"\n";
    //printList(head);
    cout<<detectLoop(&head);
    return 0;
}
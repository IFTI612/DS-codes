#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

};


node *root = NULL;

int cont =0;

void list_size()
{
    node *curr_node = root;
    while (curr_node !=NULL)
    {

        cont++;
        curr_node= curr_node -> next;

    }
    cout<<cont<<endl;
}



void last_node()
{

    node *prev;
    node *curr_node = root;
    while(curr_node != NULL)
    {
        prev = curr_node;
        curr_node = curr_node -> next;
    }
    cout<<prev->data<<endl;
}


void Prev_of_last_node()
{
    node *ager_node;
    node *prev;

    node *curr_node = root;

    while(curr_node != NULL)
    {
        ager_node = prev;
        prev = curr_node;
        curr_node = curr_node -> next;
    }
    cout<<ager_node->data<<endl;
}



void rev_print(node *curr_node)
{
    if(curr_node != NULL)
    {
        rev_print(curr_node-> next);
        cout<<curr_node->data<<endl;
    }
}


void Searching(int val)
{
    node *curr_node = root;

    while(curr_node!= NULL)
    {
        if(curr_node->data==val)
        {
            cout<<"Found"<<endl;
            return ;
        }
        curr_node = curr_node ->next;
    }
    cout<<"NOT found"<<endl;
}




void printing()
{

    node *curr_node = root;
    while (curr_node !=NULL)
    {

        cout<<curr_node -> data<<endl;
        curr_node= curr_node -> next;

    }
}



void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
        {
           node * curr_node = root;
           while(curr_node->next !=NULL)
           {
               curr_node = curr_node->next;
           }
           curr_node->next = temp;
        }
}




void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
        {
            temp -> next = root;
            root = temp;

        }
}

void insert_anywhere(int val , int n)
{
     node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    int i = 1;
    if(root == NULL)
    {
        root = temp;
    }
    else
        {
           node * curr_node = root;
           node *pore_node = curr_node->next;

           while(i<n-1)
           {
               curr_node = curr_node->next;
               pore_node = curr_node->next;
               i++;
           }
           curr_node->next = temp;
           temp->next =pore_node;
        }

}

void delete_first()
{


    if(root !=NULL)
    {
        root = root->next;



    }
}



void delete_last()
{


    node *curr_node = root;


    while(curr_node->next->next != NULL)
    {

        curr_node = curr_node -> next;

    }
    curr_node->next = NULL;


}


void delete_anywhere(int n)
{
    node *curr_node = root;
    node *porer_node;
    int i = 1;

    while(i<n-1)
    {
        curr_node = curr_node-> next;
        i++;

    }
    porer_node = curr_node->next;
    curr_node->next = porer_node ->next;



}



void delete_anywhere_value(int searchNum)
{
    node *curr_node = root;
    int index = 1;

    while(curr_node!=NULL)
    {
        if(curr_node->data == searchNum)
        {
            delete_anywhere(index);
            return;
        }
        index++;
        curr_node = curr_node->next;
    }
}


int main()
{
    int n,m,l,d;

//
//    cout<<"insert first"<<endl;
//    cin>>n;
//
//    for(int i = 0; i<n; i++)
//    {
//        cin>>m;
//        insert_first(m);
//    }
//    cout<<endl;
//    printing();

    cout<<"insert last like vector"<<endl;
    cin>>l;
    for(int i = 1; i<=l; i++)
    {
        cin>>m;
        insert_last(m);
    }

//    cout<<endl;
//    printing();
//    cout<<endl;
//    rev_print(root);
//    cout<<endl;
//    last_node();
//    cout<<endl;
//    list_size();
    cout<<"enter a value and then position for insert list"<<endl;
   cin>>d;
   cin>>n;
   insert_anywhere(d,n);

    cout<<endl;
     printing();


    return 0;


}


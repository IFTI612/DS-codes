#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int index = 0;
    node *next;
    node *prev;

};


node *root = NULL;
node *tail = NULL;


int cont =0;
int siz = 0;





 node* getNodeAtIndex(int ind) {
        node* current = root;

        while (current !=NULL) {
            if (current->index == ind) {
                return current;

            }
            current = current->next;
        }
        return nullptr;
    }


int Bin_Search(int key)
{

    int lo = 0;
    int hi =  cont - 1;
    int mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        node* midNode = getNodeAtIndex(mid);


        if (midNode == NULL)
        {
            cout<<"Not found"<<endl;
            return 0;

        }


        if(midNode->data == key)
        {
            cout<<"found"<<endl;
            return 1;

        }
        else if(midNode->data > key)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout<<"Not found"<<endl;
    return 0;
}



int list_size()
{
    node *curr_node = root;
    while (curr_node !=NULL)
    {

        siz++;
        curr_node= curr_node -> next;

    }
    return siz;
    //cout<<cont<<endl;
}



void last_node()
{
   cout<< tail->data<<endl;
}


void Prev_of_last_node()
{
    cout<< tail->prev->data<<endl;
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
    cout<<endl;
    curr_node = tail;
    while (curr_node !=NULL)
    {

        cout<<curr_node -> data<<endl;
        curr_node= curr_node -> prev;

    }
    cout<<endl;
}



void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp ->index = cont;
    temp -> data = val;
    temp -> next = NULL;
    temp ->prev = NULL;
    temp->index = cont;
    if(root == NULL)
    {
        root = temp;
        tail = temp;
        cont++;
    }
    else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            cont++;

        }



}




void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;
    temp ->prev = NULL;
    if(root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
        {
            temp -> next = root;
            root->prev = temp;
            root = temp;

        }

}

void insert_anywhere(int val , int n)///1,2,3,4,
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;
    temp -> prev = NULL;
    int last_index = list_size();
    int i = 1;
    if(root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
        {
            if(n==1)
            {
                insert_first(val);
            }
            else if(n == last_index+1)
            {
                insert_last(val);
            }
            else
            {
                node * curr_node = root;
           node *porer_node=curr_node->next;

           while(i<n - 1)
           {
               curr_node = curr_node->next;
               porer_node = curr_node->next;
               i++;
           }
           curr_node->next = temp;
           temp->prev = curr_node;

           temp ->next = porer_node;
           porer_node->prev =temp;
            }




        }

}

void delete_first()
{


    if(root !=NULL)
    {
        root = root->next;
        root->prev = NULL;

    }
}



void delete_last()
{


   if(tail!= NULL)
   {
       tail = tail->prev;
       tail->next = NULL;
   }


}


void delete_anywhere(int n)//1,2,3
{
    node *curr_node = root;
    node *porer_porer_node=curr_node->next->next;

    int i = 1;

    while(i<n-1)
    {

        curr_node = curr_node-> next;
        porer_porer_node = curr_node ->next;
        i++;

    }
    curr_node->next = porer_porer_node;
    porer_porer_node->prev = curr_node;




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
    insert_last(10);
    insert_last(20);
    insert_last(30);




    printing();

//    cout<<endl;
//    last_node();
//    cout<<endl;
//    Prev_of_last_node();
//    Searching(20);
//
//    rev_print(root);
//delete_first();
//printing();

//delete_last();

//delete_anywhere(2);

//insert_anywhere(50,4);


//printing();
Bin_Search(10);

    return 0;


}



#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *link;
};
struct node *start=NULL;
int insert_b()
{   //struct node *temp;
    int key; 
   // temp=(struct node*)malloc(sizeof(struct node ));
    struct node *temp=new node;
    cout<<"enter the data ";
    cin>>key;
    temp->data=key;
    if(start==NULL){
      start=temp;
      temp->link=NULL;
    }
    else{
      temp->link=start;
      start=temp;
    }
    return 0;
}
int insert_e()
{   struct node *ptr=start;
    int key;
    ptr=start;
    //temp=(struct node*)malloc(sizeof(struct node));
    struct node *temp=new node;
    cout<<"enter the data ";
    cin>>key;
    temp->data=key;
    if(start==NULL){
      start=temp;
      temp->link=NULL;
    }
    else{
      while(ptr->link!=NULL)
          ptr=ptr->link;
      ptr->link=temp;
      temp->link=NULL;
    }
    return 0;
}
int del_key()
{   int key,check=0;
    cout<<"enter key ";
    cin>>key;
    struct node *temp=start,*prev=NULL;
    while(temp!=NULL)
    {  if(start->data==key){
         start=start->link;
         check=1;
         cout<<"deleted\n";
         return 0;
       }
       else if(temp->data==key){
         prev->link=temp->link;
         delete temp;
         check=1;
         cout<<"deleted\n";
         return 0;
       }
       prev=temp;
       temp=temp->link;
       
    }
    if(check==0)
       cout<<"element not found\n";
    cout<<endl;
    return 0;
}
int del_b()
{   struct node *ptr=start;
    if(start==NULL)
      cout<<"list is empty\n";
    else{
      start=ptr->link;
      ptr->link=NULL;
      delete(ptr);
      cout<<"deleted\n";
    }
    return 0;
}
int del_l()
{   struct node *ptr=start;
    if(start==NULL)
      cout<<"list is empty\n";
    else if(start->link==NULL){
      delete(start);
      start=NULL;
      cout<<"deleted\n";
    }
    else{
      while(ptr->link->link!=NULL){
         ptr=ptr->link;
      }
      delete(ptr->link);
      ptr->link=NULL;
      cout<<"deleted\n";
    }
    return 0;
}
int show()
{   struct node *ptr=start;
    if(start==NULL){
       cout<<"list is empty\n";
       return 0;
    }
    else{
       while(ptr!=NULL){
         cout<<ptr->data<<" ";
         ptr=ptr->link;
       }   
    }
    cout<<endl;
    return 0;
}
int r_show()
{   struct node *prev=NULL,*cur=start,*next;
    while(cur!=NULL){
      next=cur->link;
      cur->link=prev;
      prev=cur;
      cur=next;
      
    }
    start=prev;
    struct node *temp=start;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->link;
    }
    cout<<endl;
    return 0;
}
int main()
{   int y;
    do{
    cout<<"1.insert a node from begining\n";
    cout<<"2.insert a node from end\n";
    cout<<"3.delete a node using key\n";
    cout<<"4.delete a node from begining\n";
    cout<<"5.delete a node from last\n";
    cout<<"6.print all nodes\n";
    cout<<"7.print all nodes in reverse order\n";
    int x;
    cin>>x;
    switch(x)
    {  case 1: insert_b();
               break;
       case 2: insert_e();
               break;
       case 3: del_key();
               break;
       case 4: del_b();
               break;
       case 5: del_l();
               break;
       case 6: show();
               break;
       case 7: r_show();
               break;
       
       default: cout<<"enter correct choice \n";
    }
    cout<<"\n\npress 0 to rerun\n";
    cin>>y;
    cout<<"\033[2J\033[1;1H";
    }while(y==0);
    return 0;
 }

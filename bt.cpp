#include<iostream>
using namespace std;
class Node{
  public:
     int data;
     //children
     Node*left;
     Node*right;

	Node(int val){
	  data=val;
	  left=NULL;
	  right=NULL;
   }
   };

class BST{
  public:
	Node*root;
	BST(){
	  root=NULL;
	 }
   void insert(int value){
	insertHelper(root,value);
    }
   void insertHelper(Node*curr,int value){
	//base case if curr is NULL insert there
         if(root==NULL){
	   root=new Node(value);
	}
	//else compare the current data with value
	else if (value<curr->data){
	    //if value<curr data->
	    //if left is null,insert it
	    //else mov left and call insertH
	     if(curr->left==NULL)curr->left=new Node(value);
	     else insertHelper(curr->left,value);
        }
	else{ 
	   //else move right and call insertH
	   if(curr->right==NULL)curr->right=new Node(value);
	   else insertHelper(curr->right,value);
	 }
	}

   void display(){display2(root);}
   void display2(Node*curr){
	//condition
	if(curr==NULL) return;
	//display left
	display2(curr->left);
	//display current
	cout<<curr->data<<",";
	//display right
	display2(curr->right);
	}
  Node*search(int value){
	 return search2(root,value);}
  Node* search2(Node*curr,int value){
      //if value found or reached end of the tree
        if(curr==NULL || curr->data==value)return curr;
	else if (value < curr->data)return search2 (curr->left,value);
        else return search2(curr->right,value);	
	}
	   };
  
int main(){
	BST t1;
   t1.insert(12);
   t1.insert(13);
   t1.insert(10);
   t1.insert(9);
   t1.insert(11);
   t1.insert(6);
   t1.display();cout<<endl;
   int number;
   cout<<"enter no to be searched -";
    cin>>number;
    t1.search(number);
    if(t1.search(number)!=NULL) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
   
	}














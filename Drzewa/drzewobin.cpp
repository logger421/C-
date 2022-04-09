#include <iostream>
using namespace std;

typedef int Telement; 
 
struct Node 
{ 
        Telement info; 
	Node * left; 
    	Node * right; 
}; 
 
typedef Node *PNode;

class BinaryTree 
{ 
protected: 
	PNode T; 
public: 
	BinaryTree() {
		T = NULL;
	} 

	PNode PARENT(PNode n);

	PNode PARENT1(PNode n,PNode T);

	PNode LEFT_CHILD(PNode n) 
	{
		return n->left;
	}
	PNode RIGHT_CHILD(PNode n) 
	{
		return n->right;
	}

	Telement GetLabel(PNode n)
	{
		return n->info;
	} 
 	
	PNode BuildTree1(int m)
	{
		if(m == 0) return NULL;
		int left,right;
		Telement x;
		PNode temp;
		left = m/2;
		right = m - left - 1;
		cout << "Podaj element: ";
		cin >> x;
		temp = new Node;
		temp->info = x;
		temp = BuildTree1(left);
		temp = BuildTree1(right);
		return temp;
	}
	void BuildTree(int m)
	{
		T = BuildTree1(m);
	}
 	
	PNode ROOT()
	{
		return T;
	} 

 	void MAKENULL(PNode p) 
	{
		if (p != NULL) {
			if (p->left != NULL) 
				MAKENULL(p->left);
			if (p->right != NULL)
				MAKENULL(p->right);
			delete p;
			p = NULL;
		}
	} 
 	
	void PreOrder(PNode t) 
	{
		if( t != NULL ) {
			cout << t->info;
			PreOrder(t->left);
			PreOrder(t->right);
		}
	}

 	void InOrder(PNode t) 
	{
		if ( t == NULL ) return;
		InOrder(t->left);
		cout << t->info;
		InOrder(t->right);
	}

 	void PostOrder(PNode t) 
	{
		if( t != NULL) {
			PostOrder(t->left);
			PostOrder(t->right);
			cout << t->info;
		}
	}
};

int main() {

	return 0;
}

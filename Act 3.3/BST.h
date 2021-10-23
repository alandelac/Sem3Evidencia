// Matrícula:
// Nomber:
#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();
		void add(dataCS data);
		void print();
	private:
		NodeT *root;
		void inOrdenC(NodeT *r);
		void destuye_Helper(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destuye_Helper(root);
}

void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}
void BST::add(dataCS data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

void BST::print(){
	inOrdenC(root);
	cout << endl;
}

void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData();
		inOrdenC(r->getLeft());
	}
}
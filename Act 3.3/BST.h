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

// constructor default
BST::BST(){
	root = nullptr;
}

// destruir el arbol
BST::~BST(){
	destuye_Helper(root);
}

// para borrar el arbol: Complejidad O(n)
void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

// añadir un nuevo nodo al arbol. Complejidad O(n)
void BST::add(dataCS data){
	
	// si la raiz es nula agregar el dato al principio
	if (root == nullptr){
		root = new NodeT(data);
	}

	// acomodar el dato en el lugar correcto
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

// imprimir el arbol complejidad O(1)
void BST::print(){
	inOrdenC(root);
	cout << endl;
}

// acomodar el arbol e imprimir los datos complejidad O(n)
void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData();
		inOrdenC(r->getLeft());
	}
}
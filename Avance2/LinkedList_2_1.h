//Complejidad O(n)
template <class T>
void LinkedList<T>::reverse() {
    if(this->size == 0 || this->size == 1){ return;}
    Node<T> *aux;
    Node<T> *curr;
    aux = nullptr;
    curr = head ->getNext();
    head -> setNext(nullptr);
    while (curr != nullptr){
        aux = head;
        head = curr;
        curr = curr -> getNext();
        head -> setNext(aux);
    }
    
}

//Complejidad O(n)
template <class T>
void LinkedList<T>::shift(int n) {
    int res = n % this -> size;
    if(res == 0 || this -> size == 1 || this -> size == 0){ return; }
    if(res < 0) {    res += this -> size;    }
    Node<T> *aux;
    Node<T> *curr1 = this -> head;
    
    int saltos = size - res;
    for(int i = 0; i<saltos; i++){
        aux = this -> head;
        head = head -> getNext();
    }
    aux -> setNext(nullptr);
    aux = this -> head;
    while (aux->getNext() )
    {
        aux = aux -> getNext();
    }
    aux -> setNext(curr1);
    
}

//Complejidad O(n)
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &otra) {
    if(this->size != otra.size){
        return false;
    }
    Node<T> *curr1 = this->head;
    Node<T> *curr2 = otra.head;
    while (curr1 != nullptr){
        if(curr1->getData() != curr2->getData()){
            return false;
        }
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
    return true;
}


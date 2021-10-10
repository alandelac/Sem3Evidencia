#include "Node.h"

template <class T>
class LinkedList{
    public: 
        LinkedList();
        LinkedList(const LinkedList<T> &otra);
        ~LinkedList();
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
        T get(int pos);
        T set(T data, int pos);
        void change(int pos1, int pos2);
        bool isEmpty();
        int getSize();
        void print();
        void SortList();
        void SortListBy3UBI();
        void saveInFile(string a);
        void buscarUbiPorMes(string busqueda);

        void reverse();
        void shift(int n);
        bool operator==(const LinkedList<T> &otra);

        void operator+=(const LinkedList<T> &otra);
        void operator=(const LinkedList<T> &otra);

    private:
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    deleteAll();
}

template <class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    if(size == 0) {
        addFirst(data);
    }else{
        Node<T> *curr = head;
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos) {
    if(pos > size) {
        return false;
    }
    if(pos == 0) {
        addFirst(data);
    } else if (pos == size) {
        addLast(data);
    } else {
        Node<T> *curr = head;
        for (int i=1; i<pos; i++) {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
    }
    return true;
}

template <class T>
void LinkedList<T>::deleteFirst() {
    if(size != 0) {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast() {
    if(size <= 1) {
        deleteFirst();
    }else{
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr) {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(nullptr);
        size--;
    }
}

template <class T>
// Complejidad peor caso O(n)
void LinkedList<T>::del(int pos) {
    if(pos == 0) {
        deleteFirst();
    } else if (pos == size - 1){
        deleteLast();
    } else {
        Node<T> *curr = head;
        for (int i=1; i<pos; i++){
            curr = curr->getNext();
        }
        Node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext()); // curr->setNext(curr->getNext()->getNext())
        delete aux;
        size--;
    }
}

template <class T>
// Complejidad O(n)
int LinkedList<T>::deleteAll() {
    Node<T> *curr = head;
    while(head != nullptr) {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int cant = size;
    size = 0;
    return cant; 
}

template <class T>
T LinkedList<T>::get(int pos) {
    Node<T> *curr = head;
    for(int i = 0; i < pos; i++) {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos) {
    Node<T> *curr = head;
    for(int i = 0; i < pos; i++) {
        curr = curr->getNext();
    }
    T aux = curr->getData();
    curr->setData(data);
    return aux;
}

// complejidad O(n)
template <class T>
void LinkedList<T>::change(int pos1, int pos2) {
    if( pos1 != pos2) {
        int posMen = (pos1 < pos2) ? pos1 : pos2;
        int posMay = (pos1 > pos2) ? pos1 : pos2;
        Node<T> *curr1 = head;
        for (int i=1; i<=posMen; i++) {
            curr1 = curr1->getNext();
        }
        Node<T> *curr2 = curr1;
        for(int i=1; i<=(posMay - posMen); i++) {
            curr2 = curr2->getNext();
        }
        T dataAux = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(dataAux);
    }
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return (size == 0);
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
// Complejidad O(n)
void LinkedList<T>::print() {
    Node<T> *curr = head;
    while(curr != nullptr){
        registro r1 = curr->getData();
        cout << r1.ubi << " " << r1.fecha << " " << r1.hora << " " << r1.entrada  << endl ;
        curr = curr->getNext();
    }
}

template <class T>
void LinkedList<T>::saveInFile(string a){
    ofstream archivoM(a + ".txt");
    Node <T> *curr = head;
    while (curr != nullptr){
        registro r1 = curr->getData();
        archivoM << r1.ubi << " " << r1.fecha << " " << r1.hora << " " << r1.entrada  << endl ;
        curr = curr ->getNext();
    }
    archivoM.close();
}

template <class T>
void LinkedList<T>::buscarUbiPorMes(string busqueda){
    Node<T> *curr = head;
    registro rViaje = curr->getData();
    vector<contBuques> fechasDeSalida;
    int i = 0;
    while(curr != nullptr){
        while (rViaje.ubi.substr(0, 3) == busqueda){
            string fecha = rViaje.fecha.substr(rViaje.fecha.find("-") + 1);

            //Primera iteración
            if(fechasDeSalida.empty()){
                contBuques aux;
                aux.fechaSalida = fecha;
                if(rViaje.entrada == 'R') {
                    aux.contRojo = 1;
                    aux.contMedi = 0;
                } else { 
                    aux.contRojo = 0;
                    aux.contMedi = 1; 
                }
                fechasDeSalida.push_back(aux);
            }
            //Si la fecha es igual a la fecha anterior
            else if(fecha == fechasDeSalida[i].fechaSalida) {
                if(rViaje.entrada == 'R') {
                    fechasDeSalida[i].contRojo++;
                } else { fechasDeSalida[i].contMedi++; }
            }

            //Nuevo Mes
            else {
                contBuques aux;
                aux.fechaSalida = fecha;
                if(rViaje.entrada == 'R') {
                    aux.contRojo = 1;
                    aux.contMedi = 0;
                } else { 
                    aux.contMedi = 1; 
                    aux.contRojo = 0;
                }
                fechasDeSalida.push_back(aux);
                i++;
            }
            curr = curr -> getNext();
            rViaje = curr->getData();
        }
        curr = curr ->getNext();
        if(curr != nullptr){ rViaje = curr->getData(); };
    }


    for(int j = 0; j<fechasDeSalida.size(); j++){

        fechasDeSalida[j].fechaSalida[3] = ' ';
        cout<<fechasDeSalida[j].fechaSalida<<" "<<fechasDeSalida[j].contMedi<<" "<<fechasDeSalida[j].contRojo<<endl;
    }   
}


#include "LinkedList_2_1.h"
#include "LinkedList_2_2.h"
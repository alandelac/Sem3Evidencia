
//Complejidad O(n)
template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &otra)
{
    if (otra.size > 0)
    {
        Node<T> *c1 = head;
        Node<T> *c2 = otra.head;
        if (this->size == 0)
        {
            head = new Node<T>(otra.head->getData());
            c2 = c2->getNext();
        }
        c1 = head;
        while (c1->getNext() != nullptr)
        {
            c1 = c1->getNext();
        }
        while (c2 != nullptr)
        {
            c1->setNext(new Node<T>(c2->getData()));
            c1 = c1->getNext();
            c2 = c2->getNext();
        }
        size = size + otra.size;
    }
}

//complejidad O(n)
template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &otra)
{
    this->deleteAll();

    if (otra.size > 0)
    {
        this->head = new Node<T>(otra.head->getData());
        Node<T> *c1 = head;
        Node<T> *c2 = otra.head->getNext();
        while (c2 != nullptr)
        {
            c1->setNext(new Node<T>(c2->getData()));
            c1 = c1->getNext();
            c2 = c2->getNext();
        }
    }
}

//Complejidad O(n)
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &otra)
{
    head = nullptr;
    size = 0;
    if (otra.size > 0)
    {
        head = new Node<T>(otra.head->getData());
        Node<T> *c1 = head;
        Node<T> *c2 = otra.head->getNext();
        while (c2 != nullptr)
        {
            c1->setNext(new Node<T>(c2->getData()));
            c1 = c1->getNext();
            c2 = c2->getNext();
        }
        size = otra.size;
    }
}

// complejidad O(n^2)
template <class T>
void LinkedList<T>::SortList()
{
    if (size > 1)
    {
        Node<T> *curr1 = head;
        Node<T> *curr2 = curr1;

        while (curr1->getNext() != nullptr)
        {
            curr2 = curr1->getNext();
            while (curr2 != nullptr)
            {
                registro r1 = curr1->getData();
                registro r2 = curr2->getData();
                if (r1.ubi > r2.ubi)
                {
                    curr1->setData(r2);
                    curr2->setData(r1);
                }
                else if (r1.ubi == r2.ubi && r1.fechaInt > r2.fechaInt)
                {
                    curr1->setData(r2);
                    curr2->setData(r1);
                }
                curr2 = curr2->getNext();
            }
            curr1 = curr1->getNext();
        }
    }
}

// complejidad O(n^2)
template <class T>
void LinkedList<T>::SortListBy3UBI()
{
    if (size > 1)
    {
        Node<T> *curr1 = head;
        Node<T> *curr2 = curr1;

        while (curr1->getNext() != nullptr)
        {
            curr2 = curr1->getNext();
            while (curr2 != nullptr)
            {
                registro r1 = curr1->getData();
                registro r2 = curr2->getData();
                if (r1.ubi.substr(0, 3) > r2.ubi.substr(0, 3))
                {
                    curr1->setData(r2);
                    curr2->setData(r1);
                }
                else if (r1.ubi.substr(0, 3) == r2.ubi.substr(0, 3) && r1.fechaInt > r2.fechaInt)
                {
                    curr1->setData(r2);
                    curr2->setData(r1);
                }
                curr2 = curr2->getNext();
            }
            curr1 = curr1->getNext();
        }
    }
}
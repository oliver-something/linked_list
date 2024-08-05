template<class T>
bool Path<T>::deleteNode(T data) {
    if (firstNode == nullptr) return false;

    if (firstNode->data == data) {
        Node<T>* temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
        return true;
    }

    Node<T>* current = firstNode;
    while (current->next && current->next->data != data) {
        current = current->next;
    }

    if (current->next) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    return false;
}

template<class T>
void Path<T>::appendList(const Path<T> &other) {
    if (other.firstNode == nullptr) return;
    auto * current = other.firstNode;
    while (current != nullptr) {
        addNode(current->data);
        current = current->next;
    }
}

template<class T>
Path<T>::Path(const Path<T>& other) : firstNode(nullptr) {
    if (other.firstNode) {
        firstNode = new Node<T>(other.firstNode->data);
        Node<T>* currentOther = other.firstNode->next;
        Node<T>* currentThis = firstNode;

        while (currentOther) {
            currentThis->next = new Node<T>(currentOther->data);
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }
}

template<class T>
Path<T>& Path<T>::operator=(const Path<T>& other) {
    if (this == &other) return *this; // Handle self-assignment

    // Clean up existing nodes
    Node<T>* current = firstNode;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    firstNode = nullptr;

    // Copy nodes from the other list
    if (other.firstNode) {
        firstNode = new Node<T>(other.firstNode->data);
        Node<T>* currentOther = other.firstNode->next;
        Node<T>* currentThis = firstNode;

        while (currentOther) {
            currentThis->next = new Node<T>(currentOther->data);
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }

    return *this;
}

template<class T>
Node<T> *Path<T>::findNode(T data) {
    auto * current = firstNode;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
bool Path<T>::isEmpty() {
    return firstNode == nullptr;
}

template<class T>
int Path<T>::size() const {
    Node<T> * current = firstNode;
    int counter {0};
    while (current != nullptr) {
        counter += 1;
        current = current->next;
    }
    return counter;
}

template<class T>
void Path<T>::clear() {
    Node<T> * current = firstNode;
    while (current != nullptr) {
        Node<T> nextNode = current->next;
        delete current;
        current = current->next;
    }
    firstNode = nullptr;
}

template<class T>
void Path<T>::addNode(T data) {
    auto * newNode = new Node<T>(data);
    if (!firstNode) {
        firstNode = newNode;
    } else {
        Node<T> * current = firstNode;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<class T>
Path<T>::~Path() {
    Node<T>* current = firstNode;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    firstNode = nullptr;
}

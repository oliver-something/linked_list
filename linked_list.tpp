#include <cassert>

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
    auto * newNode = addNode(other.firstNode->data);
    auto * otherCurrent = other.firstNode->next;
    auto * current = newNode;

    while (otherCurrent != nullptr) {
        current->next = new Node<T>(otherCurrent->data);
        current->next = current->next;
        otherCurrent = otherCurrent->next;
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
T& Path<T>::operator[](int index) {
    if (index < 0) {
        throw std::out_of_range("Index cannot be negative.");
    }

    Node<T>* current = firstNode;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        throw std::out_of_range("Index out of range.");
    }

    return current->data;
}


template<class T>
void Path<T>::bubbleSort() {
    bool state;
    for (int i = 0; i < this->size() - 1; ++i) {
        state = false;
        for (int j = 0; j < this->size() - 1 - i; ++j) {
            if ((*this)[j] > (*this)[j + 1]) {
                state = true;
                auto temp = (*this)[j];
                (*this)[j] = (*this)[j + 1];
                (*this)[j + 1] = temp;
            }
        }
        if(!state) break;
    }
}

template<class T>
bool Path<T>::isSorted() {
    // Empty List
    if (firstNode == nullptr or firstNode->next == nullptr) return true;
    auto current = firstNode;
    while (current->next != nullptr) {
        if (current->data > current->next->data) return false;
        current = current->next;
    }
    return true;
}

template<class T>
int Path<T>::binarySearch(T item) {
    if (!this->isSorted() or this->isEmpty()) return -1;
    int left = 0;
    int right = this->size() - 1;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if((*this)[mid] == item) return mid;
        else if ((*this)[mid] < item) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
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
Node<T> * Path<T>::addNode(T data) {
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
    return newNode;
}

template<class T>
std::vector<T> Path<T>::toVector() {
    auto * current = this->firstNode;
    std::vector<T> vector;
    while (current != nullptr) {
        vector.emplace_back(current->data);
        current = current->next;
    }
    return vector;
}

template<class T>
void Path<T>::insert(int position, T value) {
    assert(position >= 0);
    if (position == 0 and firstNode != nullptr) {
        firstNode = new Node<T>(value, firstNode);
        return;
    } else if (position == 0 and firstNode == nullptr) {
        firstNode = new Node<T>(value);
        return;
    }

    auto * current = firstNode;
    Node<T> * previous = nullptr;
    int index = 0;

    while (current != nullptr and index < position) {
        previous = current;
        current = current->next;
        index += 1;
    }

    if (index == position) {
        auto * newNode = new Node<T>(value, current);
        if (previous != nullptr) {
            previous->next = newNode;
        }
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

//
// Created by Oliver on 8/5/24.
//
#pragma one
#include <vector>

template<class T>
class Node final {
public:
    explicit Node(T data, Node<T> * next = nullptr): data(data), next(next) {}
    ~Node() = default;
    Node<T> * next;
    T data;
};

template<class T>
class Path {
public:
    explicit Path() = default;
    Path(const Path<T>& other);
    Node<T> * addNode(T data);
    bool deleteNode(T data);
    bool isEmpty();
    Node<T>* findNode(T data);
    Path<T>& operator=(const Path<T>& other);
    void appendList(const Path<T> & other);
    [[nodiscard]] int size() const;
    void clear();
    T & operator[](int index);
    void bubbleSort();
    bool isSorted();
    int binarySearch(T);
    std::vector<T> toVector();
    void insert(int, T);
    ~Path();
public:
    Node<T> * firstNode;
};

#include "linked_list.tpp"
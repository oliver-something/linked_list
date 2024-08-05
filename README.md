# Complete Implementation of Linked List in C++

```c++
    // Default constructor
    explicit Path() = default;
    // Creates a new linked list from existing list
    Path(const Path<T>& other);
    // Adds node to the path
    void addNode(T data);
    // Deletes the node if found O(N)
    bool deleteNode(T data);
    // Checks if the list is empty
    bool isEmpty();
    // Finds the node if found O(N)
    Node<T>* findNode(T data);
    // Copies another List into existing list (Deep Copy)
    Path<T>& operator=(const Path<T>& other);
    // Appends another list into existing list (Requires Optimization)
    void appendList(const Path<T> & other);
    // Returns the size of nodes
    [[nodiscard]] int size() const;
    // Cleans all nodes from the path and sets the first node to nullptr
    void clear();
    // Added support for index [] operator (Not optimized) O(N)
    T & operator[](int index);
    // Added support for bubbleSort (Not optimized at all)
    void bubbleSort();
    // Checks if linked list is sorted
    bool isSorted();
    // Binary Search support for the linked list (Not very optimized) O(N) worst case because of checking
    // if the list sorted or not. also used [] operator which is not very optimized either.
    int binarySearch(T);
    ~Path();
```

### To run the application simply build using cmake and make (Linux/macOS)

```shell
cmake -G "Unix Makefiles" -B cmake-build
cd cmake-build
make
./main
```
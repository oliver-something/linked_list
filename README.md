# Complete Implementation of Linked List in C++

```c++
    // Default constructor
    explicit Path() = default;
    // Creates a new linked list from existing list
    Path(const Path<T>& other);
    // Adds node to the path
    Node<T> * addNode(T data);
    // Deletes the node if found O(N)
    bool deleteNode(T data);
    // Checks if the list is empty
    bool isEmpty();
    // Finds the node if found O(N)
    Node<T>* findNode(T data);
    // Copies another List into existing list (Deep Copy)
    Path<T>& operator=(const Path<T>& other);
    // Appends another list into existing list, it is now optimized for O(N)
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
    // Converts the Linked list to vector
    std::vector<T> toVector();
    // Insert to specific part of the list
    // Insert from head is O(1) but anywhere else O(N)
    void insert(int index, T value);
    ~Path();
```

### To run the application simply build using cmake and make (Linux/macOS)

```shell
cmake -G "Unix Makefiles" -B cmake-build
cd cmake-build
make
./main
```

### A Simple real world example!

```c++
class Song {
    std::string name;
    std::string artist;
    int track_number;
    // bunch of other fields
public:
    friend std::ostream & operator<<(std::ostream &os, const Song & song) {
        return os << "song : " << song.name << ", Artist: " << song.artist << '\n';
    }
    explicit Song(std::string name, std::string artist, int track): name(std::move(name)),
    artist(std::move(artist)),
    track_number(track) {}
};

class Playlist : public Path<Song> {
public:
    explicit Playlist() = default;
};

template<class T>
void show(const Path<T> & path) {
    auto * current = path.firstNode;
    while (current != nullptr) {
        std::cout << current->data << '\n';
        current = current->next;
    }
}

int main() {
    Playlist playlist {};
    playlist.addNode(Song("The New High", "Trevor Something", 1));
    playlist.addNode(Song("You Are My Obsession", "Trevor Something", 4));
    playlist.addNode(Song("Fade Away", "Trevor Something", 3));

    show(playlist);
}
```
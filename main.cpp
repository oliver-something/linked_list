#include <utility>

#include "iostream"
#include "linked_list.hpp"
////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////
template<class T>
void show(const Path<T> & path) {
    auto * current = path.firstNode;
    while (current != nullptr) {
        std::cout << current->data << '\n';
        current = current->next;
    }
}

int sumIntNodes(const Path<int> & path) {
    auto current = path.firstNode;
    auto total {0};
    while (current != nullptr) {
        total += current->data;
        current = current->next;
    }
    return total;
}

int main() {
    const int value1 = 78;
    const int value2 = 89;
    const int value3 = 72;
    const int value4 = 12;

    Path<int> path {};

    path.addNode(value1);
    path.addNode(value2);
    path.addNode(value3);
    path.addNode(value4);

    show(path);

    Path<int> other {};
    other.addNode(23);
    other.addNode(90);
    other.addNode(43);

    std::cout << "After \n";

    path.appendList(other);

    show(path);
    auto test = sumIntNodes(path);
    std::cout << test << '\n';

    path.bubbleSort();
    show(path);

    auto item = path.binarySearch(90);
    std::cout << "index : "<<  item << '\n';

    // Creates the vector out of linked list
    std::cout << "vector : " << '\n';
    auto vec = path.toVector();
    for (auto & i: vec){
        std::cout << i << '\n';
    }
    // Inserting 12 to the beginning.
    std::cout << "Inserting 14 to the beginning\n";
    path.insert(0, 14);
    show(path);

    // Simple Real World Sample
    Playlist playlist {};
    playlist.addNode(Song("The New High", "Trevor Something", 1));
    playlist.addNode(Song("You Are My Obsession", "Trevor Something", 4));
    playlist.addNode(Song("Fade Away", "Trevor Something", 3));

    show(playlist);
    return 0;
}


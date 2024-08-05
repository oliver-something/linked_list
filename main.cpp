#include "iostream"
#include "linked_list.hpp"

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
    return 0;
}


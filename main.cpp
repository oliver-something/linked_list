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
    Path<std::string> names {};

    names.addNode("Oliver");
    names.addNode("John");
    names.addNode("Roger");
    names.addNode("Raj");


    show(names);

    Path<std::string> otherNames {};

    names.addNode("George");
    names.addNode("Taylor");
    names.addNode("Frank");

    std::cout << "After appending second list!\n";

    names.appendList(otherNames);
    show(names);

    return 0;
}


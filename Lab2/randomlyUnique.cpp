#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unsorted.h"

void PrintList(UnsortedType& list) {
    list.ResetList();
    for (int i = 0; i < list.GetLength(); ++i) {
        ItemType item = list.GetNextItem();
        item.Print(std::cout);
        std::cout << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    UnsortedType list;
    srand(time(0)); 
    bool found;
    ItemType item;

    std::cout << "Generating 50 unique random integers between 0 and 99." << std::endl;

    while (list.GetLength() < 50) {
        int randomNumber = rand() % 100;
        item.Initialize(randomNumber);

        list.GetItem(item, found);

        if (!found) {
            list.PutItem(item);
        }
    }

    std::cout << "Generated list of 50 unique integers:" << std::endl;
    PrintList(list);

    return 0;
}
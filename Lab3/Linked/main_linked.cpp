#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unsorted.h"
using namespace std;

int main() {
    srand(time(0));
    UnsortedType list;

    cout << "=== Case 1: Empty list ===" << endl;
    try {
        list.Head().Print(cout); cout << " ";
        list.Tail().Print(cout); cout << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    int midPoint = rand() % 50 + 1;
    for (int i = 1; i <= 50; i++) {
        ItemType item;
        item.Initialize(rand() % 100 + 1);
        list.PutItem(item);

        if (i == midPoint) {
            cout << "\n=== Case 2: Mid-fill (" << i << " items) ===" << endl;
            cout << "Head: "; list.Head().Print(cout);
            cout << "  Tail: "; list.Tail().Print(cout);
            cout << endl;
        }
    }

    cout << "\n=== Case 3: Full (50 items) ===" << endl;
    cout << "Head: "; list.Head().Print(cout);
    cout << "  Tail: "; list.Tail().Print(cout);
    cout << endl;

    cout << "\nList contents: ";
    list.ResetList();
    for (int j = 0; j < list.GetLength(); j++) {
        ItemType it = list.GetNextItem();
        it.Print(cout);
        cout << " ";
    }
    cout << endl;
    return 0;
}

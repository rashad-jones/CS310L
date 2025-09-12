#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <fstream>

const int MAX_ITEMS = 50; 
enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
  ItemType();
  RelationType ComparedTo(ItemType otherItem) const;
  void Print(std::ostream& out) const;
  void Initialize(int number);
private:
  int value;
};

#endif
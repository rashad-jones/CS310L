#ifndef UNSORTED_H
#define UNSORTED_H

#include "ItemType.h"

class UnsortedType {
public:
  UnsortedType();
  bool IsFull() const;
  int GetLength() const;
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  ItemType GetItem(ItemType item, bool& found);
  void ResetList();
  ItemType GetNextItem();
private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};

#endif
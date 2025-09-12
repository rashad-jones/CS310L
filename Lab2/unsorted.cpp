#include "unsorted.h"
#include <iostream>

UnsortedType::UnsortedType() {
  length = 0;
  currentPos = -1;
}

bool UnsortedType::IsFull() const {
  return (length == MAX_ITEMS);
}

int UnsortedType::GetLength() const {
  return length;
}

void UnsortedType::PutItem(ItemType item) {
  info[length] = item;
  length++;
}

void UnsortedType::DeleteItem(ItemType item) {
  int location = 0;
  while (location < length && item.ComparedTo(info[location]) != EQUAL) {
    location++;
  }
  if (location < length) {
    info[location] = info[length - 1];
    length--;
  }
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) {
  found = false;
  int location = 0;
  while (location < length && !found) {
    if (item.ComparedTo(info[location]) == EQUAL) {
      found = true;
      item = info[location];
    } else {
      location++;
    }
  }
  return item;
}

void UnsortedType::ResetList() {
  currentPos = -1;
}

ItemType UnsortedType::GetNextItem() {
  currentPos++;
  return info[currentPos];
}
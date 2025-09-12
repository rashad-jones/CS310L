#include "ItemType.h"

ItemType::ItemType() {
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const {
  if (value < otherItem.value) {
    return LESS;
  } else if (value > otherItem.value) {
    return GREATER;
  } else {
    return EQUAL;
  }
}

void ItemType::Print(std::ostream& out) const {
  out << value;
}

void ItemType::Initialize(int number) {
  value = number;
}
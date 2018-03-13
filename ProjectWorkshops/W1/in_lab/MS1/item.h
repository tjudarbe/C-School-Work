#ifndef _SICT_ITEM_H  // forces the complier to compile this
#define _SICT_ITEM_H  // header file only once.

struct Item {
  int quantity;  
  int minQuantity;
  double price;
  char taxed;  // 'y' or 'n'
  char name[61];
};



#endif
// main.cpp
#include "lib/linkedlist.hpp"
#include <iostream>
#include <ostream>

int
main ()
{
  LinkedList list;
  list.append (10);
  list.append (20);
  list.append (30);

  try
    {
      std::cout << "Value at index 1: " << list.get (1) << std::endl;
    }
  catch (const std::out_of_range &e)
    {
      std::cerr << e.what () << std::endl;
    }

  // print the linkedList
  std::cout << "The LL has: ";
  list.printList ();
  list.removeAt (1);

  std::cout << "Inserting at: pos 1 with value 15" << std::endl;
  list.insertAt (1, 15);

  std::cout << "Inserting at: end with value 5" << std::endl;
  list.append (5);

  std::cout << "The new LL has: ";
  list.printList ();

  return 0;
}

//===-- LinkedList/linkedlist.hpp - definition --------*-C++-*-=------===//
//
//
//===----------------------------------------------------------------------===//
///
/// \file linkedlist.hpp
/// \brief This file contains the declarations for the LinkedList class.
///
///
//===----------------------------------------------------------------------===//

// LinkedList.hpp
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/// \file LinkedList.hpp
///
/// \brief This file contains the declarations for the LinkedList class.

#include <iostream>
#include <memory>

class LinkedList
{
public:
  /// Default constructor.
  LinkedList ();

  /// Destructor.
  ~LinkedList ();

  /// Inserts a new element at the end of the LinkedList.
  ///
  /// \param value The value to insert.
  void append (int value);

  /// Removes the element at the specified index.
  ///
  /// \param index The index of the element to remove.
  void removeAt (int index);

  /// Inserts a new element at the specified index.
  ///
  /// \param index The index at which to insert the new element.
  /// \param value The value to insert.
  void insertAt (int index, int value);

  /// Retrieves the element at the specified index.
  ///
  /// \param index The index of the element to retrieve.
  /// \return The value of the element at the given index.
  int get (int index) const;

  /// Prints the entire LinkedList.
  void printList () const;

private:
  struct Node
  {
    int value;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> head;
};

#endif // LINKEDLIST_H
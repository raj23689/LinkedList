// LinkedList.cpp
#include "lib/linkedlist.hpp"

#include <stdexcept>

LinkedList::LinkedList () : head (nullptr) {}

LinkedList::~LinkedList ()
{
  while (head)
    {
      head = std::move (head->next);
    }
}

void
LinkedList::append (int value)
{
  if (!head)
    {
      head = std::make_unique<Node> ();
      head->value = value;
    }
  else
    {
      Node *current = head.get ();
      while (current->next)
        {
          current = current->next.get ();
        }
      current->next = std::make_unique<Node> ();
      current->next->value = value;
    }
}

void
LinkedList::removeAt (int index)
{
  if (index == 0 && head)
    {
      head = std::move (head->next);
      return;
    }

  Node *current = head.get ();
  for (int i = 0; current && i < index - 1; ++i)
    {
      current = current->next.get ();
    }

  if (current && current->next)
    {
      current->next = std::move (current->next->next);
    }
}

void
LinkedList::insertAt (int index, int value)
{
  if (index == 0)
    {
      auto newNode = std::make_unique<Node> ();
      newNode->value = value;
      newNode->next = std::move (head);
      head = std::move (newNode);
      return;
    }

  Node *current = head.get ();
  for (int i = 0; current && i < index - 1; ++i)
    {
      current = current->next.get ();
    }

  if (current)
    {
      auto newNode = std::make_unique<Node> ();
      newNode->value = value;
      newNode->next = std::move (current->next);
      current->next = std::move (newNode);
    }
  else
    {
      // If the index is out of bounds, throw an exception
      throw std::out_of_range ("Index out of range");
    }
}

int
LinkedList::get (int index) const
{
  Node *current = head.get ();
  for (int i = 0; current && i < index; ++i)
    {
      current = current->next.get ();
    }

  if (current)
    {
      return current->value;
    }

  throw std::out_of_range ("Index out of range");
}

void
LinkedList::printList () const
{
  Node *current = head.get ();
  while (current != nullptr)
    {
      std::cout << current->value << " -> ";
      current = current->next.get ();
    }
  std::cout << "null" << std::endl;
}
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
    if (!empty())
    {
        if (tail_->last == ARRSIZE)
        {
            Item* newItem = new Item();
            newItem->prev = tail_;
            tail_->next = newItem;
            tail_ = newItem;
        }
    }
    else
    {
        head_ = tail_ = new Item();
    }
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

void ULListStr::push_front(const std::string& val)
{
    if (!empty())
    {
        if (head_->first == 0)
        {
            Item* newItem = new Item();
            newItem->next = head_;
            head_->prev = newItem;
            head_ = newItem;
            head_->first = head_->last = ARRSIZE;
        }
    }
    else
    {
        head_ = tail_ = new Item();
        head_->first = head_->last = ARRSIZE;
    }
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
}

void ULListStr::pop_back()
{
    if (empty()) return;
    
    if (size_ == 1)
    {
        size_--;
        delete tail_;
        head_ = tail_ = nullptr;
        return;
    }
    
    // If there's only one element left in that item
    if (tail_->last - tail_->first == 1)
    {
        Item* newTail = tail_->prev;
        delete tail_;
        tail_ = newTail;
        tail_->next = nullptr;
        size_--;
        return;
    }
    
    // General case
    size_--;
    tail_->last--;
}

void ULListStr::pop_front()
{
    if (empty()) return;
    
    if (size_ == 1)
    {
        size_--;
        delete head_;
        head_ = tail_ = nullptr;
        return;
    }
    
    // If there's only one element left in that item
    if (head_->last - head_->first == 1)
    {
        Item* newHead = head_->next;
        delete head_;
        head_ = newHead;
        head_->prev = nullptr;
        size_--;
        return;
    }
    
    // General case
    size_--;
    head_->first++;
}

std::string const & ULListStr::back() const
{
    return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
    if (loc >= size_) return nullptr;
    
    Item* current = head_;
    int currentIndex = head_->first;
    for (size_t i = 0; i < loc; i++)
    {
        if (currentIndex < ARRSIZE - 1) currentIndex++;
        else
        {
            current = current->next;
            currentIndex = current->first;
        }
    }
    return current->val + currentIndex;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

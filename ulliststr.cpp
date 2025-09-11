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

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val) {
  if (tail_ == nullptr) {
    tail_ = new Item();
		head_ = tail_;
  }

  if (tail_->last == ARRSIZE) {
    Item* tmp = tail_;
    tail_ = new Item();
    tail_->prev = tmp;
    tmp->next = tail_;
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back() {
  tail_->last--;
  size_--;

  if (tail_->last == tail_->first) {
    Item* tmp = tail_;
    tail_ = tmp->prev;
		if (tail_ != nullptr) {
			tail_->next = nullptr;	
		} else {
			head_ = nullptr;
		}
    
    delete tmp;
  }
}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val) {
  if (head_ == nullptr) {
    head_ = new Item();
		tail_ = head_;
  } else if (head_->first == 0) {
    Item* tmp = head_;
    head_ = new Item();
    head_->next = tmp;
    tmp->prev = head_;
  } else {
    --head_->first;
    head_->val[head_->first] = val;
    size_++;
    return;
  }

  head_->last = ARRSIZE;
  head_->first = head_->last - 1;
  head_->val[head_->last-1] = val;
  size_++;
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front() {
  head_->first++;
  size_--;

  if (head_->last == head_->first) {
    Item* tmp = head_;
    head_ = tmp->next;
		if (head_ != nullptr) {
			head_->prev = nullptr;
		} else {
			tail_ = nullptr;
		}
    delete tmp;
  }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

//

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

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) {
    return NULL;
  }

  Item* curr = head_;
  size_t p = 0;
  
  while (curr != nullptr) {
		p += curr->last - curr->first;

		if (loc < p) {
			size_t ind = curr->last - (p - loc);
			return &curr->val[ind];
		}

		curr = curr->next;
	}

  return nullptr;
}
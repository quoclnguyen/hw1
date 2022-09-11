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

void ULListStr::push_back(const std::string& val){
  if(head_ ==NULL&& tail_ ==NULL){
    Item *temp = new Item;
    head_ = temp;
    tail_ = temp;
  }
  if ((tail_->last)<ARRSIZE){
    tail_->val[tail_->last] = val; //since tail points to 1 after
    ++(tail_->last);
  }
  else{ //if tail is at end of item, make new item then push to front.
    Item * temp = new Item;
    Item * old_tail = tail_;
    temp->val[temp->first] = val;
    ++(temp->last);
    //old_tail -> next = tail_;
    tail_ = temp; 
    tail_ ->prev = old_tail;
    (tail_->prev)->next = tail_;
  }
  ++size_;
}
void ULListStr::push_front(const std::string& val){
  if(head_ ==NULL&& tail_ ==NULL){
    Item *temp = new Item;
    head_ = temp;
    tail_ = temp;
  }
  if(empty()){
    head_->val[head_->first]=val;
    ++(head_->last);
  }
  else if ((head_ -> first)>0){
    --(head_->first);
    head_->val[head_->first] =val;
  }
  else{
    Item * temp = new Item;
    Item* old_head = head_;
    temp -> first = 9;
    temp ->last = 10;
    temp -> val[9] = val;
    old_head -> prev = head_;
    head_ = temp;
    head_ ->next =old_head;
  }
  ++size_;
}
void ULListStr::pop_back(){
  if ((tail_->last) >0){
    tail_->val[(tail_ ->last)-1] = "";
    --(tail_->last);
  }
  if (tail_ ->last ==0){
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_ ->next = NULL;
  }
  --size_;
}
void ULListStr::pop_front(){
  if ((head_->first)<10){
    head_->val[head_ ->first] = "";
    ++(head_->first);
  }
  if ((head_->first)==10){
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
    head_ ->prev = NULL;
  }
  --size_;
}
std::string const& ULListStr::front() const{
  return head_ ->val[head_->first];
}
std::string const& ULListStr::back() const{
  return tail_ ->val[(tail_->last)-1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* current_item = head_;
  size_t current_index = head_->first;
  size_t current_loc =0;
  
  while(current_loc < loc){
    if (current_item ==NULL){return NULL;}
    if (current_index == (current_item->last)-1){
      current_item = current_item ->next;
      if(current_item ==NULL){return NULL;}
      current_index = current_item ->first;
      ++current_loc;
      continue;
    }
    ++current_index;
    ++current_loc;
  }
  return &(current_item->val[current_index]);
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

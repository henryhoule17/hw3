#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <cmath>
#include <vector>

/*template<typename T>
struct Comp{
    bool operator()(T val1, T val2)
    {
    if(val1 <= val2)
        return false;
    else
        return true;
    }
};*/

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

	void trickleDown(int idx);

	void trickleUp(int idx);

	int pChildIdx(int idx) const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> vals_;
  int m_;

  PComparator c_;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c){}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty())
    throw std::underflow_error("Heap is empty");
  else
    return vals_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
		throw std::underflow_error("Heap is empty");
  else
  {
    vals_[0] = vals_[vals_.size()-1];
    vals_.pop_back();
    if(empty())
      return;
    else
      trickleDown(0);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int idx)
{
	if(idx*m_+1 >= vals_.size())
		return;

  int pindex = idx*m_+1;
	for(int i=2; i<=m_; i++)
	{
    if(idx*m_+i >= size()) break;
		if(c_(vals_[idx*m_+i], vals_[pindex]))
		{
			pindex = idx*m_+i;
		}
	}

  //checks if idx val is worse than priority child
  if(c_(vals_[pindex], vals_[idx]))
  {
    std::swap(vals_[pindex], vals_[idx]);
    trickleDown(pindex);
  }
  else
    return;
}

template <typename T, typename PComparator>
int Heap<T,PComparator>::pChildIdx(int idx) const
{
	int pindex = idx*m_+1;
	for(int i=2; i<=m_; i++)
	{
    if(idx*m_+1 >= size())
      break;
		if(c_(vals_[idx*m_+i], vals_[pindex]))
		{
			pindex = idx*m_+i;
		}
	}

	return pindex;
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
	vals_.push_back(item);

	trickleUp(size()-1);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int idx)
{
	if(idx == 0)
		return;
	else if(c_(vals_[idx], vals_[(idx-1)/m_]))
	{
		std::swap(vals_[idx], vals_[(idx-1)/m_]);
		trickleUp((idx-1)/m_);
	}
	else
		return;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	if(vals_.empty())
		return true;
	else
		return false;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return vals_.size();
}

#endif


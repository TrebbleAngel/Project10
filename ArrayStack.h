/**
 * @brief CS-202 Project 10 ArrayStack.h w/ implementation!
 * @author Angel Lazcano (angelglazcano15@gmail.com)
 * @date December 4, 2018
 * 
 * The purpose of this is file is to provide the declration and implementation 
 *   of a templated Stack class through the use of an Array for navigation and
 *   allocation.
 * We are to use this generalized class to work with the DataType class provided
 *   in the last data structure projects, creating our own test driver to ensure
 *   functionality.
 */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACk_H_

#include <iostream>

//template <typename T> std::ostream & operator<<(std::ostream & os, 											const ArrayStack<T> & arrayStack);

template <typename T> class ArrayStack;
template <typename T> std::ostream & operator<<(std::ostream & os, 
						const ArrayStack<T> & arrayStack);
									
const size_t MAX_STACKSIZE = 1000;

template <typename T>
class ArrayStack{
	
  friend std::ostream & operator<< <> (std::ostream & os, 
								const ArrayStack<T> & arrayStack); 
  public:
  //fashf;lkasj
	ArrayStack();
	
  //fasdkjf;lkasdj
	ArrayStack(size_t count, const T & value);
	
  //safdsa
	ArrayStack(const ArrayStack<T> & other);
	
  //fsafda
	~ArrayStack();
	
  //fasdfa
	ArrayStack & operator= (const ArrayStack<T> & rhs);
	
  //fasddfa
	T & top();
	
  //sdfas
	const T & top() const;
	
  //dafs
	void push(const T & value);
	
 //sadfasd
	void pop();
	
  //sdfasd	
	size_t size() const;
	
  //sdafsdf
	bool empty() const;
	
  //sdafdsa
	bool full() const;
	
  //dasfda
	void clear();
	
  //dsafdsa
	void serialize(std::ostream & os) const;


  private:
	T m_container[MAX_STACKSIZE];
	size_t m_top;
};

#endif //ARRAYSTACK_H_

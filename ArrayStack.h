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
	ArrayStack():m_top(0){;}
	
  //fasdkjf;lkasdj
	ArrayStack(size_t count, const T & value);
	
  //safdsa
	ArrayStack(const ArrayStack<T> & other);
	
  //fsafda
	~ArrayStack();
	
  //fasdfa
	ArrayStack & operator= (const ArrayStack<T> & rhs);
	
  //fasddfa
	T & top(){return m_top;}
	
  //sdfas
	const T & top() const{return m_top;}
	
  //dafs
	void push(const T & value){
		m_top += 1;
		m_container[m_top] = value;
	}
	
 //sadfasd
	void pop(){
		if(!empty){
			delete m_container[m_top];
			m_top -= 1;
		}else{
			;
		}
	}
	
  //sdfasd	
	size_t size() const{
		return m_top;
	}
	
  //sdafsdf
	bool empty() const{
		if(m_top == 0){
			return true;
		}else{
			return false;
		}
	}
	
  //sdafdsa
	bool full() const{
		if(m_top == MAX_STACKSIZE){
			return true;
		}else{
			return false;
		}
	}
	
  //dasfda
	void clear(){
		if(!empty){
			while(!empty){
				pop();
			}
		}else{
			;
		}
	}
	
  //dsafdsa
	void serialize(std::ostream & os) const{
		if(!empty){
			os << '[';
			size_t i = size();
			while(i != 0){
				if((m_top - 1) == 0){
					os << m_container[i] << ']';
				}else{
					os << m_container[i] << ", ";
				}
				i++;
			}
		}
		os << std::endl;
	}
	


  private:
	T m_container[MAX_STACKSIZE];
	size_t m_top;
};

#endif //ARRAYSTACK_H_

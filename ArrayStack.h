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
  //Default Ctor, initializes m_top to 0 							(1)
	ArrayStack():m_top(0){;}
	
  //Parameterized ctor, initializes ArrayStack with providied values		(2)
	ArrayStack(size_t count, const T & value);
	
  //Copy ctor, makes a new ArrayStack with values of other ArrayStack object			(3)
	ArrayStack(const ArrayStack<T> & other);
	
  //Dtor, kills ArrayStack object :(										(4) 
	~ArrayStack();
	
  //Assignment operator, copies one ArrayStack object with rhs ArrayStack
  //																	(5)
	ArrayStack & operator= (const ArrayStack<T> & rhs);
	
  //top function (non-const), returns a usable data value for m_top		(6a) 
	T & top(){return m_top;}
	
  //top function (const), returns a display only data value for m_top 	(6b)
	const T & top() const{return m_top;}
	
  //push function, inserts provided value to Stack						(7) 
	void push(const T & value){
		m_top += 1;
		m_container[m_top] = value;
	}
	
 //pop function, delete top value of Stack								(8) 
	void pop(){
		if(!empty){
			delete m_container[m_top];
			m_top -= 1;
		}else{
			;
		}
	}
	
  //size function, transverses through Nodes to find sizeof Stack		(9)	
	size_t size() const{
		return m_top;
	}
	
  //empty function, checks if Stack is empty							(10)
	bool empty() const{
		if(m_top == 0){
			return true;
		}else{
			return false;
		}
	}
	
  //full function, check if the Stack is full							(11)
	bool full() const{
		if(m_top == MAX_STACKSIZE){
			return true;
		}else{
			return false;
		}
	}
	
  //clear function, clears Stack of values								(12)
	void clear(){
		if(!empty){
			while(!empty){
				pop();
			}
		}else{
			;
		}
	}
	
  //serialize function, initializes a ostream variable for << operator	(13)
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

/** 
 * @brief CS-202 Project 10 NodeStack.h w/ implementaion!
 * @author Angel Lazcano (angelglazcano15@gmail.com)
 * @date December 4, 2018
 * 
 * The purpose of this file is to provide the declration and implemention of a 
 * 	templated Stack class through the use of Nodes for Navigation and allocation.
 * We are to use this generalized class to work with the DataType class provided
 * 	in last data structure projects, creating our own test driver to ensure
 * 	functionality. 
 */
	
#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <iostream>

template <typename T>
class Node{
	 
	friend class NodeStack;
	    
  public: 
	Node(): m_next(NULL){;} 
	Node(const T & data, Node * next = NULL):m_next(next), m_data(data){;}
	T & data(){return m_data;} 
	const T & data() const{return m_data;} 
  private: 
	Node * m_next; 
	T m_data;                                   
}; 

template <typename T, typename P>
class NodeStack{
  template <typename A, typename B>
  friend std::ostream & operator<<(std::ostream & os,   //(i)
                   const NodeStack<A, B> & nodeStack);  
  public:
  //Default Ctor, initializes m_top to NULL 							(1) 
	NodeStack():m_top(NULL){;}
	
  //Parameterized ctor, initializes NodeStack with providied values		(2)  
	NodeStack(size_t count, const T & value){
		size_t i = 0;
		m_top = new Node<P>(value, NULL);
		while(i < (count - 1)){
			push(value);
			i++;
		}
	}
	
  //Copy ctor, makes a new NodeStack with values of provided			(3)            
	NodeStack(const NodeStack & other){
		m_top = new Node<P>(other.m_top->data(), NULL);
		Node<P> * topcpy = m_top;
		Node<P> * othercpy = other.m_top;
		while(othercpy != NULL){
			othercpy = othercpy->m_next;
			topcpy = topcpy->m_next;
			topcpy = new Node(othercpy->data(), NULL);
		}
	}
	
  //Dtor, kills NodeStack object :(										(4)                       
	~NodeStack(){
		clear();
	}                                                 
	
  //Assignment operator, copies one Node Stack object with rhs NodeStack
  //																	(5)
    NodeStack &operator=(const NodeStack & rhs){
		if(*this != &rhs){
			m_top = new Node<P>(rhs.m_top->data(), NULL);
			Node<P> * rhscpy = rhs.m_top;
			while(othercpy != NULL){
				othercpy = othercpy->m_next;
				
			}	
		}else{
			return *this;
		}
	}
    
  //top function (non-const), returns a usable data value for m_top		(6a) 
	T & top(){
		return m_top->data();
	}                                     
	
  //top function (const), returns a display only data value for m_top 	(6b)
	const T & top() const{
		return m_top->data();
	}                           
	
  //push function, inserts provided value to Stack						(7)   
	void push(const T & value){
		Node<P> * newNode = new Node<P>(value, NULL);
		newNode->m_next = m_top;
		m_top = newNode;
	}          
		
  //pop function, delete top value of Stack								(8) 
	void pop(){
		if(!empty()){
			Node<P> * topNode = m_top;
			m_top = m_top->m_next;
			delete topNode;
			topNode = NULL;
		}else{
			std::cout << "This stack is empty" << std::endl; 
		}
	}								 
	
  //size function, transverses through Nodes to find sizeof Stack		(9)
	size_t size() const{
		size_t i = 0;
		if(!empty()){
			Node<T> *size = m_top;
			while(size != NULL){
				i++;
				size = size->m_next;
				}
			} 
			return i;
	}                
	
  //empty function, checks if Stack is empty							(10)
	bool empty() const{
		if(m_top == NULL){
			return true;
		}else{
			return false;
		}
	}
	
  //full function, check if the Stack is full							(11)
    bool full() const{return false;}             
    
  //clear function, clears Stack of values								(12)
	void clear(){
		if(!empty()){
			while(m_top != NULL){
				pop();
				if(empty()){
					std::cout << "This Stack is now empty." << std::endl;
					break;
				}
			}
		}else{
			std::cout << "This Stack is empty!!!" << std::endl;
		}
	}                                            
		
  //serialize function, initializes a ostream variable for << operator	(13)
	void serialize(std::ostream & os) const{
		if(!empty()){
			os << '[';
			while(m_top != NULL){
				if(m_top->m_next == NULL){
					os << m_top->data() << ']';
				}else{
					os << m_top->data() << ", ";
				}
				m_top = m_top->m_next;
			}
		}
	}
	
	                               
	 
  private: 
	T * m_top;
};	


#endif //NODESTACK_H_

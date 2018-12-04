/**
 * @brief CS-202 Project 10 proj10.cpp (Test Driver)
 * @author Angel Lazcano (angelglazcano15@gmail.com)
 * @date December 4, 2018
 * 
 * The purpose of this file is to provide the tests necessary to enure our 
 *   NodeStack & ArrayStack classes function properly.
 * The NodeStack & Array classes are to templated for generalization, and are
 *   designated to work with the DataType class provided in the previous data
 * 	 structure projects.
 * 
 * 	Resources used: Powerpoints from lecture & Labs,
 */

#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

class DataType{

friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
friend std::istream & operator>>(std::istream & is, DataType & dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);
	DataType(const DataType & other);
	
    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);
    
    int getIntVal() const;
    void setIntVal(int i);  
    double getDoubleVal() const;
    void setDoubleVal(double d);

  private:
    int m_intVal;
    double m_doubleVal;
};



int main()
{
  //DEFAULT CTOR															 (1)
	ArrayStack<int> aempty;
	NodeStack<int> nempty;
	
	std::cout << "Test these Default ctors\nArrayStack: " << aempty
			  << "NodeStack: " << nempty << std::endl;
			  
  //PARAMETERIZED CTOR 														 (2)
	//DataType garbage(5, 5.0);
	//DataType alsogarbage(6, 6.0);
	ArrayStack<int> gettingsomewhere(3, 2);
	NodeStack<int> alsogettingsomewhere(5, 2);
	
	std::cout << "Test these Parameterized ctors\nArrayStack: " 
			  << gettingsomewhere << "NodeStack: " << alsogettingsomewhere	
			  << std::endl;
	
  //COPY CTOR 																 (3)
	ArrayStack<int> cat(gettingsomewhere);
	NodeStack<int> kitty(alsogettingsomewhere);
	
	std::cout << "Test these Copy ctors\nArrayStack: " << cat << "NodeStack: "
			  << kitty << std::endl;

  //ASSIGNMENT OPERATOR 													 (5)
	std::cout << "Assignemnt operator: Changing default to copy.\nOld "
			  << "ArrayStack: " << aempty;
	aempty = cat;
	std::cout << "New ArrayStack: " << aempty;
	
	std::cout << "\nOld NodeStack: " << nempty;
	nempty = kitty;
	std::cout << "New NodeStack: " << nempty;

  //TOP FUNCTION															 (6)
	//DataType value(9, 9.0);
	//DataType nodeValue(10, 10.0);
	ArrayStack<int> aTop(3, 9);
	NodeStack<int>  nTop(2, 10);
	
	std::cout << "\nTop value of the stack:\nArrayStack: " << aTop.top()
			  << "\nNodeStack: " << nTop.top() << std::endl;
	
  //PUSH FUNCTION 															 (7)
	//DataType aPush(22,22.0);
	//DataType nPush(23, 23.0);
	aTop.push(9);
	nTop.push(23);
	
	std::cout << "\nTesting push function:\nArrayStack: " << aTop << "NodeStack: "
			  << nTop << std::endl;
			 /* 
  //POP FUNCTION															 (8)
	std::cout << "Testing pop function:\nOld ArrayStack: " << aTop << 
			  << "Old NodeStack: " << nTop
	aTop.pop();
	nTop.pop();
	std::cout << "New ArrayStack: " << aTop << "New NodeStack: " << nTop;
	
  //SIZE FUNCTION															 (9)
	std::cout << "Testing size function:\nArrayStack: " << atop.size() 
			  << "NodeStack: " << nTop.size();
	
  //EMPTY FUNCTION															(10)
	ArrayStack empty;
	NodeStack  notfull;
	
	std::cout << "Testing empty function:\nEmpty ArrayStack: " << std::boolalpha
			  << empty.empty() << "\nRegular Array Stack: " << std::boolalpha
			  << aTop.empty() << std::endl;
			  
  //FULL FUNCTION															(11)
	ArrayStack full(1000, value);
	NodeStack neverfull(1001, value);
	std::cout << "Testing full function:\nFull ArrayStack: " << 
			  << std::boolalpha << full.full() << "\nRegular ArrayStack: " 
			  << std::boolalpha << aTop.full() << "\nNodeStacks have no limit, "
			  << "NodeStack of size 1001: " << std::boolalpha 
			  << neverfull.full() << std::endl;
			  
  //CLEAR FUNCTION															(12)
	std::cout << "Testing the clear function:\nFull ArrayStack, bye bye: ";
	full.clear();
	std::cout << full << "\nNodeStack, bye bye: ";
	neverfull.clear();
	std::cout << neverfull << std::endl;
	
  //DTORS CALLED															 (4)
	std::cout << "And they're gone" << std::endl;
	
	
	*/
	
	
	return 0;
}


DataType::DataType()
 : m_intVal(0),
   m_doubleVal(0)
{
}

DataType::DataType(int intVal, double doubleVal)
 : m_intVal(intVal),
   m_doubleVal(doubleVal)
{
}

DataType::DataType(const DataType & other)
 : m_intVal(other.m_intVal),
   m_doubleVal(other.m_doubleVal)
{
}
	
bool DataType::operator==(const DataType& rhs) const{
  return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}

DataType& DataType::operator=(const DataType& rhs){
  if (this != &rhs){
    m_intVal = rhs.m_intVal;
    m_doubleVal = rhs.m_doubleVal;
  }
  return *this;
}

int DataType::getIntVal() const{
  return m_intVal;
}

void DataType::setIntVal(int i){
  m_intVal = i;
}

double DataType::getDoubleVal() const{
  return m_doubleVal;
}

void DataType::setDoubleVal(double d){
  m_doubleVal = d;
}

std::ostream & operator<<(std::ostream& os, const DataType & dt){
  os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
  return os;
}

std::istream & operator>>(std::istream & is, DataType & dt){
  char in_buf[255];
  is >> in_buf;
  dt.m_doubleVal = atof(in_buf);
  dt.m_intVal = (int)dt.m_doubleVal;
  dt.m_doubleVal -= dt.m_intVal;
  return is;
}


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
 */

#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"
#include "DataType.h"

int main()
{
  //DEFAULT CTOR															 (1)
	ArrayStack thisaempty;
	NodeStack thisnempty;
	
	std::cout << "Test these Default ctors\nArrayStack: " << thisaempty
			  << "NodeStack: " << thisnempty << std::endl;
			  
  //PARAMETERIZED CTOR 														 (2)
	DataType garbage(5, 5.0);
	DataType alsogarbage(6, 6.0);
	ArrayStack gettingsomewhere(3, garbage);
	NodeStack alsogettingsomewhere(5, alsogarbage);
	
	std::cout << "Test these Parameterized ctors\nArrayStack: " 
			  << gettingsomewhere << "NodeStack: " << alsogettingsomewhere	
			  << std::endl;
	
  //COPY CTOR 																 (3)
	ArrayStack cat(gettingsomewhere);
	NodeStack kitty(alsogettingsomewhere)
	
	std::cout << "Test these Copy ctors\nArrayStack: " << cat << "NodeStack: "
			  << kitty << std::endl;
	
  //ASSIGNMENT OPERATOR 													 (5)
	std::cout << "Assignemnt operator: Changing default to copy.\nOld "
			  << "ArrayStack: " << thisaempty;
	thisaempty = cat;
	std::cout << "New ArrayStack: " << thisaempty;
	
	std::cout << "Old NodeStack: " << thisnempty;
	thisnempty = kitty;
	std::cout << "New NodeStack: " << thisnempty;
	
  //TOP FUNCTION															 (6)
	DataType value(9, 9.0);
	DataType nodeValue(10, 10.0);
	ArrayStack aTop(2, value);
	NodeStack  nTop(2, nodeValue);
	
	std::cout << "Top value of the stack:\nArrayStack:" << aTop.top();
			  << "\nNodeStack: " << nTop.top() << std::endl;
	
  //PUSH FUNCTION 															 (7)
	DataType aPush(22,22.0);
	DataType nPush(23, 23.0);
	aTop.push(aPush);
	nTop.push(nPush);
	
	std::cout << "Testing push function:\nArrayStack: " << aTop << "NodeStack: "
			  << nTop << std::endl;
			  
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
	
	
	
	
	
	return 0;
}


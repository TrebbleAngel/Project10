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
  //
	ArrayStack thisaempty;
	NodeStack thisnempty;
	
	std::cout << "Test these Default ctors\nArrayStack: " << thisaempty
			  << "NodeStack: " << thisnempty << std::endl;
  //
	DataType garbage(5, 5.0);
	DataType alsogarbage(6, 6.0);
	ArrayStack gettingsomewhere(3, garbage);
	NodeStack alsogettingsomewhere(5, alsogarbage);
	
	std::cout << "Test these Parameterized ctors\nArrayStack: " 
			  << gettingsomewhere << "NodeStack: " << alsogettingsomewhere	
			  << std::endl;
	
  //		  
	ArrayStack cat(gettingsomewhere);
	NodeStack kitty(alsogettingsomewhere)
	
	std::cout << "Test these Copy ctors\nArrayStack: " << cat << "NodeStack: "
			  << kitty << std::endl;
	
  //		  
	std::cout << "Assignemnt operator: Changing default to copy.\nOld "
			  << "ArrayStack: " << thisaempty;
	thisaempty = cat;
	std::cout << "New ArrayStack: " << thisaempty;
	
	std::cout << "Old NodeStack: " << thisnempty;
	thisnempty = kitty;
	std::cout << "New NodeStack: " << thisnempty;
	
  //
	DataType value(9, 9.0);
	DataType nodeValue(10, 10.0);
	ArrayStack aTop(5, value);
	NodeStack  nTop(4, nodeValue);
	
	std::cout << "Top value of the stack:\nArrayStack:" << aTop.top();
			  << "\nNodeStack: " << nTop.top() << std::endl;
	
	
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <string>
#include "Mylog.h"


int func()
{
	LOG_WARN("����������");
	
	LOG_DEBUG("����Ҳ������");
	return 1;
}

int main()
{
	log4cplus::Initializer initializer;

	func();
	
	std::cout<<"press any key to continue..."<<std::endl;
	getchar();
	
	return 0;
}
#include <iostream>
//#include <stdio.h> // for clear stdout
#include "src.h"

int main(){
	
	// 1
	//////////////////////////////////////////////////
	
	int a, b, c, d;
	a = 3;
	b = 11;
	c = 321;
	d = 51;
	std::cout << a << " " << b << " " << c << " " << d << " " << std::endl;
	float fl = a * (b + ((float)c / d));
	std::cout << fl << " " << std::endl;

	/////////////////////////////////////////////////
	// 2
	/////////////////////////////////////////////////
	
	int n = 24;
	//printf("Text = ");
	//fflush(stdout); // It's work!
	//fseek(stdout, 0, SEEK_END); // It's work!
	n = (n >= 21) ? (2 * (n - 21)) : (21 - n);
	//scanf("%d", &n);
	std::cout << n << std::endl;
	
	/////////////////////////////////////////////////
	// 3
	/////////////////////////////////////////////////
	
	func(a, b, c, d);
	std::cout << a << " " << b << " " << c << " " << d << " " << std::endl;
	fl = a * (b + ((float)c / d));
	std::cout << fl << " " << std::endl;
	
	/////////////////////////////////////////////////
	// 4
	/////////////////////////////////////////////////
	
	int trparr[3][3][3] = {
		{
			{},
			{},
			{}
		},
		{
			{},
			{6,7,2},
			{}
		},
		{
			{},
			{},
			{}
		}
		
	}, *trparrptr;
	// 1 варинант
	//trparrptr = &trparr[1][1][1];
	// 2 вариант
	trparrptr = trparr[0][0];
	trparrptr += 3*3*3/2; // значение центральной ячейки получившегося куба [1][1][1] 
	//
	std::cout << *trparrptr << std::endl;
	
	return 0;
}
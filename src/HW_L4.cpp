#include <iostream>
//#include <math.h>

using namespace std;

int main(){
	
// 1
////////////////////////////////

// /*

	cout << endl << "N1" << endl;
	
	
	int a, b;
	cout << "    Input number a = ";
	cin >> a;
	
	cout << "    Input number b = ";
	cin >> b;
	
	cout << endl;
	
	//cout << a % b << endl;
	//a = 8;
	//b = 3;
	
	a = a + b;
	if ( a >= 10 && a <= 20){
		
		cout << "True" << endl;
		
	} else {
		cout << "False" << endl;
	};
	
	cout << endl << endl;
// */

////////////////////////////////
// 2
////////////////////////////////

// /*
	cout << endl << "N2" << endl;
	
	long long n2;
	cout << "    Input number = ";
	cin >> n2;
	cout << endl;
	//cout << n << endl;
	if(n2 > 0){
		int j2 = 0; // incriment of iteration
		long long i2 = 0;
		bool t; // true - simple, false - natural
		if (n2 > 3){
			
			if( n2 % 2 != 0){
				
				for (i2 = 3; i2*i2 < n2; i2+= 2) {
					
					if (n2 % i2 == 0) {
						t = false;
						break;
					}	 
					j2++;
				}
				
				
				if( i2*i2 > n2 ){
					t = true;
				} else t = false;
				
				
			} else t = false;
			
			
		} else if (n2 > 0){
			t = true;
		}	
		
		cout << "Number of iterations = " << j2 << "; NOD = " << i2 << endl;
		if (t){
			cout << "Simple number" << endl;
		} else{
			cout << "Natural number" << endl;
		}
		
		
	} else{
		cout << "Number < 0" << endl;		
	}
	
	cout << endl << endl;
	
//*/


////////////////////////////////
// 3
// Написать программу, выводящую на экран “истину”, если две целочисленные константы, 
// объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.
////////////////////////////////

//	/*
	cout << endl << "N3" << endl;
	
	if ((a == 10)||(10 == (a / 2))){ // str[20] a = a + b;
		
		cout << "3 true" << endl << endl;
	}
//	*/

////////////////////////////////
// 4
//* Написать программу, которая заполняет диагональные элементы квадратной матрицы единицами. 
// Размеры матрицы нужно задать константными числами, матрицу нужно инициализировать нулями.
////////////////////////////////
	
	cout << endl << "N4" << endl;
	
	const int n4 = 9;
	// int n4;
	// cout << "    Enter  = ";
	// cin >> n4;
	
	int arradr[n4][n4] = {0};
		
	cout << "  ";
	for(int i4 = 0; i4 < n4; i4++){
		
		if ((i4 == j4)||(i4 + j4 == n4-1)){
			
			arradr[i4][j4] = 1;
			cout << "1";
			
		} else{
			arradr[i4][j4] = 0;
			cout << "0";
		}
		
		cout << " ";
		cout << endl << "  ";
			
	}
	
	cout << endl << endl;
	
////////////////////////////////
// 5
// * Написать программу, которая определяет является ли год високосным. 
// Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. 
// Для проверки работы вывести результаты работы программы в консоль
////////////////////////////////

	cout << endl << "N5" << endl;
	
	int n5;
	cout << "    Enter year = ";	
	cin >> n5;
	
	//int nn = (n5 % 100 == 0) ? n5 / 100 : n5;
	
	if (((n5 % 100 == 0) ? n5 / 100 : n5) % 4 == 0){
		cout << " Leap rear " << endl;		
	} else {
		cout << " Not Leap year " << endl;
	}
	
////////////////////////////////
	return 0;
}
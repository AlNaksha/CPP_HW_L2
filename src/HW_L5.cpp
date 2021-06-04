#include <iostream>
#include <stdarg.h>

using namespace std;

////////////////////////////////////////

void printArr(short arr[], int n){
	cout << " l = " << n << endl; 
	for(int i = 0;i < n; i++){
		cout << " " << arr[i];		
	}
	cout << endl;
}

////////////////////////////////////////
namespace funkL5 { // funkL5::

	int N1(short arr1[], int n){
		
		for (int i = 0; i < n; i++){
			
			// #1
			// arr1[i] = (arr1[i] - 1)*(-1);
			
			// #2
			arr1[i] = !arr1[i] ;
			
			// #3
			
			cout << " " << arr1[i];
			
		}
		
		return 0;
	}
	////////////////////////////////////////
	
	void N1_2(int size, ...){
		short * arg_i;
		va_list ap;
		va_start(ap, size);
		for (int j = 0; j < size; j++) {
			arg_i = va_arg(ap, short*);
			printf(" %d ", *arg_i);
			cout << *(arg_i+1) << endl;
		}
		va_end(ap);
	}
	///////////////////////////////////////
	
	int N2(short arr2[], int n){
		//cout << n << endl;
		for (short i = 0; i < n; i++){
			
			arr2[i] = 1 + 3 * i;
			cout << " " << arr2[i];
			
		}
		
		return 0;
	}
	////////////////////////////////////////
	
	bool N3(short arr3[], int l){
		bool flg;
		
		if (l>2){
				
			int i = 0, j = l-1;
			short n = arr3[i], m = arr3[j];	
			
			while(i + 1 < j){
				if (n>m){
					j--;
					m+=arr3[j];
					
				} else {
					i++; 
					n+=arr3[i];
					
				}
			}
			if (n == m) {
				return true;
			} else return false;
			
		} else if(l == 2){
			if (arr3[0] == arr3[1]) {
				return true;
			} else return false;
			
		} else{
			cout << "insufficient data" << endl;
			return false;
		}
		
		return 0;
	}
	////////////////////////////////////////
	
	int N4(short arr4[], int l, int n){
			
		if (!n) return 0;
		
		printArr(arr4, l);
		
		while (n * n > l * l){
			
			if(n > 0){
				n = n - l;
			} else{
				n = l + n;
			}
		}
		short arr4_2[l] = {0};
		
		for (int i = 0; i < l; i++){
			int n_i = i+n;
			if ((n_i >= 0)&&(n_i < l)){
				
				arr4_2[i] = arr4[n_i];
				
			} else {
				
				arr4_2[i] = (n > 0) ? arr4[n_i-l]: arr4[n_i+l];
			}
			printf("  %d  %d  %d  %d  \n", i, arr4[i], n_i, arr4_2[i]);
			
		}
		
		for (int i = 0; i < l;i++){
			arr4[i] = arr4_2[i];
		}
		
		return 0;
	}

}

////////////////////////////////////////
int main(){
	
////////////////////////////////////////
// #1
// Задать целочисленный массив, состоящий из элементов 0 и 1. 
// Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
// Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0 
// (** без применения if-else, switch, () ? :);
////////////////////////////////////////
	cout << endl << "#1" << endl;
	
	short arr1[10] = {0,0,0,1,0,1,0,0,1,1};
	int l1 = sizeof(arr1)/sizeof(short);
	// funkL5::N1(arr1, l1);
	funkL5::N1_2(l1, arr1);

////////////////////////////////////////
// #2
// Задать пустой целочисленный массив размером 8. 
// Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
////////////////////////////////////////
	cout << endl << "#2" << endl;
	
	short arr2[8];
	//cout << sizeof(arr2) << endl;
	int l2 = sizeof(arr1)/sizeof(short);
	funkL5::N2(arr2, l2);
	

////////////////////////////////////////
// #3
// * Написать функцию, в которую передается не пустой одномерный целочисленный массив, 
// функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой 
// части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) -> true, 
// checkBalance ([2, 1, 1, 2, 1]) -> false, checkBalance ([10, || 1, 2, 3, 4]) -> true. 
// Абстрактная граница показана символами ||, эти символы в массив не входят.
////////////////////////////////////////
	cout << endl << "#3" << endl;
	
	short arr3[] = {4,2,10,5,3,1,1,2,3,9,1,21};
	int l3 = sizeof(arr3)/sizeof(short);
	
	if (funkL5::N3(arr3, l3)){
		cout << endl << "true" << endl;
	}else{
		cout << endl << "false" << endl;
	}
	printArr(arr3, l3);

////////////////////////////////////////
// #4
// * Написать функцию, которой на вход подаётся одномерный массив 
// и число n (может быть положительным, или отрицательным), при этом функция должна циклически 
// сместить все элементы массива на n позиций. 
////////////////////////////////////////
	cout << endl << "#4" << endl;
	//cout << "    Enter offset = ";
	int n = 2;
	//cin >> n;
	
	funkL5::N4(arr3, l3, n);
	printArr(arr3, l3);
	
	
////////////////////////////////////////
// #5
// ** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
////////////////////////////////////////

	// char t;
	// t = -20;
	// unsigned char t2;
	// t2=(unsigned char) t;
    // printf("The character '%c' has code ыопыко %d (%hhu).\n",t,t,(unsigned)t2);

////////////////////////////////////////
// #6
//** Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на исполнение в основном файле программы используя указатели на функции.
////////////////////////////////////////
	return 0;
	
}
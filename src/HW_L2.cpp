#include <iostream>

int main(){
	
	char ch = 68;
	short sh = 50;
	int i = 1000;
	long l = 5000;
	float fl = 0.25;
	double db = 205.00142;
	bool b = true;
	struct exhero{
		char name[15];
		int dmg;
		int shield;
	};
	std::cout << (int) ch << " = " << ch << " " << sh << " " << i << " " << l << std::endl;
	std::cout << fl << " " << db << std::endl;
	
	enum TiTaTo {E,O,X};
	enum TiTaTo exem[3] = {X,E,O};
	struct tableT {
		enum TiTaTo Tstate;
		signed char hor;
		signed char ver;
		signed char dia;
	};
	//char n; //Размерность поля
	//printf("Input field size = ");
	//scanf("%i", n);
	//tableT field[n][n] = {};
	
	
}
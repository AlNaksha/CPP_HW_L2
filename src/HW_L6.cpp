#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

//////////////////////////////////////////////// ¯®¤áç¥â á¨¬¢®«®¢ ¢ ¬ áá¨¢¥ á¨¬¢®«®¢
int lenofcharr(const char * content){
	int i = 0;
	while (content[i] != '\0') i++;
	return i;
}

//////////////////////////////////////////////// ¢ë¢®¤ á®®¡é¥­¨©
void prntmsg(int nmsg){
	
	switch(nmsg){
		
		case 0:{
			printf(" None instructions ");
			break;
		}
		
		case 2:{
			printf(" Done ");
			break;
		}
		
		case 3:{
			printf(" Yes ");
			break;
		}
		
		case 111:{
			printf(" Error open file for write ");
			break;
		}
		
		case 222:{
			printf(" Error open file for read ");
			break;
		}
		
		case 333:{
			printf(" No ");
			break;
		}
		
		case 404:{
			printf(" Not faund ");
			break;
		}
		
		case 3333:{
			printf(" Wrong input ");
			break;
		}
		
		default: printf(" Undefined instructions ");
	}
	
}

void prntmsg(int nmsg, const char str1[], const char str2[]){
	
	switch(nmsg){
		case 1:{
			printf("In file <%s> wrote %d simbols\n\n", str1, lenofcharr(str2));
			break;
		}
		
		
	}	
}

//////////////////////////////////////////////// ‡ ¯¨áì ¢ ä ©«
bool outfile(const char namefile[], const char * content){
	
	ofstream outf(namefile);
	if (outf.is_open()) {
		outf << content;
		outf.close();
		return true;
	} else return false;
	
	//printf("In file <%s> wrote %d simbols\n\n", namefile, lenofcharr(content));
	//cout << content << endl << endl;
	//return true;
}

//////////////////////////////////////////////// —â¥­¨¥ ä ©« 
char* infile(const char nf[], int *l){
	
	ifstream ifs1(nf, ofstream::ate);
	
	char * cstr;
	if (ifs1.is_open()){
		
		*l = ifs1.tellg();
		ifs1.seekg(ios::beg);
		
		cstr = (char*) calloc( *l, sizeof(char));
		
		int i = 0;
		while(i < *l){
			cstr[i]=ifs1.get();
			//cout << cstr[i];
			i++;
			//printf("%c", cstr[i]);
		}
		
		ifs1.close();
		//cout << endl << cstr << endl;
	} else {
		prntmsg(404);
	}
	return cstr;
}

//////////////////////////////////////////////// ‘«¨ï­¨¥ ä ©«®¢
bool conkat(const char nf1[], const char nf2[], const char nf3[]){
	
	int lf1 = 0;
	int lf2 = 0;
	// string str1;
	// string str2;
	char * cstr1;
	char * cstr2;
	
	cstr1 = infile( nf1, &lf1);
	
	/*
	// ifstream ifs1(nf1, ofstream::ate);
	
	// if (ifs1.is_open()){
		
		// lf1 = 110;
		// // lf1 = ifs1.tellg();
		// // //printf("\n%d\n", lf1);
		// // ifs1.seekg(ios::beg);
		
		// cstr1 = (char*) calloc( lf1, sizeof(char));
		// int i = 0;
		// while(!ifs1.eof()){
			// cstr1[i]=ifs1.get();
			// i++;
		// }
		
		// ifs1.close();
		
	// } else return false;
	
	cout << cstr1 << endl;
	//cout << lf1 << endl;
	*/
	
	cstr2 = infile( nf2, &lf2);
	
	/*
	ifstream ifs2(nf2, ofstream::ate);
		
	if (ifs2.is_open()){
		
		lf2 = ifs2.tellg();
		//printf("\n%d\n", lf2);
		ifs2.seekg(ios::beg);
		
		cstr2 = (char*) calloc( lf2, sizeof(char));
		int i = 0;
		while(!ifs2.eof()){
			cstr2[i]=ifs2.get();
			i++;
		}
		
		ifs2.close();
		
	} else return false;
	
	*/
	//cout << cstr2 << endl;
	
	int n = lf1+lf2;
	//cout << lf1 << " " << lf2 << " " << n << endl;
	
	char * cstr3 = (char*) calloc( n+1, sizeof(char));
	
	//cout << lenofcharr(cstr3) << endl;
	//cout << cstr3 << endl;
	
	int i = 0;
	while( i < n){
		if (i < lf1){
			cstr3[i] = cstr1[i];
		} else{
			cstr3[i] = cstr2[i-lf1];
		}
		//printf( "%d %c %d\n", i, cstr3[i], cstr3[i]);
		i++;
	}
	
	//cout << cstr3 << endl;
	
	if (outfile( nf3, cstr3)) prntmsg(1,nf3, cstr3);
	else prntmsg(111);
	
	return true;
}

//////////////////////////////////////////////// áà ¢­¥­¨¥ ¬ áá¨¢®¢ á¨¬¢®«®¢
bool strcon(const char str1[], const char str2[]) { return strcmp(str1, str2) == 0;}

bool findword( const char fn[], const char word[]){
	
	int l = 0;
	char * str = infile( fn, &l);
	
	int l1 = 0, l2 = l-1;
	
	int n = lenofcharr(word);
	int n1 = 0, n2 = n-1;
	//printf(" %d %d\n %d %d\n", n1, n2, l1, l2);
	int i = 0;
	while (l1 <= l2 + n){
		
		if ( str[l1] == word[n1]) n1++;
		else {
			n1 = 0;
			if ( str[l1] == word[n1]) n1++;
		}
		if ( str[l2] == word[n2]) n2--;
		else {
			n2 = n-1;
			if ( str[l2] == word[n2]) n2--;
		}
		if ((n1 == n) || (n2 == 0)) { 
			//printf(" %d\n", i); 
			//printf(" %d %d\n %d %d\n", n1, n2, l1, l2);  
			return true;
		}
		l1++;
		l2--;
		i++;
		
	}
	//printf(" %d\n", i);
	//printf(" %d %d\n %d %d\n", n1, n2, l1, l2);
	return false;
}

////////////////////////////////////////////////
int main(int args, const char** argv){
	
	// ®¡à ¡®âª  ¢¢®¤­ëå ¤«ï ¯à®£à ¬¬ë
	int stage = 0;
	if (args>=2){
		if (strcon(argv[1], "-c")) {stage = 1; }
		else if (strcon(argv[1], "-m")) {stage = 2; }
		else if (strcon(argv[1], "-f")) { 
			if (args == 4) stage = 3;
			else {
				prntmsg(3333);
				return 0;
			}
			//cout << "_" << argv[2] << "_" << argv[3] << "_" << endl;
		}
		else stage = 404;
		// if (argv[1][0]=='-') {		
			// cout << argv[1] << endl;
			// cout << stage << endl;
			// if (argv[1][1]=='c') stage = 1;
			// if (argv[1][1]=='m') stage = 2;
			// if (argv[1][1]=='f') stage = 3;
		// }
	}
	// cout << " Number of arguments = " << args << endl;
	// printf("State = %d\n", stage);
	
	const char nf1[] = "F1.txt";
	const char nf2[] = "F2.txt";
	const char nf3[] = "F3.txt";
		
	// int * n = new int[2]{4,6};
	// cout << &n << " " << n << " " << n[0] << " " << &n[1] << " " <<n[1] << endl;
	// delete n;
	// int * k = new int;
	// cout << &k << " " << k << " " << *k <<  endl;
	
	switch(stage){
		
		case 0 :{
			prntmsg(0);
			break;			
		}
		
		
		////////////////////////////////////////////////
		//  ¯¨á âì ¯à®£à ¬¬ã, ª®â®à ï á®§¤ áâ ¤¢  â¥ªáâ®¢ëå ä ©« , 
		// ¯à¨¬¥à­® ¯® 50-100 á¨¬¢®«®¢ ¢ ª ¦¤®¬ (®á®¡®£® §­ ç¥­¨ï ­¥ ¨¬¥¥â);
		////////////////////////////////////////////////
		case 1 :{
			/*
				word used by programmers when... they do not want to explain what they did

				programmer is a person who fixed a problem 
				that you don't know you have, 
				in a way you don't understand 

				programmer is a machine that turns coffee into code
			*/
			
			const char txt1[] = "rehthsthjyjfhyjsyjsfrjsfjysjrjsfjsyhmksdm,dgjh,dgj,dgj,dsfhmxhmfdh";
			// const char txt1[] = " - Can you please recommend books that made you cry?\
			// - Data Structures and Algorithms in Java(2nd Edition).";
			 
			const char txt2[] = "sgjsrjnsfdgjsrhmdfhmdhmdhgmdhmdghxhmxhm,xvnxvxvh,gjcxchj,xhfmxfhmm,dgj";
			// const char txt2[] = " The best apps I have developed:\
			// 1. Hello World;\
			// 2. Test App;\
			// 3. Untitled Project.";
			
			// printf("In file wrote %d simbols\n", sizeof(txt1));
			// cout << lenofcharr(txt1) << endl << endl;
			
			if (outfile( nf1, txt1)) prntmsg(1,nf1, txt1);
			else prntmsg(111);
			
			//printf("%d", sizeof(txt1));
			
			// ofstream outf1("F1.txt");
			// outf1 << txt1;
			// outf1.close();
			
			if (outfile( nf2, txt2)) prntmsg(1,nf2, txt2);
			else prntmsg(111);
			
			// ofstream outf2("F2.txt");
			// outf2 << txt2;
			// outf2.close();
			break;
		}
		
		
		////////////////////////////////////////////////
		//  ¯¨á âì äã­ªæ¨î, <áª«¥¨¢ îéãî> íâ¨ ä ©«ë, 
		// ¯à¥¤¢ à¨â¥«ì­® ¡ãä¥à¨§ãï ¨å á®¤¥à¦¨¬®¥ ¢ ¤¨­ ¬¨ç¥áª¨ ¢ë¤¥«¥­­ë© á¥£¬¥­â ¯ ¬ïâ¨ ­ã¦­®£® à §¬¥à .
		////////////////////////////////////////////////
		case 2 :{
			
			if (conkat( nf1, nf2, nf3)) {
				prntmsg(2);
			} else prntmsg(222);
			break;
		}	
		
		
		////////////////////////////////////////////////
		// *  ¯¨á âì ¯à®£à ¬¬ã, ª®â®à ï ¯à®¢¥àï¥â ¯à¨áãâáâ¢ã¥â «¨ ãª § ­­®¥ ¯®«ì§®¢ â¥«¥¬ ¯à¨ § ¯ãáª¥ 
		// ¯à®£à ¬¬ë á«®¢® ¢ ãª § ­­®¬ ¯®«ì§®¢ â¥«¥¬ ä ©«¥ (¤«ï ¯à®áâ®âë à ¡®â ¥¬ â®«ìª® á « â¨­¨æ¥©).
		////////////////////////////////////////////////
		case 3 :{
			
			// file3.txt {afha fgbazeh ae ahdt h dhzsdtgjnsr gbwshbr eatnedtgndnb gtnrehellotnsgn gcjc} yes
			// file3.txt {afha fgbazeh ae ahdt h dhzsdtgjnsr gbwshbr eatnedtgndnb gtnrehel lotnsgn gcjc} no
			if (findword( argv[2], argv[3])) {
				prntmsg(3);
			} else prntmsg(333);
			
			break;
		}	
		default: prntmsg(404);
	}
	
	return 0;
}

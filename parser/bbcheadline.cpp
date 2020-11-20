//#include <chrono.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string line;
	ifstream myfile("example.txt");
	if (myfile.is_open()){
		while(!feof(myfile)){
		getline(myfile,line);
		}
	myfile.close();
	}




return 0;
}

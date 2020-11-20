#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string line;
	ifstream myfile("example.txt");
	if (myfile.is_open()){
		//while(getline(myfile,line)){
		while(!myfile.eof()){
			getline(myfile,line);
			size_t count =line.find("title");
			//getline(myfile,line);	
			if(count<10){
			cout<<line<<endl;
		}

			else {// cout << "empty";
			}		
		//	count=0;
		}
	myfile.close();
	}




return 0;
}

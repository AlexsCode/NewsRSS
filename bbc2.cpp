#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string line;
	int linecount= 0;
	size_t count;
	double    index = 0 ;
	int linesize;
	int remainingsize = 0;
	ifstream myfile("example.txt");
	if (myfile.is_open()){
		//while(getline(myfile,line)){
		while(!myfile.eof()){
		
			count =line.find("title");
			getline(myfile,line);
			++linecount;	
			if(count<15){
				//cout<<count<<endl;
				if(line.size()>60){
				cout<<line<<endl;
				line.erase(0,34);
				index =( line.find(']')-1);
				linesize = line.size();
				remainingsize = (linesize - index);
				cout<<index<<endl;
				line.erase(index,remainingsize);		
				cout<<line<<endl;
				}
			}

			else {// cout << "empty";
			}		
		//	count=0;
		}
		cout<<linecount<<endl;
	myfile.close();
	}




return 0;
}

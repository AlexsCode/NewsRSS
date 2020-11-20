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
	ofstream writefile("output.txt");
//	writefile.open("output.txt",ios::out,ios::binary);

	if (writefile.is_open()){
	if (myfile.is_open()){
		//while(getline(myfile,line)){
		while(!myfile.eof()){
		
			getline(myfile,line);
			count =line.find("<title><![CDATA[");
		//	cout<<count<<endl;
		//	cout<<line<<endl;
			++linecount;
			if(count<100){
			//	cout<<count<<endl;
				if(line.size()>60){
		//			cout<<line<<endl;
					line.erase(0,28);
					index =( line.find(']'));
					linesize = line.size();
					remainingsize = (linesize - index);
		//			cout<<index<<endl;
					line.erase(index,remainingsize);		
					cout<<line<<endl;
					writefile<<line<<endl;
					count = 0;
				}
			}

	//		else {// cout << "empty";
	//		}		
		//	count=0;
		}
//		cout<<linecount<<endl;
	myfile.close();
	writefile.close();
	}


	}

return 0;
}

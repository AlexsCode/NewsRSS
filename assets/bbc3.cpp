#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string line; //main string for single line
	double index = 0 ; //index count for lines
	size_t count; //size gives the number found
	int linesize; //
	int remainingsize = 0;
	int linecount= 0;
	
	
	ifstream myfile("example.txt"); //sets input stream from file
	ofstream writefile("output.txt"); //sets output stream to file

	if (writefile.is_open()){ //makes sure output file is open, opens if not
	if (myfile.is_open()){ //makes sure input file is open, opens if not
		while(!myfile.eof()){ // loops through file until hits end of file		
			getline(myfile,line); //getline pulls a line from the input file and saves it into string_line
			count =line.find("<title><![CDATA["); // counts the occurances of title header start within string line.
			++linecount; // will move this index on for each iteration of the while loop
			if(count<100){ //requires count less than 100, means as long as the whole RSS isnt a single line should activate
				if(line.size()>60){ //loop enters for the full title, removes false positives from .rss webpage on build
					line.erase(0,28);//this removes the tittle header information and whitespace padding on titles
					index =( line.find(']'));//searches for the end of the title from the line
					linesize = line.size(); //sets the full remaining line length as size
					remainingsize = (linesize - index); //calculates the charactercount after title ends within string line
					line.erase(index,remainingsize); //removes excess characters after title		
					cout<<line<<endl; //this should print on screen the headline nicely formatted
					writefile<<line<<endl; // this writes the formatted line - headline to the output file
					count = 0; //resets the counter for the line found.
				}
			}

		}
	myfile.close(); //close the input file
	writefile.close(); //close the output file - all lines have been read and parsed at this point
	}


	}

return 0;
}

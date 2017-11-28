#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int count=0;
int main(int argc, char** argv)
{
	char* filename = argv[1];
	cout << "filename:" << filename << endl;
	
	ifstream input(filename);
	
	string line;
	getline(input,line);
	
	while (!input.eof())
	{

		cout << "line:" << line << endl;
		int pos = line.find(' ');
				string number = line.substr(pos,2);
		cout << "number:" << number << endl;
		count += stoi(number);
		
		getline(input,line);
		};
	cout << "numero de muestras:" << count << endl;
	};

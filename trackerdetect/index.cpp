#include<map>
#include "index.h"
using namespace std;

Index::Index()
{
	count=0;
	};
	
void Index::put(int iExt)
{
	count++;
	index.insert(pair<int,int>(iExt,count));
	
	};
bool Index::get(int iExt, int &iInt)
{
	map<int,int>::iterator it= index.find(iExt);
	if (it!=index.end())
	{
		iInt = it->second;
		return true;
		} else return false;
};

int Index::size()
{
	return count;
	};

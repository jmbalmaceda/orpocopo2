#include<map>
using namespace std;
class Index
{
	public:
		Index();
		void put(int iExt);
		bool get(int iInt, int &iExt);
		int size();
	private:
	map<int,int> index;
	int count;
	};

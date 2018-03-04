#include <iostream>
#include <string>

using namespace std;

class CountObj {
	static int nObj;
public:
	CountObj() {
		++nObj;
		print("from Constructor:");
	}
	CountObj(CountObj& obj) {
		++nObj;
		print("from Copy-Constructor:");
	}
	static void print(const string& msg = "") {
		if (!msg.empty())
			cout << "\n msg = "<<msg << " ";
		cout << "Number of Object = " << nObj << endl;
	}
	~CountObj() {
		--nObj;
		print("from Destructor:");
	}
};

int CountObj::nObj = 0;

CountObj fun(CountObj obj) {	
	return obj;
}
void numOfObj() {
	CountObj obj1, obj2;
	obj1 = fun(obj2);
}

int main() {
	numOfObj();
	cout << "\n\n";
	system("pause");
	return 0;
}
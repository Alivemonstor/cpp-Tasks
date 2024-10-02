#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string left = R"(
		+=-=
		|
		+=-=
)";
	string right = R"(
		 -=+
		   |
		 -=+
)";

	cout << left << right;
	return 0;

}
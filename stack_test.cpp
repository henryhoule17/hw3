#include <iostream>
#include <vector>
#include "stack.h"

using namespace std;

int main(int argc, char* argv[])
{
	Stack<int> s;
	s.push(23);
	s.push(0);
	s.push(11);
	cout << s[s.size()-1] << endl;

	s.pop();
	s.pop();

	cout << s[s.size()-1] << endl;

	cout << s.top() << endl;

	return 1;
}
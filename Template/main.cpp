#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

/*
Inputs:
-Number of test cases
-

Outputs:
"Case #x: y"
where x is the test case and y "NOT POSSIBLE" if not a valid combination, or the number of switches to flip.
*/

#define ul unsigned long long
#define ui unsigned int
#define sl signed long long
#define si signed int

using namespace std;

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		string testCaseY;

		testCaseYs.push_back(testCaseY);
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}

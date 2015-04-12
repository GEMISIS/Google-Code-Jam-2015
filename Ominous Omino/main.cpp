#include <iostream>
#include <string>
#include <vector>

/*
Inputs:
-Number of test cases
-The maximum possible shyness
-A number with each digit containing the number of kth shy people, where k is the index of a digit.

Outputs:
"Case #x: y"
where x is the test case and y is the minimum number of friends you must invite.
*/

using namespace std;

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> winners;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		string winner = "X";
		winners.push_back(winner);
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << winners[tc] << endl;
	}
}


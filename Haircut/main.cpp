#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

/*
Inputs:
-Number of test cases
-The number of barbers
-Your place in line

Outputs:
"Case #x: y"
where x is the test case and y is the barber who will cut your hair.
*/

using namespace std;

long solve(long pos, vector<long> barbers)
{
	long low = -1, high = 10000 * pos;
	long haircutsGiven = 0;
	long mid = (low + high) / 2;

	while (low + 1 < high)
	{
		mid = (low + high) / 2;

		haircutsGiven = 0;
		for (long i = 0; i < barbers.size(); i += 1)
		{
			haircutsGiven += mid / barbers[i] + 1;
		}

		if (haircutsGiven < pos)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	long t = high;
	haircutsGiven = 0;
	for (long i = 0; i < barbers.size(); i += 1)
	{
		haircutsGiven += t / barbers[i];
	}
	long customersLeft = pos - haircutsGiven;

	for (long i = 0; i < barbers.size(); i += 1)
	{
		if (mid % barbers[i] == 0)
		{
			customersLeft -= 1;
			if (customersLeft == 0)
			{
				return i;
			}
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (int tc = 0; tc < testCases; tc += 1)
	{
		long barbers, mp;
		vector<long> barbersm;

		cin >> barbers;
		cin >> mp;

		for (long i = 0; i < barbers; i += 1)
		{
			long temp;
			cin >> temp;
			barbersm.push_back(temp);
		}

		testCaseYs.push_back(to_string(solve(mp, barbersm)));
	}

	for (int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}

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

unsigned long long solve(unsigned long long pos, vector<unsigned long long> barbers)
{
	unsigned long long maxTime = 1000000000;
	for (unsigned long long i = 0; i < barbers.size(); i += 1)
	{
	}

	unsigned long long barber = 0;
	pos -= barbers.size();
	vector<unsigned long long> bt;
	unsigned long long barberMin = 100000;

	for (unsigned long long i = 0; i < barbers.size(); i += 1)
	{
		bt.push_back(1);
		barberMin = min(barberMin, barbers[i]);
	}
	while (pos + 1 > 1)
	{
		for (unsigned long long i = 0; i < barbers.size() && pos + 1 > 1; i += 1)
		{
			if (barbers[i] <= bt[i])
			{
				barber = i;
				pos -= 1;
				bt[i] = 1;
			}
			else
			{
				bt[i] += barberMin;
			}
		}
	}

	return barber + 1;
}

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		unsigned long long barbers, mp;
		vector<unsigned long long> barbersm;

		cin >> barbers;
		cin >> mp;

		for (unsigned long long i = 0; i < barbers; i += 1)
		{
			unsigned long long temp;
			cin >> temp;
			barbersm.push_back(temp);
		}

		testCaseYs.push_back(to_string(solve(mp, barbersm)));
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}

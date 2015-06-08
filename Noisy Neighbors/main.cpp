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

string solve(ul w, ul h, ul n)
{
	ul out = 0;
	ul roomsLeft = 0;
	ul maxRooms = w * h;

	n -= maxRooms / 2;

	if (n - 1 == 0 && maxRooms % 2 == 1)
	{
		return "0";
	}
	else
	{
		ul p = 2;
		while (n > 0)
		{
			if (maxRooms % 2 == 1)
			{
				out += 4 * p;
			}
			else
			{
				out += 2 * p;
			}
			maxRooms -= w * 2;
			maxRooms -= (h - 2) * 2;
			p += 1;
		}
	}

	ul start = 0;
	while (maxRooms > 0 && n > 0)
	{
		if (start == 0)
		{
			for (ul i = 0; i < 2 && maxRooms > 0 && n > 0; i += 1)
			{
				n -= 1;
				maxRooms -= 1;
				out += 2;
			}
		}
		else
		{
		}
		start += 1;
	}

	return to_string(out);
}

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		string testCaseY;
		ul w, h, n;

		cin >> h >> w >> n;

		testCaseYs.push_back(solve(w, h, n));
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}

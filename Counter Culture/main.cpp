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

string reverse(const char* str1)
{
	char* str = (char*)str1;
	reverse(str, str + strlen(str));
	return str;
}

string solve(ul n)
{
	ul count = 1;
	ul temp = n;
	while (temp > 1)
	{
		string str = to_string(temp);
		ul lowest = str[str.length() - 1] - '0';
		if (lowest > 1)
		{
			string revn = str.substr(0, str.length() - 1) + "1";
			ul norm = stoull(revn);
			ul rev = stoull(reverse(revn.c_str()));
			if (rev < norm)
			{
				temp = rev;
				count += lowest - 1;
			}
			else
			{
				temp -= lowest - 1;
				count += lowest - 1;
			}
		}
		else
		{
			temp -= 1;
			count += 1;
		}
	}

	return to_string(count);
}

int main(int argc, char* argv[])
{
	unsigned int testCases = 0;
	cin >> testCases;

	vector<string> testCaseYs;

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		string testCaseY;
		ul n;
		cin >> n;

		testCaseYs.push_back(solve(n));
	}

	for (unsigned int tc = 0; tc < testCases; tc += 1)
	{
		cout << "Case #" << tc + 1 << ": " << testCaseYs[tc] << endl;
	}
}

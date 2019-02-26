#include <iostream>
#include <regex>
#include <map>
#include <fstream>
#include <string>
using namespace std;
map<int, string> monthNames = {
{1, "january"},
{2, "february"},
{3, "march"},
{4, "april"},
{5, "may"},
{6, "june"},
{7, "jule"},
{8, "august"},
{9, "september"},
{10, "octember"},
{11, "november"},
{12, "december"} };
bool isLeap(int year)
{
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}
bool isValidDate(int d, int m, int y)
{
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	if (m == 2)
	{
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
	if (m == 4 || m == 6 ||
		m == 9 || m == 11)
		return (d <= 30);
	return true;
}
int main()
{
	regex re("(\\d{1,2})\\.(\\d{2})\\.(\\d{4})y");
	std::ifstream file("source.txt");
	std::string str;
	while (std::getline(file, str))
	{
		sregex_iterator next(str.begin(), str.end(), re);
		sregex_iterator end;
		while (next != end)
		{
			smatch match = *next;
			if (isValidDate(stoi(match.str(1)), stoi(match.str(2)), stoi(match.str(3)))) {
				cout << match.str() << " => "
					<< match.str(1) << " "
					<< monthNames[stoi(match.str(2))] << " "
					<< match.str(3) << " year\n";
			}
			next++;
		}
	}
	getchar();
	return 0;
}
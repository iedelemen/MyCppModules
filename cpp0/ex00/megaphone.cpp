#include <iostream>

using std::cout;

int main(int arc, char **arv)
{
	if (arc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < arc; i++)
		{
			for(int j = 0; arv[i][j]; j++)
				cout << (char)std::toupper(arv[i][j]);
		}
	return cout << std::endl, 0;

}

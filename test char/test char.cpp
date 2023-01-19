#include <iostream>
#include <string.h>
using namespace std;
int shortest(char* s);
int main()
{
	char s[] = "ghuyhhygag";
	cout << shortest(s);

}
int shortest(char* s)
{
	int num = 0;
	int counter = 0;
	int temp;
	for (int i = 0; i < strlen(s); i++)
	{
		for (int j = i; j < strlen(s); j++)
		{
			if (s[i] == s[j] && i != j)
			{
				num++;
			}
		}
	}
	int* A = new int[num];
	if (!A)
	{
		cout << "out of memory";
		return 0;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		for (int j = i; j < strlen(s); j++)
		{
			if (s[i] == s[j] && i != j)
			{
				A[counter] = j - i-1;
				counter++;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			if (A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	temp = A[0];
	delete[] A;
	return temp;
}

#include <iostream>

using namespace std;

const char* g_begin = "BEGIN";
const char* g_end = "END";
const int g_strMaxLength = 100;

int myStrstr(char* source, const char* target)
{
	for (int i = 0; source[i] != 0; i++)
	{
		for (int j = 0; source[i + j] == target[j]; j++)
		{
			if (j + 1 == strlen(target)) return i;
		}
	}
	return -1;
}
int targetSum(char* str)
{
	if ((myStrstr(str, g_end) < myStrstr(str, g_begin)) ||
		myStrstr(str, g_end) == -1 ||
		myStrstr(str, g_begin) == -1)
	{
		return -1;
	}
	int result = 0;
	for (int i = myStrstr(str, g_begin) + strlen(g_begin); i < myStrstr(str, g_end); i++)
	{
		if (str[i] > '0' && str[i] <= '9')
		{
			result += str[i] - '0';
		}
	}
	return result;
}
int main()
{
	FILE* fptr = 0; 
	fopen_s(&fptr, "testfile.txt", "r");
	if (fptr == NULL)
	{
		cout << "error, didn't open the file";
		return -1;
	}
	char filestr[g_strMaxLength]{};
	fread(filestr, sizeof(char), g_strMaxLength, fptr);
	cout << targetSum(filestr);

	fclose(fptr);
	return 0;
}
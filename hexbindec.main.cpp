#include <iostream>
using namespace std;

// кто, я? аможет быть ты?
int INDEX_IN(char* str) 
{
	if ((str[1] == 'b' || str[1] == 'B') && str[0] == '0') return 2;
	else if ((str[1] == 'x' || str[1] == 'X') && str[0] == '0') return 16;
	else if (str[1] >= '0' && str[1] <= '9' && str[0] != '0') return 10;
	else return -1;
}
int mystrlen(char* str,int index)
{
	const int size = 100;
	int i = 0, length = 0;	
	for (; i < 100; i++)
	{
		if (str[i] != 0) 
		{
			length++;				
		}
		else { break; }
	}
	return length;
}
void inStr(char* str, int size)
{
	cout << "Vvesti chislo " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> str[i];
	}
}
int strToInt(const char* str,const int size,int index)
{	
	int i = 0;
	if (index == 2 || index == 16) i = 2;	
	int num = 0;
	while (i < size)
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return num;
}
void DEC_TO_(int num, const int index)
{
	char res[32] = "0";
	const char* digits = "0123456789ABCDEF";
	int i = 0;
	if (index == 2 || index == 16) i = 2;
	while (num)
	{
		res[i++] = digits[num % index];
		num /= index;
	}
	if (index == 2) cout << "0b";
	if (index == 16) cout << "0x";
	while (--i)
	{
		cout << res[i];
	}
	cout << endl;
}
int chartoint(const char chr)
{
	if (chr >= '0' && chr <= '9') return (chr - '0');
	else if (chr >= 'a' && chr <= 'f') return (chr - 'a' + 10);
	else if (chr >= 'A' && chr <= 'F') return (chr - 'A' + 10);
	else return -1;
}
int _TO_DEC(const char* str, const int size, const int index)
{
	int dec = 0;
	if (index == 2 || index == 16) 
	{
		for (int j = 2, i = size - 1; j < size; ++j, --i)
		{
			dec += chartoint(str[j]) * pow(index, i-2);
		}
	}
	else 
	{
		for (int j = 0, i = size - 1; j < size; ++j, --i)
		{
			dec += chartoint(str[j]) * pow(index, (i));
		}
	}
	return dec;
}

int main()
{
	int indexin = 0, indexout = 0;
	char str[100] = {};
	cout << "Chislo:";
	cin >> str;
	indexin = INDEX_IN(str);
	int n = mystrlen(str,indexin);
	if (INDEX_IN(str) == -1)
	{
		cout << "ne bratan, wrong chislo";
		return -1; 
	}
	cout << "osnovanie out:";
	cin >> indexout;
	if ((indexin == 16 && indexout == 2) ||
		(indexout == 16 && indexin == 2))
	{
		DEC_TO_(_TO_DEC(str, n, indexin), indexout);
	}
	else if (indexin == 10 && (indexout == 16 || indexout == 2))
	{
		DEC_TO_(strToInt(str,n,indexin), indexout);
	}
	else if (indexout == 10 && (indexin == 16 || indexin == 2))
	{
		cout<<_TO_DEC(str, n, indexin);
	}
	return 0;
}
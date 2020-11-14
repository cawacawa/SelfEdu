#include <iostream>
using namespace std;


int index_in(char* str)
{
	if (str[0] == '0')
	{
		if (str[1] == 'b' || str[1] == 'B') return 2;
		else if (str[1] == 'x' || str[1] == 'X') return 16;
	}
	else if (str[0] >= '1' && str[0] <= '9') return 10;
	return -1;
}

int my_strlen(char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return i;
}

int str_to_int(const char* str, const int size, int index)
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

void dec_to_(int num, const int index)
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

int char_to_int(const char chr)
{
	if (chr >= '0' && chr <= '9') return (chr - '0');
	else if (chr >= 'a' && chr <= 'f') return (chr - 'a' + 10);
	else if (chr >= 'A' && chr <= 'F') return (chr - 'A' + 10);
	else return -1;
}

int _to_dec(const char* str, const int size, const int index)
{
	int dec = 0;
	if (index == 2 || index == 16)
	{
		for (int j = 2, i = size - 1; j < size; ++j, --i)
		{
			dec += char_to_int(str[j]) * pow(index, i - 2);
		}
	}
	else
	{
		for (int j = 0, i = size - 1; j < size; ++j, --i)
		{
			dec += char_to_int(str[j]) * pow(index, (i));
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
	indexin = index_in(str);
	int n = my_strlen(str);
	if (index_in(str) == -1)
	{
		cout << "ne bratan, wrong chislo";
		return -1;
	}
	cout << "osnovanie out:";
	cin >> indexout;
	if ((indexin == 16 && indexout == 2) ||
		(indexout == 16 && indexin == 2))
	{
		dec_to_(_to_dec(str, n, indexin), indexout);
	}
	else if (indexin == 10 && (indexout == 16 || indexout == 2))
	{
		dec_to_(str_to_int(str, n, indexin), indexout);
	}
	else if (indexout == 10 && (indexin == 16 || indexin == 2))
	{
		cout << _to_dec(str, n, indexin);
	}
	return 0;
}
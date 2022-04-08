#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "¬ведите y: ";
	cin >> y;
	cout << "¬ведите z: ";
	cin >> z;
	char res[50];
	convert(y, res);
	cout << res << endl;
	char* str1 = new char[100];
	char* str2 = new char[110];
	strcpy(str1, "9999999&999999");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}
void convert(float y, char* str)
{
	double x = sin(3 * y) + 16.5;
	sprintf(str, "%08.8f = sin(3* %08.8f)+16.5", x, y);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 100);

	int adr = 0;
	char start[250] = {};
	char end[250] = {};

	for (int i = 0; i < strlen(str_l); i++) {
		start[i] = str_l[i];
		adr = i;
		if (str_l[i] == '&') break;
	}

	for (int i = adr+1, j = 0; i < strlen(str_l); i++, j++) {
		end[j] = str_l[i];
	}

	char res[250] = {};
	char sas[] = "100500";
	for (int i = 0; i < strlen(end); i++) {
		if (end[i] >= '0' && end[i] <= '9') {		
			strcat(res, sas);
		}
		else {
			strncat(res, i + end, 1);
		}
	}
	strcat(start, res);

	for (int i = 0; i < strlen(start); i++)
	{
		resault_l[i] = start[i];
	}
}
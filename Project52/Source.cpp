#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, float z, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "¬ведите y: ";
	cin >> y;
	cout << "¬ведите z: ";
	cin >> z;
	char res[500];
	convert(y, z, res);
	cout << res << endl;
	char* str1 = new char[2500];
	char* str2 = new char[2500];
	strcpy(str1, "9999999&999999");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}
void convert(float y,float z, char* str)
{
	double x = 2 * log(pow(y,(3*z))) - 2*log(3*z);  //X= 2*log(Y,3*Z) Ц 2*ln(3*Z)
	sprintf(str, "%14f = 2*log(%14f^(3*%14f)) Ц 2*ln(3*%14f)", x, y, z, z);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 2500);

	int adr = 0;
	char start[2500] = {};
	char end[2500] = {};

	for (int i = 0; i < strlen(str_l); i++) {
		start[i] = str_l[i];
		adr = i;
		if (str_l[i] == '&') break;
	}

	for (int i = adr+1, j = 0; i < strlen(str_l); i++, j++) {
		end[j] = str_l[i];
	}
	int count = 0;
	char res[2500] = {};
	char sas[] = "100500";
	for (int i = 0; i < strlen(end); i++) {
		if (end[i] >= '0' && end[i] <= '9') {		
			strcat(res, sas);
			count++;
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
	cout << "«амен: " << count << endl;
}
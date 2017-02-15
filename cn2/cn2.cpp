// cn2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned short chkSum(unsigned short * buf, int count);

using namespace std;

int main()
{
	int guess;
	char  a  [] = "No winter lasts forever; no spring skips its turn.\0";
	srand(time(NULL));
	unsigned short b[sizeof(a)/sizeof(a[0])];
	unsigned short ret;

	cout << a.size() << endl;
	cout << b.size() << endl;

	//Compress data, 2 char for each unsigned short
	for (int i = 0; i < strlen(a); i+=2)
	{
		b[i] = a[i] + a[i+1];

		cout << b[i] << endl;
	}



	//Message without altering
	/*ret = chkSum(b, sizeof(b));
	cout << ret << endl;

	//Alter one bit, randomly

	cout << sizeof(b) << endl;
	guess = rand() % sizeof(b) +1;
	cout << guess << endl;
	*/

    return 0;
}

unsigned short chkSum(unsigned short * buf, int count )
{
	register unsigned long sum = 0;

	while (count--)
	{
		sum += *buf++;
		if (sum & 0xFFFF0000)
		{
			//Carry occured
			sum &= 0xFFFF;
			sum++;
		}

	}
	return ~(sum & 0xFFFF);

}


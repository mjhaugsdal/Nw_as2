// cn2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <vector>

unsigned short chkSum(unsigned short * buf, int count);

using namespace std;

int main()
{
	int guess;
	char  a  [] = "No winter lasts forever; no spring skips its turn.\0";

	srand(time(NULL));

	//unsigned short b[];
	vector<unsigned short> b;
	unsigned short ret;

	//Compress data, 2 char for each unsigned short


	for (int i = 0; i < strlen(a); i+=2)
	{
		for (int j = i; j <= i; j++)
		{
			b.push_back(a[j] + a[j + 1]);	
		}
		


	}

	for (int i = 0; i < b.size(); i++)
		cout << b[i] << endl;

	//Message without altering

	unsigned short * d = &b[0];
	ret = chkSum(d, sizeof(b)/  sizeof(b[0]));


	//Pick a number randomly
	guess = rand() % sizeof(b) / sizeof(b[0]) + 1;
	//cout << guess << endl;


	//Alter one bit, randomly
	bitset <8> set(a[guess]);
	set.flip(0);
	unsigned long i = set.to_ulong();
	unsigned char c = static_cast<unsigned char>(i); // simplest -- no checks for 8 bit bitsets
	a[guess] = c;
	cout << a << endl;


	//Pick new number randomly
	guess = rand() % sizeof(b) / sizeof(b[0]) + 1;
	//Alter 3 bits, randomly
	bitset <8 >set2(a[guess]);
	set2.flip(0);
	set2.flip(1);
	set2.flip(2);
	i = set2.to_ulong();
	c = static_cast<unsigned char>(i); // simplest -- no checks for 8 bit bitsets
	a[guess] = c;
	cout << a;



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
			//
			sum &= 0xFFFF;
			sum++;
		}

	}
	return ~(sum & 0xFFFF);

}


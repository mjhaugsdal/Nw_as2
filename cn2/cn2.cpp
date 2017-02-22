// cn2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <vector>

using namespace std;

unsigned short chkSum(unsigned short * buf, int count);
vector<unsigned short> compress(char * a);
char * msgErr(char * a, int b, int c);


using namespace std;

int main()
{
	int guess;
	char  arr  [] = "No winter lasts forever; no spring skips its turn.";

	srand(time(NULL));

	vector<unsigned short> b;

	unsigned short ret;


	//Compress data, 2 char for each unsigned short




	/*for (int i = 0; i < b.size() ; i++)
		cout << b[i] << endl;*/

	cout << "This program will take the following message: ";
	cout << arr << endl;
	cout << "And do the following operations: " << endl;
	
	cout << "1. Compress 2 and 2 characters to single unsigned shorts" << endl;
	cout << "2. Perform a checksum algorithm on the message and show both message and checksum to the screen." << endl;
	cout << "3. Randomly permute the message, and show 1, 3 and 8 bit errors to the screen" << endl;
	cout << endl;



	//Message without altering
	b = compress(arr);
	unsigned short * d = &b[0];
	ret = chkSum(d, sizeof(b)/  sizeof(b[0]));
	cout << "Checksum of original message:  " << ret << endl;


	//cout << guess << endl;


	//Pick a number randomly
	guess = rand() % sizeof(b) / sizeof(b[0]) + 1;
	//Alter one bit, randomly

	strcpy_s(arr, msgErr(arr, 1, guess));
	cout << arr << endl;
	b = compress(arr);
	d = &b[0];
	ret = chkSum(d, sizeof(b) / sizeof(b[0]));
	cout << "Checksum: " << ret << endl;

	//Pick a number randomly
	guess = rand() % sizeof(b) / sizeof(b[0]) + 1;
	//3 bits
	strcpy_s(arr, msgErr(arr, 3, guess));
	cout << arr << endl;
	b = compress(arr);
	d = &b[0];
	ret = chkSum(d, sizeof(b) / sizeof(b[0]));
	cout << "Checksum: " << ret << endl;


	//Pick a number randomly
	guess = rand() % sizeof(b) / sizeof(b[0]) + 1;
	//8 bits
	strcpy_s(arr, msgErr(arr, 8, guess));
	cout << arr << endl;
	b = compress(arr);
	d = &b[0];
	ret = chkSum(d, sizeof(b) / sizeof(b[0]));
	cout << "Checksum: " << ret << endl;




    return 0;
}

char * msgErr(char * arr, int bit, int guess)
{

	//Alter one bit, randomly
	bitset <8> set(arr[guess]);

	for (int i = 0; i < bit; i++)
	{
		set.flip(i);
	}

	unsigned long i = set.to_ulong();
	unsigned char c = static_cast<unsigned char>(i);
	arr[guess] = c;

	return arr;

}


vector<unsigned short> compress(char * a)
{

	vector<unsigned short> b;

	for (int i = 0; i < strlen(a) / 2; i++)
	{
		unsigned short t1, t2;
		t1 = a[i + i];
		t2 = a[i + i + 1];
		//Shift
		t1 << 8;
		t1 |= t2;

		b.push_back(t1);

	}

	return b;
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


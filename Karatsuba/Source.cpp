#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*This function addes leading zeros to the shorter string*/
int makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
			str2 = '0' + str2;
	}
	return len1; // If len1 >= len2
}

/*Adds lagging zeros to the string based on power of 10*/
string multiplyByPowerof10(string str, int n)
{
	string str_10 = str;
	for (int i = 1; i <= n; i++)
	{
		str_10 = str_10 + '0';
	}
	return str_10;
}

/*Adds numeric values of two strings using grade-school addition*/
string addBitStrings(string str1, string str2)
{
	string result;  // To store the sum bits

	// make the lengths same before adding
	int length = makeEqualLength(str1, str2);
	//Carries 1 over, if sum of two digits is more than or equal to 10
	int global_carry = 0;
	// Add all bits one by one
	for (int i = length - 1; i >= 0; i--)
	{
		int firstBit = str1.at(i) - '0';
		int secondBit = str2.at(i) - '0';
		if ((firstBit == 0) || (secondBit == 0))
		{
			firstBit = (firstBit ^ secondBit);
		}
		else
		{
			//This carry variable represents the bitwise carry.
			int carry = firstBit & secondBit;
			int temp = firstBit ^ secondBit;
			carry = carry << 1;
			firstBit = temp + carry;
		}

		firstBit = firstBit + global_carry;
		if (firstBit >= 10)
		{
			firstBit = firstBit - 10;
			global_carry = 1;
		}
		else
			global_carry = 0;

		int sum = firstBit + '0';

		if ((global_carry == 1) && (i == 0))
		{
			result = (char)sum + result;
			result = '1' + result;
		}
		else
			result = (char)sum + result;
	}
	return result;
}
/*The Karatsuba function*/
string Karatsuba(string x, string y)
{
	int n = makeEqualLength(x, y);
	string a = x.substr(0, n / 2);
	string b = x.substr((n / 2), (n - n / 2));
	string c = y.substr(0, n / 2);
	string d = y.substr((n / 2), (n - n / 2));
	a = (a.empty()) ? "0" : a;
	b = (b.empty()) ? "0" : b;
	c = (c.empty()) ? "0" : c;
	d = (d.empty()) ? "0" : d;

	if (n == 1)
		return to_string((x.at(0) - '0')*(y.at(0) - '0'));
	else
	{
		string P1 = Karatsuba(a, c);
		string P2 = Karatsuba(a, d);
		string P3 = Karatsuba(b, c);
		string P4 = Karatsuba(b, d);

		//int odd = (n % 2 != 0) ? ((n / 2) + 1) : (n / 2);
		P1 = multiplyByPowerof10(P1, n);
		P2 = multiplyByPowerof10(P2, n / 2);
		P3 = multiplyByPowerof10(P3, n / 2);

		string result = addBitStrings(P1, P2);
		result = addBitStrings(result, P3);
		result = addBitStrings(result, P4);

		return result;
	}
}

int main()
{
	/*This program works best if number of digits are equal to 2^n*/
	string x = "3141592653589793238462643383279502884197169399375105820974944592";
	string y = "2718281828459045235360287471352662497757247093699959574966967627";
	string ans;
	ans = Karatsuba(x, y);
	cout << ans;

	ofstream log;
	log.open("log.txt");
	log << ans;
	log.close();

	cin.get();

}
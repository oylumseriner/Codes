/*
---ECDH---
Author: Dursun Oylum Seriner
Operating System: Win 10
IDE: Visual Studio 2019

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <iostream>
#include <mpirxx.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;






// I decided to change the this part.
mpz_class bitShiftToRight(mpz_class source, mpz_class shift) {
	for (mpz_class i = 0; i < shift; i++) {
		source = source >> 1;
	}
	return source;
}
mpz_class byteShiftToRight(mpz_class source, mpz_class shift) {
	for (mpz_class i = 0; i < shift; i++) {
		source = source >> 8;
		if (source == 0) {
			return 0;
		}
	}
	return source;
}
mpz_class getBitLength(mpz_class x) {
	mpz_class counter = 0;
	while (x != 0) {
		x = x >> 1;
		counter = counter + 1;
	}
	return counter;
}
mpz_class getByteLength(mpz_class x) {
	mpz_class counter = 0;
	while (x != 0) {
		x = x >> 8;
		counter = counter + 1;
	}
	return counter;
}
mpz_class makeMaskOfOnes(mpz_class numberOfByte) {
	mpz_class mask = 0xFF;
	mpz_class result = 1;
	for (mpz_class i = 0; i < numberOfByte * 8 - 1; i++) {
		result = (result << 1) + 1;
	}
	return result;
}

mpz_class readTextAsEncoded(string filePath) {
	ifstream input(filePath, std::ios::binary); 
	char charData;

	mpz_class result = 0;
	int numberOfChar = 0;
	while (input.get(charData)) {

		int unsignedNumber = (int)charData < 0 ? charData + 256 : charData; 
		result = (result << 8) + (unsignedNumber);
		numberOfChar++;
	}

	return result;
}
void writeNumberAsDecoded(mpz_class x, string path) {
	mpz_class mask = 0xFF;
	mpz_class bitLength = getBitLength(x);
	mpz_class charLength = (bitLength / 8) + 1;
	ofstream stream;
	stream.open(path, std::ios::binary); 

	if (!stream) {
		cout << "ERROR";
	}

	for (mpz_class i = 0; i < charLength; i++) {
		mpz_class shiftAmount = charLength - i - 1;
		mpz_class charOfX = byteShiftToRight(x, shiftAmount) & mask;
		int a = charOfX.get_si();
		char c = (char)a;
		stream << c;
	}
	stream.close();
}

//Point Methods

mpz_class p;
mpz_class a;
mpz_class b;
mpz_class n;

class Point
{
private:
	mpz_class x;
	mpz_class y;

public:
	Point(mpz_class x, mpz_class y)
	{
		this->x = x;
		this->y = y;
	}

	Point get_double() {
		mpz_class c3 = 3;
		mpz_class c2 = 2;
		mpz_class c2_inverse = 0;
		mpz_invert(c2_inverse.get_mpz_t(), c2.get_mpz_t(), p.get_mpz_t());

		mpz_class y_inverse = 0;
		mpz_invert(y_inverse.get_mpz_t(), y.get_mpz_t(), p.get_mpz_t());

		mpz_class lambda;
		lambda = ((3 * x * x) + a) * c2_inverse * y_inverse;
		lambda = lambda % p;
		mpz_class xr = (lambda * lambda - 2 * x) % p;
		mpz_class yr = (lambda * (x - xr) - y) % p;
		return Point(xr, yr);
	}
	Point add(const Point& point) {
		mpz_class y1_y2 = y - point.y;
		mpz_class x1_x2 = x - point.x;
		mpz_class x1_x2_inverse = 0;
		mpz_invert(x1_x2_inverse.get_mpz_t(), x1_x2.get_mpz_t(), p.get_mpz_t());

		mpz_class lambda = (y1_y2 * x1_x2_inverse) % p;

		mpz_class xr = (lambda * lambda - x - (point.x)) % p;
		mpz_class yr = (lambda * (x - xr) - y) % p;

		return Point(xr, yr);
	}
	// a.P
	Point multiply(mpz_class a) {
		Point result(x, y);
		for (int i = getBitLength(a).get_ui() - 1; i > 0; i--) {
			result = result.get_double();
			if (((a.get_ui() >> (i - 1)) & 0x1) == 1) {
				result = result.add(*this);
			}
		}
		return result;
	}

	void print() {
		cout << "(x,y)=" << x << "," << y << "\n";
	}


};
Point g(0, 0);

//file util

void readParameters() {
	ifstream stream;
	//I change the parameters file. I am sorry for that but I cannot compile with old form of text file.
	stream.open("parameters.txt");
	mpz_class x; char name; char deliminator;

	mpz_class gx;
	mpz_class gy;

	int counter = 0;
	while ((stream >> name >> deliminator >> x) && (deliminator == '=')) {
		switch (counter)
		{
		case 0:
			a = x;
			break;
		case 1:
			b = x;
			break;
		case 2:
			p = x;
			break;
		case 3:
			gx = x;
			break;
		case 4:
			gy = x;
			break;
		case 5:
			n = x;
			break;

		default:
			break;
		}
		counter++;
	}
	stream.close();
	g = Point(gx, gy);
}


mpz_class generate_random(mpz_class size) {
	unsigned __int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	mpz_class result = 0;
	gmp_randstate_t x;
	gmp_randinit_default(x);
	gmp_randseed_ui(x, now);
	mpz_urandomm(result.get_mpz_t(), x, size.get_mpz_t());
	return result;
}

Point transform_message_koblitz(mpz_class m) {
	mpz_class k = 30;
	mpz_class x;
	mpz_class rhs;
	mpz_class y;
	mpz_class exponent = (p + 1) / 4;
	for (int j = 0; j < k; j++) {
		x = m * k + j;
		rhs = x * x * x + a * x + b;
		if (mpz_legendre(rhs.get_mpz_t(), p.get_mpz_t()) == 1) {
			mpz_powm(y.get_mpz_t(), rhs.get_mpz_t(), exponent.get_mpz_t(), p.get_mpz_t());
			break;
		}
	}


	return Point(x, y);
}




void Q2() {
	cout << "Q2 starts\n\n";

	readParameters();
	cout << "**Private key** \n";
	cout << "Bob starts to generate his private key: \n";
	mpz_class beta = generate_random(n);
	cout << "Bob's private key is " << beta << "\n";

	cout << "Alice starts to generate her private key: \n";
	mpz_class alpha = generate_random(n);
	cout << "Alice's private key is " << alpha << "\n";

	cout << "**Public key** \n";
	cout << "Bob starts to generate his public key: \n";
	Point bob_public = g.multiply(beta);
	cout << "Bob's public key is \n";
	bob_public.print();

	cout << "Alice starts to generate her public key: \n";
	Point alice_public = g.multiply(alpha);
	cout << "Alice's public key is \n";
	alice_public.print();

	cout << "**Shared secret key** \n";
	cout << "Bob starts to calculate for exchanged key: \n";
	Point exchanged_by_bob = alice_public.multiply(beta);
	exchanged_by_bob.print();

	cout << "Alice starts to calculate for exchanged key \n";
	Point exchanged_by_alice = bob_public.multiply(alpha);
	exchanged_by_alice.print();

	cout << "Q2 ends\n\n";
}
void Q1() {
	cout << "Q1 starts\n\n";
	cout << "Started to read parameters\n";
	readParameters();
	cout << "a=" << a << "\n";
	cout << "b=" << b << "\n";
	cout << "p=" << p << "\n\n";
	//There are three txt file. I attached the zip file.
	mpz_class message1 = readTextAsEncoded("input_text_1.txt");
	mpz_class message2 = readTextAsEncoded("input_text_2.txt");
	mpz_class message3 = readTextAsEncoded("input_text_3.txt");

	//For test purposes
	writeNumberAsDecoded(message1, "test1");
	writeNumberAsDecoded(message2, "test2");
	writeNumberAsDecoded(message3, "test3");

	// message 1 -->
	cout << "Encoded message-1:\t" << message1 << "\n";
	cout << "Encoded message-2:\t" << message2 << "\n";
	cout << "Encoded message-3:\t" << message3 << "\n\n\n";

	cout << "Koblitz imbedded point for message-1 \n";
	transform_message_koblitz(message1).print();
	cout << "Koblitz imbedded point for message-2 \n";
	transform_message_koblitz(message2).print();
	cout << "Koblitz imbedded point for message-3 \n";
	transform_message_koblitz(message3).print();

	cout << "Q1 Ends\n\n";
}
int main()
{
	
	Q1();

	Q2();
	
}



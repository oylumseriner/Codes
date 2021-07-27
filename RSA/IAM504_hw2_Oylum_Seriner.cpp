/*
---RSA implemantation by using MPIR---
Author: Dursun Oylum Seriner
Operating System: Win 10
IDE: Visual Studio 2019

*/





#include <mpirxx.h>
#include <iostream>
#include <fstream>
using namespace std;
void syspause() {
	std::cout << "\nPress Enter To Continue..." << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
}
int main() {

	int buton;
	cout << "Please choose your option" << endl;
	cout << "----------------------------" << endl;
	cout << "1------> Generating Parameters " << endl;
	cout << "2------> Encryption" << endl;
	cout << "3------> Decrytion" << endl;

	cin >> buton;

	if (buton == 1) {

		mpz_class p, q, e, d;
		gmp_randstate_t state;
		gmp_randinit_mt(state);
		gmp_randseed_ui(state, time(0));
		mp_bitcnt_t n1 = 512;
		mpz_class shift;
		mpz_class base{ 2 };
		mpz_class exp{ 511 };
		
		
		
		mpz_urandomb(p.get_mpz_t(), state, n1);
		mpz_pow_ui(shift.get_mpz_t(), base.get_mpz_t(), exp.get_ui());
		p = shift | p;
		mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
		
		mpz_urandomb(q.get_mpz_t(), state, n1);
		mpz_pow_ui(shift.get_mpz_t(), base.get_mpz_t(), exp.get_ui());
		q = shift | q;
		mpz_nextprime(q.get_mpz_t(), q.get_mpz_t());


		mpz_probab_prime_p(p.get_mpz_t(), 10);
		mpz_probab_prime_p(q.get_mpz_t(), 10);
		

		mpz_class n;
		n = p * q;
		mpz_class phi;
		phi = (p - 1) * (q - 1);

		mpz_class test;

		e = 65537;
		mpz_gcd(test.get_mpz_t(), phi.get_mpz_t(), e.get_mpz_t());
		while (test != 1)
		{
			e = e + 2;
			mpz_gcd(test.get_mpz_t(), phi.get_mpz_t(), e.get_mpz_t());
		}


		mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());

		ofstream parameters("parameters.txt");

		if (parameters.fail()) {
			std::cout << "Error in opening file" << endl;
			exit(1);
		}
		parameters << p << endl << q << endl << n << endl << phi << endl << e << endl << d << endl;
		parameters.close();

	}

	else if (buton == 2) {

		ifstream key("parameters.txt");
		if (key.fail()) {
			cout << "Error Opening File" << endl;
		}
		mpz_class p, q, phi, n, e, d, pt, ct;
		key >> p >> q >> n >> phi >> e >> d;
		key.close();



		FILE* file;
		file = fopen("plain.txt", "r");
		char arr[128];
		fread(arr, 128, 1, file);// fread ( array or buffer, size_t size=128, size_t count=1, FILE  )
		fclose(file);
		cout << arr << endl;

		size_t s = 128;
		mpz_import(pt.get_mpz_t(), 128, 1, sizeof(arr[0]), 0, 0, arr);//mpz_import (pt, size_t count, int order,size_t size, int endian, size_t nail, data)
		mpz_powm(ct.get_mpz_t(), pt.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
		mpz_export(arr, &s, 1, sizeof(arr[0]), 0, 0, ct.get_mpz_t());

		FILE* file2 = fopen("cipher.txt", "w");
		fwrite(arr, 1, 128, file2); 

		fclose(file2);


	}

	else if (buton == 3) {

		ifstream key("parameters.txt");
		if (key.fail()) {
			cout << "Error Opening File" << endl;
		}
		mpz_class p, q, phi, n, e, d, ct, pt;
		key >> p >> q >> n >> phi >> e >> d;
		key.close();

		FILE* file;
		file = fopen("cipher.txt", "r");
		char arr[128];
		fread(arr, 128, 1, file);
		fclose(file);

		size_t s = 128;
		mpz_import(ct.get_mpz_t(), 128, 1, sizeof(arr[0]), 0, 0, arr);
		mpz_powm(pt.get_mpz_t(), ct.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
		mpz_export(arr, &s, 1, sizeof(arr[0]), 0, 0, pt.get_mpz_t());

		FILE* file2 = fopen("message.txt", "w");
		fwrite(arr, 1, 128, file2);

		fclose(file2);



		//There are extra nonsense characters.
		cout << "Original message is: " << arr;


	}

	syspause();



}
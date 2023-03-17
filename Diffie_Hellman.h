#pragma once
#include <cstdlib>
#include "bigint.h"

namespace FT42
{
	class Diffie_Hellman
	{
		iamtcs::BigInt iSpecial_Key;	//X, Y
		iamtcs::BigInt iPrivate_Key;	//a, b
		iamtcs::BigInt iSecrete_Key;	//k_a, k_b
	public:

		iamtcs::BigInt iPublic_Key1;	//P
		iamtcs::BigInt iPublic_Key2;	//G

		Diffie_Hellman() : iPublic_Key1(23), iPublic_Key2(9)
		{
			int iTemp = 0;

			iTemp = rand() % 10;

			while (!iTemp)
			{
				iTemp = rand() % 10;
			}

			iPrivate_Key.assign(iTemp);
		}

		void Create_Special_Key();
		void Create_Secret_Key(iamtcs::BigInt *);

		void Print_Private_Key();
		void Print_Special_Key();
		void Print_Secrete_Key();

		iamtcs::BigInt * getSpecial_Key();

		void Print();	//Prints Whole Diffie_Hellman Objects
		char * Print(iamtcs::BigInt);	//Returned value of received BigInt Object
	};
}

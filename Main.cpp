#pragma once
#include <iostream>
#include "Diffie_Hellman.h"

using namespace FT42;

int main()
{
	Diffie_Hellman Alice, Bob;
	iamtcs::BigInt *Alice_Special_Key, *Bob_Special_Key;

	Alice.Create_Special_Key();
	Bob.Create_Special_Key();

	Alice_Special_Key = Alice.getSpecial_Key();
	Bob_Special_Key = Bob.getSpecial_Key();

	Alice.Create_Secret_Key(Bob_Special_Key);
	Bob.Create_Secret_Key(Alice_Special_Key);

	Alice_Special_Key = nullptr;
	Bob_Special_Key = nullptr;

	std::cout << "For Alice\n";
	Alice.Print();
	std::cout << "\nFor Bob\n";
	Bob.Print();

	return 0;
}
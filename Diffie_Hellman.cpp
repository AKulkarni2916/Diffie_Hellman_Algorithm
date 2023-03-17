#pragma once
#include <iostream>
#include "Diffie_Hellman.h"
#include <mpir.h>
#include "bigint.h"

using namespace FT42;

void Diffie_Hellman::Create_Special_Key()
{
	iamtcs::BigInt Temp1(iPublic_Key2);
	iamtcs::BigInt Temp2;

	Temp1.powr(iPrivate_Key);
	Temp1.modulo(iPublic_Key1, &Temp2);

	iSpecial_Key.assign(Temp2);
}

void Diffie_Hellman::Create_Secret_Key(iamtcs::BigInt *Temp_Special_Key)
{
	iamtcs::BigInt Temp;

	Temp_Special_Key->powr(iPrivate_Key);
	Temp_Special_Key->modulo(iPublic_Key1, &Temp);

	iSecrete_Key.assign(Temp);
	
	delete Temp_Special_Key;
	Temp_Special_Key = nullptr;
}

void Diffie_Hellman::Print_Private_Key()
{
	unsigned int len;
	char* str = nullptr;

	iPrivate_Key.toStr(str, len, 10);

	std::cout << str << std::endl;
}

void Diffie_Hellman::Print_Special_Key()
{
	unsigned int len;
	char* str = nullptr;

	iSpecial_Key.toStr(str, len, 10);

	std::cout << str << std::endl;
}

void Diffie_Hellman::Print_Secrete_Key()
{
	unsigned int len;
	char* str = nullptr;

	iSecrete_Key.toStr(str, len, 10);

	std::cout << str << std::endl;;
}

iamtcs::BigInt * Diffie_Hellman::getSpecial_Key()
{
	iamtcs::BigInt* Special_Key_Ptr = new iamtcs::BigInt(iSpecial_Key);

	return Special_Key_Ptr;
}

void Diffie_Hellman::Print()
{
	unsigned int len;
	char* str = nullptr;

	this->iPublic_Key1.toStr(str, len, 10);
	std::cout << "iPublic_Key1 = " << str <<std::endl;
	str = nullptr;
	
	this->iPublic_Key2.toStr(str, len, 10);
	std::cout << "iPublic_Key2 = " << str << std::endl;

	std::cout << "iPrivate_Key = ";
	this->Print_Private_Key();

	std::cout << "iSpecial_Key = ";
	this->Print_Special_Key();

	std::cout << "iSecrete_Key = ";
	this->Print_Secrete_Key();
}

char * Diffie_Hellman::Print(iamtcs::BigInt Obj)
{
	unsigned int len;
	char* str = nullptr;

	Obj.toStr(str, len, 10);

	return str;
}
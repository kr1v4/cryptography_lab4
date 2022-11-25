#include "Utils.hpp"

bool kGen::Utils::is_power_of_2(int number)
{
	return (number > 0 && ((number & (number - 1)) == 0));
}

bool kGen::Utils::is_prime(int number)
{
	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	for (int i = 3; (i * i) <= number; i += 2)
		if (number % i == 0) return false;
	return true;
}

int kGen::Utils::gcd(int first_number, int second_number)
{
	return second_number == 0 ? first_number : gcd(second_number, first_number % second_number);
}
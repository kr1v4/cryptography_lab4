#include "LinearCongruentialGenerator.hpp"

kGen::ullong_t kGen::Linear_Congruential_Generator::get_increment()
{
	return _b;
}

kGen::ullong_t kGen::Linear_Congruential_Generator::get_multiplier()
{
	return _a;
}

int kGen::Linear_Congruential_Generator::get_module()
{
	return _m;
}

bool kGen::Linear_Congruential_Generator::set_increment(ullong_t b)
{
	if (Utils::gcd(_a, b) != 1)
	{
		return false;
	}
	_b = b;
	return true;
}

bool kGen::Linear_Congruential_Generator::set_multiplier(ullong_t a)
{
	if (a % 2 == 0)
	{
		return false;
	}
	_a = a;
	return true;
}

bool kGen::Linear_Congruential_Generator::set_module(int m)
{
	if	(		Utils::gcd(_b, m) != 1
			&&	!Utils::is_prime(m) 
			&&	!Utils::is_power_of_2(m) 
		)
	{
		return false;
	}
	_m = m;
	return true;
}

kGen::Linear_Congruential_Generator& kGen::Linear_Congruential_Generator::get_instanse()
{
	static Linear_Congruential_Generator lcg;
	return lcg;
}
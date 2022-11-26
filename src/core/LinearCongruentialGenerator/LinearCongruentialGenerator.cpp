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

std::bitset<16> kGen::Linear_Congruential_Generator::rand_bin16(std::bitset<16> seed_bin)
{
	ullong_t seed = seed_bin.to_ullong();

	ullong_t next = (_a * seed + _b) % _m;

	return std::bitset<16>(next);
}

kGen::Linear_Congruential_Generator& kGen::Linear_Congruential_Generator::get_instanse()
{
	static Linear_Congruential_Generator lcg;
	return lcg;
}
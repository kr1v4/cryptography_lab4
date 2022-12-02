#include "LinearFeedbackShiftRegister.hpp"
#include <iostream>

kGen::Linear_Feedback_Shift_Register& kGen::Linear_Feedback_Shift_Register::get_instanse()
{
    static Linear_Feedback_Shift_Register lfsr;
    return lfsr;
}

int kGen::Linear_Feedback_Shift_Register::xor_by_relations()
{
	int xor_result = _register[0];
	for (int i = 0; i < _relations.size(); ++i)
	{
		if (_relations[i])
		{
			xor_result ^= _register[i + 1];
		}
	}
	return xor_result;
}

std::bitset<17> kGen::Linear_Feedback_Shift_Register::get_register()
{
	return _register;
}

std::bitset<16> kGen::Linear_Feedback_Shift_Register::get_relations()
{
	return _relations;
}

void kGen::Linear_Feedback_Shift_Register::set_register(std::bitset<17> register_)
{
	_register = register_;
}

void kGen::Linear_Feedback_Shift_Register::set_relations(std::bitset<16> relations)
{
	_relations = relations;
}

std::bitset<128> kGen::Linear_Feedback_Shift_Register::rand_bin128(std::bitset<17> seed_bin)
{
	//LOG
	std::cout << "\t\tRAND_BIN128 WORKING:\n";
	set_register(seed_bin);
	std::bitset<128> next;
	for (int i = 0; i < 128; i++) {
		std::cout << "\t\tIteration: " << i << "\n";
		std::cout << "\t\tRegister Before XOR: \n";
		std::cout << "\t\t\t" << _register.to_string() << "\n";

		int result = xor_by_relations();
		next[i] = result;
		_register >>= 1;
		_register[16] = result;

		std::cout << "\t\tRegister After XOR: \n";
		std::cout <<"\t\t\t" << _register.to_string() << "\n";
	}
	return next;
}
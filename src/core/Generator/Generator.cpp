#include "Generator.hpp"

kGen::Generator& kGen::Generator::get_instanse()
{
	
	static Generator generator;
	return generator;
	
}

kGen::Linear_Congruential_Generator& kGen::Generator::get_lcg()
{
	return _lcg;
}

kGen::Linear_Feedback_Shift_Register& kGen::Generator::get_lfsr()
{
	return _lfsr;
}

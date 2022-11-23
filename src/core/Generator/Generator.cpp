#include "Generator.hpp"

kGen::Generator& kGen::Generator::get_instanse()
{
	
	static Generator generator;
	return generator;
	
}
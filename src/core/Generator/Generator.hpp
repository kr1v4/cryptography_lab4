#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include "../LinearCongruentialGenerator/LinearCongruentialGenerator.hpp"
#include <iostream>
#include <memory>

namespace kGen {
	
	class Generator {

		public:

			static Generator& get_instanse();
			Linear_Congruential_Generator& get_lcg();

		public:

			Generator(const Generator&) = delete;
			Generator(Generator&&) = delete;

			Generator& operator=(Generator&) = delete;
			Generator& operator=(Generator&&) = delete;

		private:
			Linear_Congruential_Generator &_lcg = Linear_Congruential_Generator::get_instanse();

			Generator() = default;
	};

}
#endif
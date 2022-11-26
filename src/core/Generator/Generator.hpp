#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include "../LinearCongruentialGenerator/LinearCongruentialGenerator.hpp"
#include "../LinearFeedbackShiftRegister/LinearFeedbackShiftRegister.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace kGen {
	
	class Cryptographer;

	class Generator {

		public:
			friend Cryptographer;

		public:

			Linear_Congruential_Generator& get_lcg();
			Linear_Feedback_Shift_Register& get_lfsr();
			std::vector<bool> get_gamma(std::string message);

		public:

			Generator(const Generator&) = delete;
			Generator(Generator&&) = delete;

			Generator& operator=(Generator&) = delete;
			Generator& operator=(Generator&&) = delete;

		private:
			static Generator& get_instanse();

		private:
			Linear_Congruential_Generator	&	_lcg	= Linear_Congruential_Generator::get_instanse();
			Linear_Feedback_Shift_Register	&	_lfsr	= Linear_Feedback_Shift_Register::get_instanse();

			Generator() = default;
	};

}
#endif
#ifndef LINEAR_CONGRUENTIAL_GENERATOR_HPP
#define LINEAR_CONGRUENTIAL_GENERATOR_HPP
#include "../Utils/Utils.hpp"
#include <bitset>

namespace kGen
{
	class Generator;

	class Linear_Congruential_Generator
	{
		public:

			friend Generator;

		public:

			ullong_t	get_increment();
			ullong_t	get_multiplier();
			int			get_module();

			bool		set_increment(ullong_t b);
			bool		set_multiplier(ullong_t a);
			bool		set_module(int m);
			std::bitset<16> rand_bin16(std::bitset<16> seed_bin);

		public:

			Linear_Congruential_Generator(const Linear_Congruential_Generator&) = delete;
			Linear_Congruential_Generator(Linear_Congruential_Generator&&) = delete;

			Linear_Congruential_Generator& operator=(Linear_Congruential_Generator&) = delete;
			Linear_Congruential_Generator& operator=(Linear_Congruential_Generator&&) = delete;

		private:

			static Linear_Congruential_Generator& get_instanse();

		private:

			Linear_Congruential_Generator() = default;

		private:

			ullong_t _a = 1664525;
			ullong_t _b = 1;
			int _m = 65536;
	};
}
#endif
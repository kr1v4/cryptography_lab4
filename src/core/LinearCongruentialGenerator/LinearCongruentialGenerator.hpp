#ifndef LINEAR_CONGRUENTIAL_GENERATOR_HPP
#define LINEAR_CONGRUENTIAL_GENERATOR_HPP

#include "../Utils/Utils.hpp"

namespace kGen
{
	class Linear_Congruential_Generator
	{
		public:

			ullong_t	get_increment();
			ullong_t	get_multiplier();
			int			get_module();

			bool		set_increment(ullong_t b);
			bool		set_multiplier(ullong_t a);
			bool		set_module(int m);

		public:

			static Linear_Congruential_Generator& get_instanse();

		public:

			Linear_Congruential_Generator(const Linear_Congruential_Generator&) = delete;
			Linear_Congruential_Generator(Linear_Congruential_Generator&&) = delete;

			Linear_Congruential_Generator& operator=(Linear_Congruential_Generator&) = delete;
			Linear_Congruential_Generator& operator=(Linear_Congruential_Generator&&) = delete;

		private:

			Linear_Congruential_Generator() = default;

		private:

			ullong_t _a = 1664525;
			ullong_t _b = 1;
			int _m = 65536;
	};
}
#endif
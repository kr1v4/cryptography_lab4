#ifndef CRYPTOGRAPHER_HPPLinear_Congruential_Generator
#define CRYPTOGRAPHER_HPP
#include "../Generator/Generator.hpp"

namespace kGen
{
	class Cryptographer
	{
		public:

			static Cryptographer& get_instanse();

			std::string encrypt(std::string msg);
			std::string decrypt(std::string encrypted_msg);

		public:

			Cryptographer(const Cryptographer&) = delete;
			Cryptographer(Cryptographer&&) = delete;

			Cryptographer& operator=(Cryptographer&) = delete;
			Cryptographer& operator=(Cryptographer&&) = delete;

		private:

			Generator& _generator = Generator::get_instanse();

		private:

			Cryptographer() = default;

	};
}

#endif
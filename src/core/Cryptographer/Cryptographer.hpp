#ifndef CRYPTOGRAPHER_HPP
#define CRYPTOGRAPHER_HPP

#include "../Generator/Generator.hpp"

namespace kGen
{
	class Cryptographer
	{
		public:

			static Cryptographer& get_instanse();

			std::string encrypt(std::string msg, kGen::cr_string file_to_first_lcg_key);
			std::string decrypt(std::string encrypted_msg, kGen::cr_string file_to_first_lcg_key);

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
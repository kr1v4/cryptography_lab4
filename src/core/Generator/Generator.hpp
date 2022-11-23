#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include <iostream>

namespace kGen {

	class Generator {

		public:

			static Generator& get_instanse();

		public:

			Generator(const Generator&) = delete;
			Generator(Generator&&) = delete;

			Generator& operator=(Generator&) = delete;
			Generator& operator=(Generator&&) = delete;

		private:

			Generator() = default;
	};

}
#endif
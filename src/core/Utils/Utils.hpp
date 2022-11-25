#ifndef UTILS_HPP
#define UTILS_HPP

namespace kGen
{
	using ullong_t = unsigned long long;

	class Utils
	{
		public:
			/**
			*  Check if given number is a power of 2
			*
			* @param number Number to check
			* @return return true if given number is power of two, else return false
			*/

			static bool is_power_of_2(int number);

			/**
			* Check if given number is prime
			*
			* @param number Number to check
			* @return return true if given number is prime, else return false
			*/

			static bool is_prime(int number);

			/**
			* Find greatest common divisor of 2 numbers with Euclidean algorithm
			*
			* @param first_number First number to find
			* @param second_number Second number to find
			* @return greatest common divisor of 2 numbers
			*/

			static int gcd(int first_number, int second_number);
	};
}
#endif

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

namespace kGen
{
	using ullong_t = unsigned long long;
	using cr_string = const std::string&;

	class Utils
	{
		public:
			
			static bool is_power_of_2(int number);

			static bool is_prime(int number);

			static int gcd(int first_number, int second_number);
			
			static void xor_vectors(std::vector<bool>& first_vector, const std::vector<bool>& second);

			static void show_vec_bool(const std::vector<bool>& vector);

			static std::vector<bool> string_to_bits(const std::string& str);

			static std::string bits_to_string(const std::vector<bool> &bits);

			static bool read_file_to_string(cr_string path_to_file, std::string& file_data);

			static bool write_string_to_file(cr_string path_to_file, cr_string str);
	};
}
#endif

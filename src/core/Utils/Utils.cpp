#include "Utils.hpp"

bool kGen::Utils::is_power_of_2(int number)
{
	return (number > 0 && ((number & (number - 1)) == 0));
}

bool kGen::Utils::is_prime(int number)
{
	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	for (int i = 3; (i * i) <= number; i += 2)
		if (number % i == 0) return false;
	return true;
}

int kGen::Utils::gcd(int first_number, int second_number)
{
	return second_number == 0 ? first_number : gcd(second_number, first_number % second_number);
}

void kGen::Utils::xor_vectors(std::vector<bool>& first_vector, const std::vector<bool>& second_vector)
{
	for (auto i = 0; i < first_vector.size(); ++i)
	{
		first_vector[i] = first_vector[i] ^ second_vector[i];
	}
}

void kGen::Utils::show_vec_bool(const std::vector<bool>& vector)
{
	for (auto el : vector)
	{
		std::cout << el;
	}
	std::cout << "\n";
}

std::vector<bool> kGen::Utils::string_to_bits(const std::string& str)
{
	std::vector<bool> str_bin;
	constexpr int char_size = 8;

	for (auto letter : str)
	{
		std::bitset<char_size> letter_bin(letter);
		for (auto i = 0; i < char_size; ++i)
		{
			str_bin.push_back(letter_bin[i]);
		}
	}
	return str_bin;
}


std::string kGen::Utils::bits_to_string(const std::vector<bool>& bits)
{
	if (bits.size() < 8 || bits.size() % 8 != 0)
	{
		return "Error";
	}

	std::string str;

	constexpr int char_size = 8;

	std::string current_letter_bits="";
	int bits_counter = 0;
	for (auto i = 0; i < bits.size(); ++i)
	{
		if (bits_counter == char_size)
		{
			std::reverse(current_letter_bits.begin(), current_letter_bits.end());
			std::bitset<char_size> letter_bitset(current_letter_bits);

			// https://stackoverflow.com/questions/30584463/how-to-convert-string-of-binary-values-back-to-char

			char letter = static_cast<char>(letter_bitset.to_ulong() + 256);
			current_letter_bits.clear();
			str.push_back(letter);
			bits_counter = 0;
		}
		if (bits[i])
		{
			current_letter_bits += "1";
		}
		else
		{
			current_letter_bits += "0";
		}
		if (i == bits.size() - 1)
		{
			std::reverse(current_letter_bits.begin(), current_letter_bits.end());
			std::bitset<char_size> letter_bitset(current_letter_bits);
			char letter = static_cast<char>(letter_bitset.to_ulong() + 256);
			current_letter_bits.clear();
			str.push_back(letter);
		}
		++bits_counter;
	}
	return str;
}

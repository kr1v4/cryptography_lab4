#include "Generator.hpp"

kGen::Generator& kGen::Generator::get_instanse()
{
	
	static Generator generator;
	return generator;
	
}

kGen::Linear_Congruential_Generator& kGen::Generator::get_lcg()
{
	return _lcg;
}

kGen::Linear_Feedback_Shift_Register& kGen::Generator::get_lfsr()
{
	return _lfsr;
}

std::vector<bool> kGen::Generator::get_gamma(kGen::cr_string message, kGen::cr_string file_with_lcg_key)
{
	std::vector<bool> gamma;

	int msg_len_bit = message.length() * 8;
	int amount_of_blocks = std::ceil(msg_len_bit / 128.0);

	std::string previous_lcg_result_str;
	Utils::read_file_to_string(file_with_lcg_key, previous_lcg_result_str);

	std::bitset<16> previous_lcg_result(previous_lcg_result_str);


	//LOG
	std::cout << "Amount of iterations: \n";
	std::cout << amount_of_blocks << "\n";


	while (amount_of_blocks > 0)
	{
		//LOG
		std::cout << "LCG STAGE:\n";
		std::cout << "\tPrevious lcg result: \n";
		std::cout << "\t" << previous_lcg_result.to_string() << "\n";
		//LOG
		std::cout << "\n\n";


		std::bitset<16> current_lcg_result = _lcg.rand_bin16(previous_lcg_result);
		previous_lcg_result = current_lcg_result;

		//LOG
		std::cout << "\tCurrent lcg result: \n";
		std::cout << "\t" << current_lcg_result.to_string() << "\n";
		//LOG
		std::cout << "\n\n";

		// push_front 0 - bit
		std::bitset<17> input_for_lfsr;
		for (auto i = 15; i >= 0; --i)
		{
			input_for_lfsr.set(i, current_lcg_result[i]);
		}


		//LOG
		std::cout << "\tInput for lfsr result: \n";
		std::cout << "\t" << input_for_lfsr.to_string() << "\n";
		//LOG
		std::cout << "\n\n";

		std::cout << "LFSR STAGE:\n";
		std::bitset<128> current_lfsr_result = _lfsr.rand_bin128(input_for_lfsr);
		std::cout << "\tCurrent LFSR result: \n";
		std::cout << "\t" << current_lcg_result.to_string() << "\n";

		for (auto i = 0; i < 128; ++i)
		{
			gamma.push_back(current_lfsr_result[i]);
		}

		//LOG
		std::cout << "Current Gamma:\n";
		Utils::show_vec_bool(gamma);
		std::cout << "\n\n";
		--amount_of_blocks;
	}
	return gamma;
}

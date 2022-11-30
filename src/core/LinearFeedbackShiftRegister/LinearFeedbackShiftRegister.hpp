#ifndef LINEAR_FEEDBACK_SHIFT_REGISTER_HPP
#define LINEAR_FEEDBACK_SHIFT_REGISTER_HPP

#include <bitset>

namespace kGen
{
	class Generator;

	class Linear_Feedback_Shift_Register
	{
		public:

			friend Generator;

		public:

			std::bitset<17> get_register();
			std::bitset<16> get_relations();
			void set_register(std::bitset<17> register_);
			void set_relations(std::bitset<16> relations);

			std::bitset<128> rand_bin128(std::bitset<17> seed_bin);

		public:

			Linear_Feedback_Shift_Register(const Linear_Feedback_Shift_Register&) = delete;
			Linear_Feedback_Shift_Register(Linear_Feedback_Shift_Register&&) = delete;

			Linear_Feedback_Shift_Register& operator=(Linear_Feedback_Shift_Register&) = delete;
			Linear_Feedback_Shift_Register& operator=(Linear_Feedback_Shift_Register&&) = delete;

		private:

			static Linear_Feedback_Shift_Register& get_instanse();

		private:

			Linear_Feedback_Shift_Register() = default;

		private:

			std::bitset<17> _register = std::bitset<17>("00000000000000000");
			std::bitset<16> _relations = std::bitset<16>("0000000000000000");

		private:
			int xor_by_relations();
	};
}

#endif 
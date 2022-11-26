#include "Application.hpp"
#include "../Generator/Generator.hpp"
#include "../LinearCongruentialGenerator/LinearCongruentialGenerator.hpp"

void Application::start()
{
    show_me();
    auto& my_gen = kGen::Generator::get_instanse();
    auto& lcg = my_gen.get_lcg();
    auto& lfsr = my_gen.get_lfsr();


    std::string bit_val = "1010101010101010";
    std::bitset<16> bset(bit_val);

    std::bitset<16> result16 = lcg.rand_bin16(bset);


    constexpr int size = 17;
    std::bitset<size> second;
    std::cout << result16 << "\n";

    std::cout << second << "\n";
    for (auto i = size - 2; i >= 0; --i)
    {
        second.set(i, result16[i]);
    }

    std::cout << second << "\n";

    


    std::cout << lfsr.rand_bin128(second);


}





























void Application::show_me()
{
    std::string nickname =
        R"(
       			 __                   __                  _                       
       			/\ \                 /\ \               /' \                      
       			\ \ \____   __  __   \ \ \/'\    _ __  /\_, \   __  __     __     
       			 \ \ '__`\ /\ \/\ \   \ \ , <   /\`'__\\/_/\ \ /\ \/\ \  /'__`\   
       			  \ \ \L\ \\ \ \_\ \   \ \ \\`\ \ \ \/    \ \ \\ \ \_/ |/\ \L\.\_ 
       			   \ \_,__/ \/`____ \   \ \_\ \_\\ \_\     \ \_\\ \___/ \ \__/.\_\
       			    \/___/   `/___/> \   \/_/\/_/ \/_/      \/_/ \/__/   \/__/\/_/
       			                /\___/                                            
       			                \/__/                                             		 
    )";
    std::cout << nickname << "\n";
}
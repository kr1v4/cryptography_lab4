#include "Application.hpp"
#include "../Generator/Generator.hpp"

void Application::start()
{
    show_me();
    auto& my_gen = kGen::Generator::get_instanse();
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
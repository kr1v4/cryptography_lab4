#include "Application.hpp"
#include "../Cryptographer/Cryptographer.hpp"

void Application::start()
{
    show_me();

    std::string msg_to_encrypt = "My little test string to get gamma";

    auto& cryptographer = kGen::Cryptographer::get_instanse();

    std::string encrypted_msg = cryptographer.encrypt(msg_to_encrypt);

    std::string decrypted_msg = cryptographer.decrypt(encrypted_msg);



    std::cout << msg_to_encrypt <<"." <<"\n";
    std::cout << encrypted_msg << "." << "\n";
    std::cout << decrypted_msg << "." << "\n";

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
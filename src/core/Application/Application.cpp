#include "Application.hpp"
#include "../Cryptographer/Cryptographer.hpp"

void Application::start()
{
    show_me();

	auto& cryptographer = kGen::Cryptographer::get_instanse();
	std::string source_path;
	std::string result_path;
	std::string key_path;

	int wt_choice;

	for (;;)
	{
		std::cout << "Enter the path to the original text: ";
		if ((std::cin >> source_path).good())
		{
			break;
		};
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again\n";
		}
		std::cin.ignore(100, '\n');
	}

	for (;;)
	{
		std::cout << "What needs to be done?\n1-ENCRYPT MODE\n2-DECRYPT MODE\n";
		if ((std::cin >> wt_choice).good() && wt_choice > 0 && wt_choice < 3)
		{
			break;
		};
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again\n";
		}
		else
		{
			std::cout << "Entered number is out of range, please try again\n";
		}
		std::cin.ignore(100, '\n');
	}

	for (;;)
	{
		if (wt_choice == 1)
		{
			std::cout << "Enter the path to the file where the encrypted text will be written: ";
		}
		else
		{
			std::cout << "Enter the path to the file where the decrypted text will be written: ";
		}
		if ((std::cin >> result_path).good())
		{
			break;
		};
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again\n";
		}
		std::cin.ignore(100, '\n');
	}

	for (;;)
	{
		std::cout << "Enter the path to the first file with key: ";
		if ((std::cin >> key_path).good())
		{
			break;
		};
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again\n";
		}
		std::cin.ignore(100, '\n');
	}

	std::string source;
	kGen::Utils::read_file_to_string(source_path, source);

	if (wt_choice == 1)
	{
		std::string encrypted_msg = cryptographer.encrypt(source, key_path);
		
		kGen::Utils::write_string_to_file(result_path, encrypted_msg);

		return;
	}
	std::string decrypted_msg = cryptographer.decrypt(source, key_path);

	kGen::Utils::write_string_to_file(result_path, decrypted_msg);

    /*std::string msg_to_encrypt = "My little test string to get gamma";

    auto& cryptographer = kGen::Cryptographer::get_instanse();

    std::string encrypted_msg = cryptographer.encrypt(msg_to_encrypt, "lcg_key.txt");

    std::string decrypted_msg = cryptographer.decrypt(encrypted_msg, "lcg_key.txt");



    std::cout << msg_to_encrypt <<"." <<"\n";
    std::cout << encrypted_msg << "." << "\n";
    std::cout << decrypted_msg << "." << "\n";*/

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
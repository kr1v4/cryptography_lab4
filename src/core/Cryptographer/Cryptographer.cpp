#include "Cryptographer.hpp"

kGen::Cryptographer& kGen::Cryptographer::get_instanse()
{
    static Cryptographer cryptographer;
    return cryptographer;
}

std::string kGen::Cryptographer::encrypt(std::string msg)
{
    while (msg.length() % 16 != 0)
    {
        msg.push_back(' ');
    }

    std::vector<bool> gamma = _generator.get_gamma(msg);
    std::vector<bool> string_bits = Utils::string_to_bits(msg);
    std::vector<bool> encrypted = gamma;

    Utils::xor_vectors(encrypted, string_bits);

    std::string encrypted_msg = Utils::bits_to_string(encrypted);

    return encrypted_msg;
}

std::string kGen::Cryptographer::decrypt(std::string encrypted_msg)
{
    while (encrypted_msg.length() % 16 != 0)
    {
        encrypted_msg.push_back(' ');
    }

    std::vector<bool> gamma = _generator.get_gamma(encrypted_msg);
    std::vector<bool> string_bits = Utils::string_to_bits(encrypted_msg);
    std::vector<bool> decrypted = gamma;

    Utils::xor_vectors(decrypted, string_bits);

    std::string decrypted_msg = Utils::bits_to_string(decrypted);

    return decrypted_msg;
}
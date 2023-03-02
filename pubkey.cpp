#include <bitcoin/bitcoin.hpp>

int main() {
    // Generate a private key
    bc::ec_secret private_key;
    bc::pseudo_random_fill(private_key);

    // Generate the corresponding public key
    bc::ec_compressed public_key;
    bc::secret_to_public(public_key, private_key);

    // Print the public key
    std::cout << "Public Key: " << bc::encode_base16(public_key) << std::endl;

    return 0;
}

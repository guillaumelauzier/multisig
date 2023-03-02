#include <bitcoin/bitcoin.hpp>

int main() {
  // Generate a new random private key
  bc::ec_secret private_key = bc::generate_secret();

  // Print the private key in hex format
  std::cout << "Private key: " << bc::encode_hex(private_key) << std::endl;

  return 0;
}

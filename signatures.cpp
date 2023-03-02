#include <iostream>
#include <string>
#include <bitcoin/bitcoin.hpp>

int main() {
  // Private key
  std::string private_key_string = "91a7b8a9c3d6f48e2b7281f2dd1dcd0a7e462c472a98675e1918de9a292d6714";
  bc::ec_secret private_key;
  bc::decode_base16(private_key, private_key_string);

  // Public key
  bc::ec_compressed public_key = bc::secret_to_public_key(private_key);

  // Message to sign
  std::string message = "This is a test message.";

  // Hash the message
  bc::data_chunk message_data(message.begin(), message.end());
  bc::hash_digest message_hash = bc::hash_sha256(message_data);

  // Sign the message
  bc::ec_signature signature = bc::sign_message(message_hash, private_key);

  // Verify the signature
  bool valid = bc::verify_message(public_key, message_hash, signature);

  // Output the signature and validity
  std::cout << "Signature: " << bc::encode_base16(signature) << std::endl;
  std::cout << "Valid: " << (valid ? "true" : "false") << std::endl;

  return 0;
}

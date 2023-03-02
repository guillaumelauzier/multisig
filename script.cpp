#include <iostream>
#include <string>
#include <vector>
#include <bitcoin/bitcoin.hpp>

int main() {
  // Generate two public keys
  bc::ec_secret secret1;
  bc::data_chunk secret_chunk1 = bc::to_chunk(secret1);
  bc::wallet::ec_private private_key1(secret_chunk1, bc::wallet::ec_private::mainnet_p2kh);
  bc::wallet::ec_public public_key1 = private_key1.to_public();

  bc::ec_secret secret2;
  bc::data_chunk secret_chunk2 = bc::to_chunk(secret2);
  bc::wallet::ec_private private_key2(secret_chunk2, bc::wallet::ec_private::mainnet_p2kh);
  bc::wallet::ec_public public_key2 = private_key2.to_public();

  std::vector<bc::wallet::ec_public> public_keys = {public_key1, public_key2};

  // Create a multisig redeem script
  bc::script redeem_script = bc::script::to_pay_multisig_pattern(2, public_keys);
  
  // Print the redeem script
  std::cout << "Redeem script: " << bc::encode_base16(redeem_script) << std::endl;

  return 0;
}

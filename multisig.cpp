#include <iostream>
#include <bitcoin/bitcoin.hpp>

int main() {
  // Public keys of the signers
  const std::vector<bc::ec_point> public_keys = {
    bc::base16_literal("02dcb21351db57ea9d872fa6bf52c85b317d6f540af6c7573b277a642b1e98dd84"),
    bc::base16_literal("026c3b128d7bfc8802c292fa7f87dab129539daaaf17d9f140dc7f098609a2d456"),
    bc::base16_literal("030b64c411ef91858b7d19c9df2e02e2f315ab01d39c4220c0a22a269f47c0f84d")
  };
  
  // Number of required signatures
  const uint8_t signatures_required = 2;
  
  // Create a script that requires the specified number of signatures from the listed public keys
  bc::script script = bc::script::to_pay_multisig_pattern(signatures_required, public_keys);

  // Generate the address from the script
  const bc::wallet::payment_address multisig_address = bc::wallet::payment_address(script, bc::wallet::payment_address::mainnet_p2sh);

  // Output the multisig address
  std::cout << "Multisig address: " << multisig_address.encoded() << std::endl;

  return 0;
}

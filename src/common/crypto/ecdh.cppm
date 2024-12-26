//
// Created by yizhou on 2024-12-25.
//

export module crypto.ecdh;

import standard.algorithm;
import standard.container;
import standard.iterator;
import cryptopp;
import spdlog;

namespace ecdh {

export auto calculate_shared(std::input_iterator auto public_key, std::input_iterator auto private_key) {
    log::log(log::level_enum::info, "Calculating shared key");
    crypto::ECDH<crypto::ECP>::Domain ecdh(crypto::secp192k1());
    crypto::SecByteBlock shared(ecdh.AgreedValueLength());
    ecdh.Agree(shared, reinterpret_cast<crypto::byte*>(private_key.data()), reinterpret_cast<crypto::byte*>(public_key.data()));
    std::vector<char> result(shared.size());
    std::copy_n(reinterpret_cast<char*>(shared.data()), shared.size(), result.data());
    return result;
}

}
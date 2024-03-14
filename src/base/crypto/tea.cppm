//
// Created by yizhou on 2024/2/16.
//

module;

#include <cryptopp/tea.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>

export module tea;

namespace crypto {
export auto encrypto(std::string_view key, std::string_view plain, std::string_view iv) {
    std::string cipher, sink {plain};
    CryptoPP::CBC_Mode<CryptoPP::TEA>::Encryption encryption;
    encryption.SetKeyWithIV(reinterpret_cast<const CryptoPP::byte *>(key.data()), key.size(), reinterpret_cast<const CryptoPP::byte *>(iv.data()));
    CryptoPP::StringSource source(cipher, true, new CryptoPP::StreamTransformationFilter(encryption, new CryptoPP::StringSink(sink)));
    return cipher;
}

export auto decrypto(std::string_view key, std::string_view cipher, std::string_view iv) {
    std::string plain, sink {cipher};
    CryptoPP::CBC_Mode<CryptoPP::TEA>::Decryption decryption;
    decryption.SetKeyWithIV(reinterpret_cast<const CryptoPP::byte *>(key.data()), key.size(), reinterpret_cast<const CryptoPP::byte *>(iv.data()));
    CryptoPP::StringSource source(plain, true, new CryptoPP::StreamTransformationFilter(decryption, new CryptoPP::StringSink(sink)));
    return plain;
}
}
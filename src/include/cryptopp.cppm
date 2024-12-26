//
// Created by yizhou on 2024-12-25.
//

module;

#include <cryptopp/cryptlib.h>
#include <cryptopp/eccrypto.h>
#include <cryptopp/oids.h>

export module cryptopp;

namespace crypto {

export using CryptoPP::ECDH;
export using CryptoPP::SecByteBlock;
export using CryptoPP::byte;
export using CryptoPP::OID;
export using CryptoPP::ECP;
export using CryptoPP::ASN1::secp192k1;


}
#include "../include/crypto_functions.h"

#include <cryptopp/osrng.h>
#include <limits.h>

#include <random>
#include <string>

void createRsaKeys(RSA::PublicKey &publicKey, RSA::PrivateKey &privateKey) {
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::InvertibleRSAFunction params;

    params.GenerateRandomWithKeySize(rng, RSA_KEY_LEN);

    publicKey = RSA::PublicKey(params);
    privateKey = RSA::PrivateKey(params);
}

int32_t getIntegerRand(void) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(INT32_MIN, INT32_MAX);
    return (int32_t) distribution(generator);
}

string signMessage(string message, RSA::PrivateKey privateKey) {
    string signature;
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::RSASSA_PKCS1v15_SHA_Signer signer(privateKey);

    CryptoPP::StringSource stringSource(
        message, true, new CryptoPP::SignerFilter(rng, signer, new CryptoPP::StringSink(signature)));
    return message + signature;
}


string encryptString(string message, RSA::PublicKey publicKey) {
    CryptoPP::AutoSeededRandomPool rng;
    string cipher;
    CryptoPP::RSAES_OAEP_SHA_Encryptor enc(publicKey);

    CryptoPP::StringSource stringSource(
        message, true, new CryptoPP::PK_EncryptorFilter(rng, enc, new CryptoPP::StringSink(cipher)));

    return cipher;
}

string decryptString(string cipher, RSA::PrivateKey privateKey) {
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::RSAES_OAEP_SHA_Decryptor dec(privateKey);
    string message;

    CryptoPP::StringSource ss2(cipher, true,
                               new CryptoPP::PK_DecryptorFilter(rng, dec, new CryptoPP::StringSink(message)));

    return message;
}

bool verifySign(string signed_message, RSA::PublicKey publicKey) {
    CryptoPP::RSASSA_PKCS1v15_SHA_Verifier verifier(publicKey);

    CryptoPP::StringSource ss2(signed_message, true,
                               new CryptoPP::SignatureVerificationFilter(
                                   verifier, NULL, CryptoPP::SignatureVerificationFilter::THROW_EXCEPTION));
    return true;
}
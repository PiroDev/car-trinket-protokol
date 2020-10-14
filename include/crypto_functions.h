#pragma once

#include <cryptopp/rsa.h>

#include <string>

#define RSA_KEY_LEN 1024

#define SIGN_LEN 128

using CryptoPP::RSA;
using std::string;

void createRsaKeys(CryptoPP::RSA::PublicKey &, CryptoPP::RSA::PrivateKey &);
int32_t getIntegerRand(void);
string signMessage(string, RSA::PrivateKey);
string encryptString(string, RSA::PublicKey);
string decryptString(string, RSA::PrivateKey);
bool verifySign(string, RSA::PublicKey);
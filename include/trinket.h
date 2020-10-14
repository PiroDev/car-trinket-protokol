#pragma once

#include <cryptopp/rsa.h>

#include <string>

using CryptoPP::RSA;
using std::string;

#ifndef TRINKET_ID_LEN
#define TRINKET_ID_LEN 64
#endif

class Trinket {
   private:
    RSA::PrivateKey privateKey;
    RSA::PublicKey publicKey;
    RSA::PublicKey carPublicKey;
    string id;

    inline RSA::PrivateKey getPrivateKey(void) { return privateKey; }

   public:
    Trinket(string);
    string generateHandshake(string);
    string processChallenge(string);
    void setCarPublicKey(RSA::PublicKey);

    inline string getId(void) { return id; }
    inline RSA::PublicKey getPublicKey(void) { return publicKey; }
    inline RSA::PublicKey getCarPublicKey(void) { return carPublicKey; }
};

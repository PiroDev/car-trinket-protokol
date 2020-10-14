#pragma once

#include <cryptopp/rsa.h>

#include <map>
#include <string>

using CryptoPP::RSA;
using std::map;
using std::string;

#ifndef TRINKET_ID_LEN
#define TRINKET_ID_LEN 64
#endif

class Car {
   private:
    RSA::PrivateKey privateKey;
    RSA::PublicKey publicKey;
    map<string, RSA::PublicKey> keysTable;
    string currentChallenge;
    void generateChallenge(void);
    bool verifyChallenge(string);

    inline RSA::PrivateKey getPrivateKey(void) { return privateKey; }
    inline string getCurrentChallenge(void) { return currentChallenge; }

   public:
    Car(map<string, RSA::PublicKey>);
    string processHandshake(string);
    void verifyResponse(string);
    bool isIdInKeysTable(string);
    RSA::PublicKey getKeyById(string);

    inline RSA::PublicKey getPublicKey(void) { return publicKey; }
};
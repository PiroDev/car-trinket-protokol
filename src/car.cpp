#include "car.h"

#include <assert.h>

#include "crypto_functions.h"

Car::Car(map<string, RSA::PublicKey> keys) {
    keysTable = keys;
    createRsaKeys(publicKey, privateKey);
    generateChallenge();
}

void Car::generateChallenge(void) { currentChallenge = std::to_string(getIntegerRand()); }

string Car::processHandshake(string handshakeData) {
    RSA::PublicKey trinketPublicKey = getKeyById(handshakeData.substr(0, TRINKET_ID_LEN));
    assert(verifySign(handshakeData, trinketPublicKey));

    return signMessage(encryptString(getCurrentChallenge(), trinketPublicKey), getPrivateKey());
}

void Car::verifyResponse(string responseData) {
    RSA::PublicKey trinketPublicKey = getKeyById(responseData.substr(0, TRINKET_ID_LEN));
    assert(verifySign(responseData, trinketPublicKey));

    string encryptedChallenge =
        decryptString(responseData.substr(TRINKET_ID_LEN, responseData.length() - TRINKET_ID_LEN - SIGN_LEN),
                      getPrivateKey());

    assert(verifyChallenge(encryptedChallenge));

    generateChallenge();
}

bool Car::verifyChallenge(string challenge) { return getCurrentChallenge() == challenge; }

RSA::PublicKey Car::getKeyById(string id) {
    assert(isIdInKeysTable(id));

    return keysTable.find(id)->second;
}

bool Car::isIdInKeysTable(string id) { return keysTable.find(id) != keysTable.end(); }

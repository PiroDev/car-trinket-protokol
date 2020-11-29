#include "trinket.h"

#include <assert.h>

#include "crypto_functions.h"

Trinket::Trinket(string trinketId) {
    id = trinketId;
    createRsaKeys(publicKey, privateKey);
}

void Trinket::setCarPublicKey(RSA::PublicKey carPubKey) {
    carPublicKey = carPubKey;
}

string Trinket::generateHandshake(string command) {
    return signMessage(getId() + command, getPrivateKey());
}

string Trinket::processChallenge(string challengeData) {
    assert(verifySign(challengeData, getCarPublicKey()));

    string cipher = challengeData.substr(0, challengeData.length() - SIGN_LEN);
    string response = decryptString(cipher, getPrivateKey());

    response = signMessage(getId() + encryptString(response, getCarPublicKey()), getPrivateKey());
    return response;
}

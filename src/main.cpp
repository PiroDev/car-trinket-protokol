#include <cryptopp/rsa.h>

#include <iostream>

#include "../include/car.h"
#include "../include/trinket.h"

using std::cout;
using std::endl;

int main(void) {
    Trinket trinket("cd2eb0837c9b4c962c22d2ff8b5441b7b45805887f051d39bf133b583baf6860");
    map<string, RSA::PublicKey> keysTable = { { trinket.getId(), trinket.getPublicKey() } };
    Car car(keysTable);

    trinket.setCarPublicKey(car.getPublicKey());

    cout << "______________" << endl;
    string command = "unlock";
    cout << "command " << command << endl;

    cout << "___________________________________" << endl;
    string handshakeData = trinket.generateHandshake(command);
    cout << "trinket->car send data (HANDSHAKE): " << endl << handshakeData << endl;

    cout << "___________________________________" << endl;
    string challengeData = car.processHandshake(handshakeData);
    cout << "car->trinket send data (CHALLENGE): " << endl << challengeData << endl;

    cout << "__________________________________" << endl;
    string responseData = trinket.processChallenge(challengeData);
    cout << "trinket->car send data (RESPONSE): " << endl << responseData << endl;

    cout << "______________________________" << endl;
    car.verifyResponse(responseData);
    cout << "command " << command << " status: success" << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string circularShiftEncrypt(string plaintext, int shift) {
    string encryptedText = "";

    for (char& c : plaintext) {

        if (isupper(c))
            encryptedText += char(int(c + shift - 65) % 26 + 65);

        else if (islower(c))
            encryptedText += char(int(c + shift - 97) % 26 + 97);

        else
            encryptedText += c;
    }

    return encryptedText;
}


string circularShiftDecrypt(string ciphertext, int shift) {
    string decryptedText = "";

    for (char& c : ciphertext) {

        if (isupper(c))
            decryptedText += char(int(c - shift - 65 + 26) % 26 + 65);

        else if (islower(c))
            decryptedText += char(int(c - shift - 97 + 26) % 26 + 97);
        else
            decryptedText += c;
    }

    return decryptedText;
}

int main() {
    string plaintext, ciphertext, decryptedText;
    int shift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter shift value: ";
    cin >> shift;

    ciphertext = circularShiftEncrypt(plaintext, shift);

    cout << "Encrypted text: " << ciphertext << endl;

    decryptedText = circularShiftDecrypt(ciphertext, shift);

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}

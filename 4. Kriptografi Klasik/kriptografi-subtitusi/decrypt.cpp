#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
    cout << "Ciphertext: \n\n";
    ifstream myfile;
    string word;
    myfile.open("../cipher/cipherteks3.txt");
    getline(myfile, word);

    // Print ciphertext to the screen
    cout << word << endl << endl;

    int k;
    cout << "Input key (k) = ";
    cin >> k;

    int len_26k = 1;
    int input = 26 * k;
    while (input / 10 >= 1) {
        input /= 10;
        len_26k++;
    }

    // Ciphertext numbers write to file
    int c[word.length()];
    for (int i = 0; i < word.length(); i++) {
        c[i] = word[i] - 'A';
    }

    ofstream myfile2;
    myfile2.open("../dekripsi/dekripsi1.txt");
    for (int i = 0; i < word.length(); i++) {
        myfile2 << c[i];
    }
    myfile2.close();

    // Partition to block size digit of 26*k write to file
    ifstream myfile3;
    string cip;
    myfile3.open("../dekripsi/dekripsi1.txt");
    getline(myfile3, cip);

    ofstream myfile4;
    myfile4.open("../dekripsi/dekripsi2.txt");
    int d[cip.length() / len_26k];

    for (int i = 0; i < cip.length() / len_26k; i++) {
        d[i] = 0;
        for (int j = 0; j < len_26k; j++) {
            d[i] += pow(10, len_26k - j - 1) * (cip[len_26k * i + j] - '0');
        }
        myfile4 << d[i] << " ";
    }
    myfile4.close();

    // Transform decryption to mod 26
    ofstream myfile5;
    myfile5.open("../dekripsi/dekripsi3.txt");
    int e[cip.length() / len_26k];

    for (int i = 0; i <= (cip.length() / len_26k); i++) {
        e[i] = d[i] % 26;
        myfile5 << e[i] << " ";
    }
    myfile5.close();

    // Transform to plainteks
    ofstream myfile6;
    myfile6.open("../hasil/hasil_akhir_dekripsi.txt");
    char num2alp[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    for (int i = 0; i < cip.length() / len_26k - 1; i++) {
        myfile6 << num2alp[e[i]];
    }
    myfile6.close();

    cout << "\nPlaintext files created";
    return 0;
}

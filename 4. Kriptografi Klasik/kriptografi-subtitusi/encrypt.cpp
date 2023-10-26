#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Plaintext: \n\n";
    ifstream myfile;
    string word;
    myfile.open("../hasil/plainteks.txt");

    getline(myfile, word);
    // Print Plain Text to Screen
    cout << word << endl << endl;

    int k;
    cout << "Input key (k) = ";
    cin >> k;

    int c[word.length()];
    for (int i = 0; i < word.length(); i++) {
        // srand(time(NULL));
        srand(12345);
        c[i] = ( (word[i]-65) + (rand() % k) * 26 ) % (26 * k);
    }

    // Ciphertext in number write to file
    ofstream myfile2;
    myfile2.open("../cipher/cipherteks1.txt");
    for(int j = 0; j <= word.length(); j++) {
        myfile2 << c[j];
    }
    myfile2.close();

    // Ciphertext in number same digit length write to file
    ofstream myfile3;
    myfile3.open("../cipher/cipherteks2.txt");

    int len_26k = 1, len_cj = 1;
    int input = 26 * k, input2;
    while (input / 10 >= 1) {
        input /= 10;
        len_26k++;
    }

    for(int j = 0; j <= word.length(); j++) {
        input2 = c[j];
        while (input2 / 10 > 0) {
            input2 /= 10;
            len_cj++;
        }
        
        for (int k = 1; k <= (len_26k - len_cj); k++) {
            myfile3 << 0;
        }

        myfile3 << c[j];
        len_cj = 1;
    }
    myfile3.close();

    // Ciphertext in letter write to file
    ifstream myfile4;
    string cip;
    myfile4.open("../cipher/cipherteks2.txt");
    
    getline(myfile4, cip);
    char num2alp[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    ofstream myfile5;
    myfile5.open("../cipher/cipherteks3.txt");

    for (int i = 0; i < cip.length(); i++) {
        if (cip[i] == 48 || cip[i] >= 51 || (cip[i] >= 50 && cip[i+1] >= 54)) {
            myfile5 << num2alp[cip[i] - 48];
        } else {
            if(cip[i] == 49 || (cip[i] >= 50 && cip[i+1] <= 53)) {
                myfile5 << num2alp[10 * (cip[i] - 48) + (cip[i+1] - 48)];
                i++;
            }
        }
    }
    
    myfile5.close();
    cout << "\nciphertext files created";
    
    return 0;
}
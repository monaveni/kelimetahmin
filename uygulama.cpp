#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    vector<string> words = { "elma", "armut", "çilek", "muz", "üzüm", "portakal", "şeftali" };

    srand(static_cast<unsigned int>(time(nullptr))); // Rastgele kelime seçmek için rastgele başlangıç ​​noktası

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        string randomWord = words[rand() % words.size()]; // Kelimeler arasından rastgele bir kelime seç

        int attempts = 6; // Tahmin hakkı
        string guessedWord(randomWord.length(), '_'); // Doğru tahmin edilen harfler
        vector<char> usedLetters; // Kullanılan harfler

        cout << "Kelime Tahmin Oyununa Hoş Geldiniz!" << endl;

        while (attempts > 0) {
            cout << "Kelime: " << guessedWord << endl;
            cout << "Kullanılan Harf: ";

            for (char letter : usedLetters) {
                cout << letter << " ";
            }

            cout << endl;
            cout << "Kalan Tahmin Hakkı: " << attempts << endl;

            char guess;
            cout << "Bir harf tahmin edin: ";
            cin >> guess;

            if (usedLetters.end() != find(usedLetters.begin(), usedLetters.end(), guess)) {
                cout << "Bu harfi zaten kullandınız." << endl;
                continue;
            }

            usedLetters.push_back(guess);

            size_t found = randomWord.find(guess);

            if (found != string::npos) {
                while (found != string::npos) {
                    guessedWord[found] = guess;
                    found = randomWord.find(guess, found + 1);
                }

                if (randomWord == guessedWord) {
                    cout << "Tebrikler, kelimeyi doğru tahmin ettiniz: " << randomWord << endl;
                    break;
                }
            }
            else {
                cout << "Üzgünüm, yanlış tahmin. Tekrar deneyin." << endl;
                attempts--;
            }
        }

        if (attempts == 0) {
            cout << "Tahmin hakkınız bitti. Doğru kelime: " << randomWord << endl;
        }

        cout << "Tekrar oynamak istiyor musunuz? (y/n): ";
        cin >> playAgain;
    }

    cout << "Oyunu tamamladınız. İyi günler!" << endl;

    return 0;
}

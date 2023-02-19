#include <iostream>
#include <fstream>
using namespace std;

class Weapon {
private:
    int shotRange;
    float caliber;
    int numBullet;
    int maxNumBullet;
public:
    Weapon() {
        this->shotRange = 0;
        this->caliber = 0;
        this->numBullet = 0;
        this->maxNumBullet = 0;
    }
    Weapon(int shotRange, int caliber, int numBullet, int maxNumBullet)
        : shotRange(shotRange), caliber(caliber), numBullet(numBullet),
        maxNumBullet(maxNumBullet) {

    }

    void Show() const {
        cout << "\n_______ WEAPON ________" << endl;
        cout << "Shot range: " << shotRange << endl;
        cout << "Caliber bullets: " << caliber << endl;
        cout << "Number bullets: " << numBullet << endl;
        cout << "Max number bullets in magazine: " << maxNumBullet << endl;
    }

    void Initialize(int range, float caliber, int maxSize) {
        this->shotRange = range;
        this->caliber = caliber;
        this->maxNumBullet = maxSize;
    }

    bool Shot() {
        if (numBullet <= 0) {
            cout << "\nNo bullets!!\n";
            return false;
        }
        else {
            --numBullet;
            return true;
        }
    }

    void Recharge() {
        if (numBullet == maxNumBullet) {
            cout << "\nMagazine is full!!\n";
        }
        else {
            numBullet = maxNumBullet;
        }
    }

    void Save() {
        ofstream file;
        file.open("file.txt");
        file << "\n_______ WEAPON ________" << endl;
        file << "Shot range: " << shotRange << endl;
        file << "Caliber bullets: " << caliber << endl;
        file << "Number bullets: " << numBullet << endl;
        file << "Max number bullets in magazine: " << maxNumBullet << endl;

    }

};

int main()
{
    Weapon ww(909, 5.7, 19, 32);
    ww.Show();
    
    ww.Recharge();
    ww.Show();

    ww.Shot();
    ww.Show();

    ww.Shot();
    ww.Show();

    ww.Recharge();
    ww.Show();


    ww.Save();

}
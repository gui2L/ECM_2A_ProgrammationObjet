#ifndef HEURE_H
#define HEURE_H

class Heure{
    private:
        int heures;
        int minutes;
        static bool checkHeure(int h, int m) {
            if (h < 0 || h > 23) return false;
            if (m < 0 || m > 59) return false;
            return true;
        }

    public:
        Heure(int h = 0, int min = 0);
        ~Heure();
        void affiche();

        int getHeures();
        int getMinutes();

        void setHeures(int h);
        void setMinutes(int min);

        static bool public_checkHeure(int heures, int minutes){
            return checkHeure(heures, minutes);
        }
        bool estEgale(const Heure &h);

};
#endif
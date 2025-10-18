#ifndef HEURE_H
#define HEURE_H

class Heure{
    private:
        int heures;
        int minutes;
    public:
        Heure(int h = 0, int min = 0);
        ~Heure();
        void affiche();

        int getHeures();
        int getMinutes();

        void setHeures(int h);
        void setMinutes(int min);

        bool estEgale(const Heure &h);

};
#endif
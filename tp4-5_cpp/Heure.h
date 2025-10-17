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

};
#endif
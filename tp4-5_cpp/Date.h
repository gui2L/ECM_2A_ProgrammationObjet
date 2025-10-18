#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int jour;
        int mois;
        int annee;

        static bool checkDate(int j, int m, int a){
            if (a < 2000 || a > 2050 || m < 1 || m > 12 || j < 1)
                return false;

            int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            bool bissextile = (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
            if (bissextile) joursParMois[1] = 29;

            return j <= joursParMois[m - 1];
        }

    public:
        Date(int j = 1, int m = 1, int a = 2000);
        Date(const Date &d);
        ~Date();
        void affiche();

        int getJour();
        int getMois();
        int getAnnee();

        static bool public_checkDate(int jour, int mois, int annee){
            return checkDate(jour, mois, annee);
        }

        void setJour(int j);
        void setMois(int m);
        void setAnnee(int a);

        bool estEgale(const Date &d);
        bool estSuperieureA(const Date &d) const;

};

#endif
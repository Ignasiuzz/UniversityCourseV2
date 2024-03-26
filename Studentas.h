#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "VectorIncludes.h"

class Studentas {
// realizacija
private:
    std::string Vardas_;
    std::string Pavarde_;
    double egzaminas_;
    std::vector<double> namudarbas_;

    static double Vidurkis(const std::vector<double>& namudarbas);
    static double Mediana(const std::vector<double>& namudarbas);
// interfeisas
public:
    Studentas() : egzaminas_(0) { }  // default konstruktorius
    Studentas(std::istream& is);

    std::string Vardas() const { return Vardas_; }
    std::string Pavarde() const { return Pavarde_; }
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setEgzaminas(double egzaminas);
    void setNamudarbas(const std::vector<double>& namudarbas);
    std::istream& readStudent(std::istream&);  // set'eriai

    friend double GalutinisVid(const Studentas& duom);
    friend double GalutinisMed(const Studentas& duom);

    ~Studentas();
};

// bool compare(const Studentas&, const Studentas&);
// bool comparePagalPavarde(const Studentas&, const Studentas&);
// bool comparePagalEgza(const Studentas&, const Studentas&);
#endif
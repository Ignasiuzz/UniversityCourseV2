#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "VectorIncludes.h"

class Studentas {
private:
// realizacija
    std::string Vardas_;
    std::string Pavarde_;
    double egzaminas_;
    std::vector<double> namudarbas_;

    static double Vidurkis(const std::vector<double>& namudarbas);
    static double Mediana(const std::vector<double>& namudarbas);
public:
// interfeisas
    Studentas() : egzaminas_(0), namudarbas_({}) {}  // default konstruktorius
    Studentas(const std::string& vardas, const std::string& pavarde, double egzaminas, const std::vector<double>& namudarbas) : Vardas_(vardas), Pavarde_(pavarde), egzaminas_(egzaminas), namudarbas_(namudarbas) {}
    Studentas(std::istream& is);

    // Rule of Five
    ~Studentas();
    Studentas(const Studentas& other); // Copy constructor
    Studentas(Studentas&& other) noexcept; // Move constructor
    Studentas& operator=(const Studentas& other); // Copy assignment operator
    Studentas& operator=(Studentas&& other) noexcept; // Move assignment operator
    
    std::string Vardas() const { return Vardas_; }
    std::string Pavarde() const { return Pavarde_; }
    double Egzaminas() const { return egzaminas_; }
    std::vector<double> Namudarbas() const { return namudarbas_; }
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setEgzaminas(double egzaminas);
    void setNamudarbas(const std::vector<double>& namudarbas);
    std::istream& readStudent(std::istream&);  // set'eriai

    friend double GalutinisVid(const Studentas& duom);
    friend double GalutinisMed(const Studentas& duom);
};
#endif
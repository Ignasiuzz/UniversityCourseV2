// Studentas.cpp
#include "Studentas.h"

// konstruktoriaus realizacija
Studentas::Studentas(std::istream& is) { 
// kreipiasi į Studentas::readStudent;
    readStudent(is);  
}

// Duomenu manual irasymas
void Studentas::setVardas(const std::string& vardas) {
    Vardas_ = vardas;
}
void Studentas::setPavarde(const std::string& pavarde) {
    Pavarde_ = pavarde;
}
void Studentas::setEgzaminas(double egzaminas) {
    egzaminas_ = egzaminas;
}
void Studentas::setNamudarbas(const std::vector<double>& namudarbas) {
    namudarbas_ = namudarbas;
}

// Galutinio vidurkio realizacija
double Studentas::Vidurkis(const std::vector<double>& namudarbas) {
    double sum = 0;
    for (double grade : namudarbas) {
        sum += grade;
    }
    return sum / namudarbas.size();
}
double Studentas::Mediana(const std::vector<double>& namudarbas) {
    std::vector<double> sortedVector = namudarbas;
    std::sort(sortedVector.begin(), sortedVector.end());

    if (sortedVector.size() % 2 == 0)
        return (sortedVector[sortedVector.size() / 2 - 1] + sortedVector[sortedVector.size() / 2]) / 2.0;
    else
        return sortedVector[sortedVector.size() / 2];
}
double GalutinisVid(const Studentas& duom) {
    double ndAverage = Studentas::Vidurkis(duom.namudarbas_);
    return 0.4 * ndAverage + 0.6 * duom.egzaminas_;
}
double GalutinisMed(const Studentas& duom) {
    double ndMedian = Studentas::Mediana(duom.namudarbas_);
    return 0.4 * ndMedian + 0.6 * duom.egzaminas_;
}

// Skaitymo is failo realizacija
std::istream& Studentas::readStudent(std::istream& is) {
    is >> Vardas_ >> Pavarde_;

    namudarbas_.clear();

    double grade;
    while (is >> grade) {
        namudarbas_.push_back(grade);
    }

    egzaminas_ = namudarbas_.back();
    namudarbas_.pop_back();
    return is;
}

Studentas::~Studentas() {
}

/* Rule of Five */
// Copy constructor
Studentas::Studentas(const Studentas& other)
    : Vardas_(other.Vardas_), Pavarde_(other.Pavarde_), egzaminas_(other.egzaminas_), namudarbas_(other.namudarbas_) {}

// Move constructor
Studentas::Studentas(Studentas&& other) noexcept
    : Vardas_(std::move(other.Vardas_)), Pavarde_(std::move(other.Pavarde_)), egzaminas_(std::move(other.egzaminas_)), namudarbas_(std::move(other.namudarbas_)) {}

// Copy assignment
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        Vardas_ = other.Vardas_;
        Pavarde_ = other.Pavarde_;
        namudarbas_ = other.namudarbas_;
        egzaminas_ = other.egzaminas_;
    }
    return *this;
}

// Move assignment
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        Vardas_ = std::move(other.Vardas_);
        Pavarde_ = std::move(other.Pavarde_);
        namudarbas_ = std::move(other.namudarbas_);
        egzaminas_ = std::move(other.egzaminas_);
    }
    return *this;
}
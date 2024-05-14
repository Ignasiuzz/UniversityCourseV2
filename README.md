# UniversityCourseV2
Objektinio programavimo antroji užduotis

# Releases
V1.2 - Realizuoti visi metodai atitinkantys penkių metodų taisyklę.
Pridėtas aprašas apie perdengtus metodus t.y. duomenų įvestis (rankiniu būdu, automatiniu, iš failo), išvestis - į ekraną, į failą.  

v1.5 - Realizuota abstrakti klasė Žmogus.
Studento klasė yra išvestinė iš Žmogaus ir palaiko 1.2 versijoje realizuotą penkių metodų taisyklę.

v2.0 - Sukurkita dokumentacija panaudojant Doxygen. Realizuoti Unit Testai naudojant Google Tests. Galutine programos versija su instrukcija.

# Instaliavimas  
1) Susiinstaliuokite c++ compileri sekdami instrukcijas šiame puslapyje https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/

2) Susiinstaliuokite cmake, kuris bus reikalingas buildinant programa. Puslapyje https://cmake.org/download/ parsisiuskite Windows x64 ZIP ir isskleiskite ji jusu pasirinktoje vietoje. Tuomet nueikite i cmake aplanka ir nukopijuokite bin aplanko kelia i Environment veriables PATH.

3) Atsidarykite cmd ir naudodami cd nunaviguokite i folderi, i kuri parsisiuntete programa. Tada i terminala iveskite sias komandas:

mkdir build  
cd build  
cmake -G "Unix Makefiles" ..  
cmake --build .  
copy Program.exe ..  
Programos paleidziama exe faila rasite programos folderio viduje.  

# Spartos analize  
## Be oprimizatoriaus
100.000 studentų  
Struct. Student sorting to two groups took 0.0304037 seconds.  
Class. Student sorting to two groups took 0.0443925 seconds.  
1.000.000 studentų   
Struct. Student sorting to two groups took 0.319136 seconds.  
Class. Student sorting to two groups took 0.600509 seconds.  

## Kompiliatoriaus optimizavimo lygiai 
### 100.000 studentų
| Optimization | Struct | Class | File size Struct | File size Class |
| :---: | :---: | :---: | :---: | :---: |
| O1 | 0.0117796 seconds. | 0.0195176 seconds. | 262 KB | 254 KB |
| O2 | 0.0114957 seconds. | 0.0205766 seconds. | 266 KB | 256 KB |
| O3 | 0.0108180 seconds. | 0.0202935 seconds. | 264 KB | 259 KB |


### 1.000.000 studentų
| Optimization | Struct | Class | File size Struct | File size Class |
| :---: | :---: | :---: | :---: | :---: | 
| O1 | 0.127661 seconds. | 0.345793 seconds. |262 KB| 254 KB |
| O2 | 0.115778 seconds. | 0.339243 seconds. |266 KB| 256 KB | 
| O3 | 0.115472 seconds. | 0.333918 seconds. |264 KB| 259 KB |

# Studentas Class
## Class Structure  
`Zmogus` abstrakčioje klasėje yra šie nariai:  
- `Vardas_`: String tipo studento vardas.  
- `Pavarde_`: String tipo studento pavarde.

`Studentas` klasėje yra šie nariai:  
- `egzaminas_`: Double tipo egzamino pažymys.  
- `namudarbas_`: Double vectoriaus tipo namų darbų pažymiai.  

## Data input

Studento duomenų (Vardas, Pavarde, Namu darbas, Egzaminas) rankinis įvedimas:  
`.setVardas();`  
`.setPavarde();`  
`.setNamudarbas();`  
`.setEgzaminas();`  

    Studentas data;
    data.setVardas("John");
    data.setPavarde("Doe");
    data.setNamudarbas({8, 6, 9, 5});
    data.setEgzaminas(7);

Studento duomenų (Vardas, Pavarde, Namu darbas, Egzaminas) programoje įvedimo pvz:  

    Studentas data;
    cout << "Iveskite studento varda: ";
    cin >> temp;
    data.setVardas(temp);

    cout << "Iveskite studento pavarde: ";
    cin >> temp;
    data.setPavarde(temp);

    vector<double> namudarbas;
    int NumberOfInputs = 5;
    for (int i = 0; i < NumberOfInputs; i++) {
        cout << "Iveskite studento namu darbo rezultata: ";
        cin >> temp;
        namudarbas.push_back(temp);
    }
    duom.setNamudarbas(namudarbas);

    cout << "Iveskite studento egzamino rezultata: ";
    cin >> temp;
    data.setEgzaminas(temp);
Studento duomenų (Vardas, Pavarde, Namu darbas, Egzaminas) is failo įvedimas pagal formata kuris pateiktas failuose pavyzdys. Pvz. 1000_GeneratedStudents.txt:  

    vector<Studentas> student;
    ifstream inputFile("1000_GeneratedStudents.txt");

    string line;
    getline(inputFile, line); // Naikinama pirma header eilute

    // Skaitoma ir apdorojama visa eilute
    while (getline(inputFile, line)) {
        Studentas duom;
        istringstream iss(line);
        duom.readStudent(iss);
        student.push_back(duom);
    }

## Data output
Studento duomenų (Vardas, Pavarde, Namu darbas, Egzaminas, GalutinisMed, GalutinisVid) išvedimas:   
`.Vardas();`  
`.Pavarde();`  
`.Namudarbas();`  
`.Egzaminas();`  
`GalutinisMed();`  
`GalutinisVid();`  

    Studentas data;
    cout << "Studento vardas " << data.Vardas() << endl;
    cout << "Studento pavarde " << data.Pavarde() << endl;
    cout << "Studento pazymiai ";
    for (double grade : data.Namudarbas()) {
        std::cout << grade << " ";
    }
    cout << "Studento egzamino rezultatas " << data.Egzaminas() << endl;
    cout << "Galutinis vidurkis naudojant mediana " << GalutinisMed(data);
    cout << "Galutinis vidurkis paprastu budu " << GalutinisVid(data);
## Usage

Norint naudotis `Studentas` klase, turite atsisiųsti failus `Studentas.h` `Studentas.cpp` ir `Zmogus.h`. Savo kode turite inlcudinti `Studentas.h`.

    #include "Studentas.h"


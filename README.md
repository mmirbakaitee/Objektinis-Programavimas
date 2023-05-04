# Objektinis-Programavimas

Sistemos parametrai:

     CPU: 11th Gen Intel(R) Core(TM) i5-11400H @ 2.70GHz   2.69 GHz
     RAM: 8GB
     SSD: 500 GB

---------------------V.0.1 PAPILDYMAI--------------------------------

Programa atlika ir su C masyvu,ir su std::vector konteineriu:
1) Realizuota programa, kuri nuskaito vartotoju ivedamus duomenis (studento vardas, pavarde, namu darbu ir egzamino rezultatas).
2) Baigus duomenu ivedima suskaiciuocamas galutinis vidurkis, mediana.

---------------------V.0.2 PAPILDYMAI--------------------------------

1) Prideta funkcija scan, kuri nuskaito faila. 
2) Apskaiciuojami studentu is failo vidurkiai ir medianos pagal formule. 
3) Rezultatai surikiuojami pagal varda.

---------------------V.0.3 PAPILDYMAI--------------------------------

1) Scan funkcijoje (nuskaito duomenu faila) implementuotas isimciu valdymas. 
2) Programa isskaidyta i kelis *.cpp (main funkcijos, funkciju deklaracijos + strukturos) ir i kelis *.h (bibliotekos, funkciju) failus.

---------------------V.0.4 PAPILDYMAI--------------------------------

1) Papildyta main funkcija. Suteikiama vartotojui daugiau galimybiu (galimas failu generavimas, perejimas tarp pasirinkimu, darbo uzbaigimas po darbo su txt failais).
2) Pridetos kompleksines printPGtxt, printtxt funkcijos, kurios generuoja (jei reikia), nuskaito bei formuoja txt failus pagal reikalavimus. Sugeneruojamas studentu visu pazymiu failas, bendras studentu galutiniu pazymiu failas. Tuomet studentu isrusiuojami pagal nurodytas salygas ir jie su galutiniais rezultatais irasomi i atitinkamai skirtingus txt failus.
3) Implementuotas visos programos, failo sukurimo, failo nuskaitymo, failo rusiavimo, isrusiuotu studentu irasymo i atitinkamus txt failus trukmes skaiciavimas.
4) Atlikta skaiciavimu analize su generuojamais ir jau sugeneruotais failais (galima rasti v.04 release)

a) DARBAS SU GENERUOJAMAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo sukurimas     | 0.000637   | 0.000508  | 0.000491 | 0.000559 | 0.00058   |
|  Failo nuskaitymas   | 0.021593   | 0.170191  | 1.8625   | 18.0044  | 227.713   |
|  Studentu rusiavimas | 0.003387   | 0.041065  | 0.436892 | 4.3394   | 341.286   |
|  KIETIAKU irasymas    | 0.002521   | 0.024415  | 0.284341 | 2.58672  | 48.2718  |
|  VARGUOLIU irasymas  | 0.001732   | 0.016837  | 0.190583 | 1.78405  | 28.1771   |
|  Bendras laikas      | 12.883     | 10.6924   | 20.4578  | 70.7247  | 1207.23   |

b) DARBAS SU SUGENERUOTAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo nuskaitymas   | 0.018224   | 0.283451  | 2.64144  | 23.4728  | 256.888   |
|  Studentu rusiavimas | 0.003371   | 0.069602  | 0.586354 | 5.70116  | 253.093   |
|  KIETIAKU irasymas    | 0.002388   | 0.033028  | 0.350438 | 3.37797  | 42.5484  |
|  VARGUOLIU irasymas  | 0.001714   | 0.040592  | 0.281979 | 2.36976  | 25.7387   |
|  Bendras laikas      | 5.19551    | 8.63683   | 15.3479  | 62.9997  | 926.779   |

---------------------V.0.5 PAPILDYMAI--------------------------------

1) Sukurtos trys programos naudojant skirtingo tipo konteinerius (vector, deque, list).
2) Ten, kur reikia (programoje su list tipo konteineriu), atnaujintos sort funkcijos, pakeista medianos skaiciavimo funkcija.
3) Atliekama analize: lyginame, kiek kievieno konteinerio tipo programa trunka nuskaityti txt faila, isrusiuoti pagal vidurki, isskirstyti pagal dvi grupes.
4) Analizei neaktualus laiko matavimai nuimti.
   
ANALIZE SU JAU SUGENERUOTAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa (VECTOR):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.017201 | 0.135471 | 1.16704  | 11.7178 | 141.443 |
| Rūsiavimas                 | 0.00574  | 0.069801 | 0.641486 | 6.9062  | 98.8297 |
| Skirstymas į dvi grupes    | 0.003488 | 0.057485 | 0.561964 | 4.61347 | 422.128 |
| Bendras laikas             | 0.026429 | 0.262757 | 2.37049  | 23.2375 | 662.401 | 

Laikas sekundėmis, kurį užtruko programa (DEQUE):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.022373 | 0.179341 | 1.75345  | 17.6518 | 195.584  |
| Rūsiavimas                 | 0.008568 | 0.075929 | 0.747798 | 10.2411 | 114.12   |
| Skirstymas į dvi grupes    | 0.002596 | 0.025294 | 0.281616 | 3.48125 | 377.355  |
| Bendras laikas             | 0.033537 | 0.280564 | 2.78287  | 31.3741 | 687.059  | 

Laikas sekundėmis, kurį užtruko programa (LIST):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Failo nuskaitymas          | 0.016    | 0.163196 | 1.46236  | 14.84    | 160.417 |
| Rūsiavimas                 | 0.000175 | 0.003546 | 0.044946 | 0.804268 | 20.0921 |
| Skirstymas į dvi grupes    | 0.001894 | 0.021843 | 0.245001 | 2.74138  | 1402.82 |
| Bendras laikas             | 0.018069 | 0.188585 | 1.7523   | 18.3856  | 1583.33 | 

Greiciausiai veikia list'ai, o vector'iai ir deque'ai panasiai, isskyrus su 10000000, tuomet vector'iai veikia greiciausiai.

---------------------V.1.0 PAPILDYMAI--------------------------------

1) Implementuotas 2-osios strategijos studentu skirstymas (sukuriamas tik vienas naujas vektor'ius, o is pagr. vektor'iaus istrinama neaktualus duomenis)
2) Implementuotas 2-osios strategijos studentu duomenu irasymas (irasome likusius duomenis is master vector'iaus ir varguoliu vector duomenis)
3) Suteikta vartotojui galimybe pasirinkti, kokia strategija naudoti: naujaja ar senaja.
4) Skirstymo pagreitinimui panaudoti std::erase bei std::partition algoritmai.

ANALIZE SU JAU SUGENERUOTAIS FAILAIS (2-oji strategija (1-aja galite rasti V.0.5 PAPILDYMO aprasyme))

a) Laikas sekundėmis, kurį užtruko programa (VECTOR std::erase):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.006263 | 0.066761 | 4.339465 | 282.0652 | --dideli sk-- |
| Skirstymas į dvi grupes    | 0.029743 | 2.72006  | 176.8039 | 5304.117 | --dideli sk-- |
| Bendras laikas             | 0.036006 | 2.78682  | 181.1433 | 6340.016 | --dideli sk-- | 

b) Laikas sekundėmis, kurį užtruko programa (VECTOR std::partition):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.00582  | 0.064008 | 0.604973 | 9.44182 | 151.6273 |
| Skirstymas į dvi grupes    | 0.002003 | 0.017828 | 0.18182  | 1.99382 | 19.9382  |
| Bendras laikas             | 0.007967 | 0.078294 | 0.779234 | 11.4356 | 114.356  | 

TASK MANAGER STATS (atmintis su 1000000):

          1 strategija: 71%
          2 strategija: 64%

Laikas sekundėmis, kurį užtruko programa (DEQUE):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.007274 | 0.076244 | 0.71878  | 7.83325 | 78.3325 |
| Skirstymas į dvi grupes    | 0.002376 | 0.020917 | 0.217998 | 2.20474 | 22.0474 |
| Bendras laikas             | 0.00965  | 0.097161 | 0.936778 | 10.038  | 100.38  | 

TASK MANAGER STATS (atmintis su 1000000):

          1 strategija: 74%
          2 strategija: 63%

Laikas sekundėmis, kurį užtruko programa (LIST):

|   | 1000  | 10000  | 100000  | 1000000  | 10000000 |
|---|---|---|---|---|---|
| Rūsiavimas                 | 0.000175 | 0.002379 | 0.042083 | 0.698188 | 9.774632 |
| Skirstymas į dvi grupes    | 0.002242 | 0.025324 | 0.251771 | 2.64195  | 26.4195  |
| Bendras laikas             | 0.002417 | 0.027703 | 0.293854 | 3.34014  | 33.4014  | 

TASK MANAGER STATS (atmintis su 1000000):

          1 strategija: 81%
          2 strategija: 75%
          
          
NAUDOJIMOSI INSTRUKCIJA:

        1. Parsisiųskite šiuos failus:
                a) final.v.1.0.vector.cpp, final.v.1.0.deque.cpp, final.v.1.0.list.cpp
                b) vsourceV.cpp, vsourceD.cpp, vsourceL.cpp
                c) vheaderisV.h, vheaderisD.h, vheaderisL.h
                d) studentlib.h, kursiokai.txt, CMakeLists.txt
            2. Sudėkite juos į vieną sukurtą folderį (pareadaguokite CMakeLists.txt faile projekto pavadinimą pagal sukurto aplanko pavadinimą).
            3. Build'inkite CMakeLists.txt
            4. Terminale build/<paleidziamojofailopavadinimas>.exe


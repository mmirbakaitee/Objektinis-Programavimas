# Objektinis-Programavimas
Scan funkcijoje (nuskaito duomenu faila) implementuotas isimciu valdymas. 
Programa isskaidyta i kelis *.cpp (main funkcijos, funkciju deklaracijos + strukturos) ir i kelis *.h (bibliotekos, funkciju) failus. 

---------------------papildymai--------------------------------

1) Papildyta main funkcija. Suteikiama vartotojui daugiau galimybiu (galimas failu generavimas, perejimas tarp pasirinkimu, darbo uzbaigimas po darbo su txt failais).
2) Pridetos kompleksines printPGtxt, printtxt funkcijos, kurios generuoja (jei reikia), nuskaito bei formuoja txt failus pagal reikalavimus. Sugeneruojamas studentu visu pazymiu failas, bendras studentu galutiniu pazymiu failas. Tuomet studentu isrusiuojami pagal nurodytas salygas ir jie su galutiniais rezultatais irasomi i atitinkamai skirtingus txt failus.
3) Implementuotas visos programos, failo sukurimo, failo nuskaitymo, failo rusiavimo, isrusiuotu studentu irasymo i atitinkamus txt failus trukmes skaiciavimas.

---------------------SPARTOS ANALIZE---------------------------

a) DARBAS SU GENERUOJAMAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo sukurimas     | 0.000637   | 0.000508  | 0.000491 | 0.000559 | 0.00058   |
|  Failo nuskaitymas   | 0.021593   | 0.170191  | 1.8625   | 18.0044  | 227.713   |
|  Studentu rusiavimas | 0.003387   | 0.041065  | 0.436892 | 4.3394   | 341.286   |
|  KIETIAKU irasymas    | 0.002521   | 0.024415  | 0.284341 | 2.58672  | 48.2718   |
|  VARGUOLIU irasymas  | 0.001732   | 0.016837  | 0.190583 | 1.78405  | 28.1771   |
|  Bendras laikas      | 12.883     | 10.6924   | 20.4578  | 70.7247  | 1207.23   |

b) DARBAS SU SUGENERUOTAIS FAILAIS 

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus:
|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|  Failo nuskaitymas   | 0.018224   | 0.283451  | 2.64144  | 23.4728  | 256.888   |
|  Studentu rusiavimas | 0.003371   | 0.069602  | 0.586354 | 5.70116  | 253.093   |
|  KIETIAKU irasymas    | 0.002388   | 0.033028  | 0.350438 | 3.37797  | 42.5484   |
|  VARGUOLIU irasymas  | 0.001714   | 0.040592  | 0.281979 | 2.36976  | 25.7387   |
|  Bendras laikas      | 5.19551    | 8.63683   | 15.3479  | 62.9997  | 926.779   |

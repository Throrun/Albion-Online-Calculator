# Menu 

1. [Wyświetl liste przedmiotów](#lista-przedmiotów)
2. [Dodaj cene przedmiotu](#edytuj-cene-przedmiotu)
3. [Pobierz ceny z Internetu](#pobierz-ceny-z-internetu)
4. [Kalkulator](#kalkulator)
5. Wyjscie z aplikacji

## Opis funkcji menu

### Lista Przedmiotów
W tej funkcji wyświelana jest lista wszyskich przedmiotów wraz z cenami w odpowiednich miastach. Przedmioty sortowane są po dacie dodania ich do bazy danych.

![image](https://github.com/Throrun/Albion-Online-Calculator/assets/98560554/4a8b9c7e-a7f6-4d50-b825-4db014c2ca91)


### Dodaj/Edytuj własny przedmiot
W tej funkcji zadajemy odpowiednie pytania, które określają te wartości potrzebne do dodania/edytowania przedmiotu:
+ Nazwa
+ Tier
Jeżeli chcemy dodać jeszcze ceny do miast to:
+ Miasto
+ Cena

Po prawidłowym dodaniu przedmiotu do bazy danych aplikacja wyświetla komunikat, że udało się. 

Uwaga: Cena musi być większa od 0 i być liczbą całkowitą!

### Pobierz ceny z Internetu
Ta funkcja będzie pobierała ceny z internetu. A dokładniej będzie generowała zapytanie do [Albion online data project](https://www.albion-online-data.com/) , a następnie całość będzie zapisywana do bazy danych.

### Kalkulator
Przechodzimy do menu kalkulatora w którym możemy obliczyć najbardziej opłacalną wymianę według podanych wartości:
+ Item
+ Miasto, w którym kupujemy
i w wyniku otrzymujemy:
+ Miasto, w którym najbardziej opłacalna jest aktualnie sprzedaż
+ procentowy zysk przy takiej wymianie

![image](https://github.com/Throrun/Albion-Online-Calculator/assets/98560554/b11e113b-349c-42fe-b861-6aa56a996d31)

Uwaga: kalkulator domyślnie nie powinien wyświetlać wymian na któych jest się stratnym

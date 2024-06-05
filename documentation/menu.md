# Menu 

1. [Wyświetl liste przedmiotów](###lista-przedmiotów)
2. [Dodaj/Edytuj cene przedmiotu](###dodaj/edytuj-cene-przedmiotu)
3. [Pobierz ceny z Internetu](###pobierz-ceny-z-internetu)
4. [Kalkulator](###kalkulator)
5. Wyjscie z aplikacji

## Opis funkcji menu

### Lista Przedmiotów
W tej funkcji wyświelana jest lista wszyskich przedmiotów przedmiotów wraz z cenami i ostatnią datą dodania cenu do przedmiotu wraz z miastem do któym jest przypisane domyślnie sortujemy po przedmiocie potem po Tierze przykład listy:

![Alt text](img\Item_list.png)

### Dodaj/Edytuj cene przedmiotu
W tej funkcji zadajemy odpowiednie pytania, które określają te wartości tych punktów:
+ miasto
+ Przedmiot
+ [Tier](/Item.md/tier)
+ Cenę

następnie wyświetlamy pojedynczy rekord który został dodany np.\
Sword Carleon 250k

Uwaga cena nie może być ujemna

#### Wprowadzanie Ceny
Cenę będzie można wprowadzić na 2 sposoby podając dokładną liczbę np. (250345, 250 345) lub zaokrąglić ją do tysięcy np. (250k)

### Pobierz ceny z Internetu
Ta funkcja będzie pobierała ceny z internetu na podstawie takich informacji:
+ Miasto
+ Tier np. (4.1, 5.3, 6.4)
+ Rodzaj przedmiotu

na podstawie tych informacji będzie generowane zapytanie do [Albion online data project](https://www.albion-online-data.com/) a następnie całość będzie zapisywana do bazy danych

### Kalkulator
Przechodzimy do menu kalkulatora w którym możemy obliczyć następujące rzeczy:
+ najbardziej opłacalna wymiana według wzoru [Item] [Tier] [Miasto_1] -> [Miasto_2] [zarobek w %] [cena inwestycji]

![Alt text](img\Calculator_best_trades.png)

Uwaga kalkulkator musi uwzględniać to że na Black Markecie nie da się kupować przedmiotów\
Uwaga kalkulator domyślnie nie powinien wyświetlać wymian na któych jest się stratnym
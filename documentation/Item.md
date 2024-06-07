# Przedmiot
Przedmiot to obiekt, który reprezentuje Przedmioty w grze Albion Online\
### Stuktura obiektu 
id - Unikalny indetyfikator przedmiotu\
name - Nazwa przedmiotu w grze\
tier - Liczba złożona z 2 części [tier].[enchant] np. 5.3 lub 6.1 tier może być liczbą od 1 do 8, enchant może być liczbą od 0 do 4 z uwagą że enchant jest równy 0 dla tierów mniejszych od 4.\
mapa cen i miast gdzie kluczem będzie miasto([Enum miasto](#enum-miasto)) a cena ceną w danym mieście



#### Enum Miasto
miasto może przyjmować 8 stanów:
+ Martlock
+ Thetfort
+ Fort Sterling
+ Lymhust
+ Bridgewatch
+ Caerleon
+ Black Market
+ Breclilien
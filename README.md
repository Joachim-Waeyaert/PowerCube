# Arduino remake of the power cube 
 
Dit project is gebaseerd op PowerKube, maar staat volledig los van PowerKube.

PowerKube is een commerciële boksmachine die krachtmetingen doet bij slagen. De producten van PowerKube zijn eerder duur, daarom werd voor dit project gekozen om een soortgelijk systeem low-budget na te bouwen met Arduino.

## Inleiding

Voor het vak *Opkomende Technologieën* is een boksmachine gemaakt die de **snelheid** en de **kracht** van een vuistslag meet. Het project maakt gebruik van sensoren en een Arduino om gegevens te verzamelen en weer te geven.

## Doel

Het doel van het project is het bouwen van een boksmachine die twee zaken meet:

-Hoe snel een vuist beweegt richting het stootkussen

-Hoe hard de vuist tegen het stootkussen slaat

## Gebruikte materialen

- Arduino Uno

- Infraroodsensor (voor snelheidsmeting)

- Drukknop (voor snelheidsmeting)

- Piezosensor (voor krachtmeting)

- LCD-scherm (voor scorebord)

- Stootkussen

- Breadboard en bedrading


Hieronder een schematische voorstelling van de bedrading voor dit project.

<p align="center">
  <img src="Images/bedradingsschema.jpeg" height="550px">
</p>

## Werking

### Snelheid meten
De IR-sensor wordt gericht met behulp van een papieren cilindervormvorm. Zo ziet de sensor enkel wat recht voor hem beweegt. Wanneer een vuist voorbij de sensor gaat, start een timer. Zodra de drukknop, die achter het stootkussen is geplaatst, geraakt wordt, stopt de timer. Het verschil in tijd tussen die twee momenten en de afstand tussen de sensor en de drukknop worden gebruikt om de snelheid van de vuistslag te bepalen.

### Kracht meten
Achter het stootkussen zit, naast de drukknop om de snelheid te meten, ook het piezo element. Dit fungeert als sensor en geeft een spanningssignaal wanneer hij wordt geraakt. Hoe harder de stoot, hoe hoger het signaal. De Arduino leest deze waarde uit en zet het zo om in een getal dat iets zegt over de kracht van de slag.

### Scorebord
Op een LCD-scherm worden de resultaten getoond. Hierop staan de snelheid (in km/u) en de kracht (als numerieke waarde). Zo is het mogelijk om elke slag direct te beoordelen. Wanneer de machine terug gereed is, gaat er een buzzer af die duidelijk maakt wanneer er opnieuw geslagen mag worden.

In volgorde gebeurd er dan:
1) Buzzer maakt een piepgeluid => klaar om te slaan
2) Vuist passeert de PIR-sensor => timer start
3) Vuist drukt het stootkussen in => ptototype concentreert de kracht naar één punt.
4) Piëzo en drukknop worden ingedrukt => Snelheid en kracht gemeten
5) Alles wordt weergegeven op het schermpje.

## Resultaat

<p align="center">
  <img src="Images/VA_volledig.jpg" height="500px">
  <img src="Images/Vol_opstellilng_gemonteerd.jpg" height="500px">
</p>

## Mogelijke verbeteringen
- Betere impactmeting met behulp van een druksensor in plaats van een piezo element
- Robuustere en duurzamere bouw van het prototype ivm het stootkussen
- De functie van de drukknop bij het gebruik van de druksensor voegen


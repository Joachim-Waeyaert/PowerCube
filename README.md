# PowerCube
an arduino remake of the power cube 

##Inleiding

Voor het vak Opkomende Technologieën is een boksmachine gemaakt die de snelheid en de kracht van een vuistslag meet. Het project gebruikt sensoren en een Arduino om te meten en vervolgens de gegevens te tonen.

**Doel
Het doel van het project is het bouwen van een boksmachine die twee zaken meet:

-Hoe snel een vuist beweegt richting het stootkussen

-Hoe hard de vuist tegen het stootkussen slaat

//schets toevoegen?

**Gebruikte materialen
//afbeeldingen bijzetten?
-Arduino Nano

-Infraroodsensor (voor snelheidsmeting)

-Drukknop (voor snelheidsmeting)

-Piezosensor (voor krachtmeting)

-LCD-scherm (voor scorebord)

-Stootkussen

-Breadboard en bedrading

//schema bedrading?

**Werking
***Snelheid meten
De IR-sensor wordt gericht met behulp van een WC-rol. Zo ziet de sensor enkel wat recht voor hem beweegt. Wanneer een vuist voorbij de sensor gaat, start een timer. Zodra de drukknop geraakt wordt, stopt de timer. Het verschil in tijd tussen die twee momenten en de afstand tussen de sensor en de drukknop worden gebruikt om de snelheid van de vuistslag te bepalen.

//schets?

***Kracht meten
Achter de drukknop zit een piezosensor. Deze sensor geeft een spanningssignaal wanneer hij wordt geraakt. Hoe harder de stoot, hoe hoger het signaal. De Arduino leest deze waarde uit en zet het zo om in een getal dat iets zegt over de kracht van de slag.

***Scorebord
Op een LCD-scherm worden de resultaten getoond. Hierop staan de snelheid (in milliseconden) en de kracht (als numerieke waarde). Zo is het mogelijk om elke slag direct te beoordelen.

**Resultaat


**Mogelijke verbeteringen


Besluit

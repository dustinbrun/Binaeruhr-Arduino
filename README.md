# Arduino Binäruhr 
Eine Binäruhr basierend auf einem Arduino Nano. Die LEDs werden mit Hilfe von 74HC595 Schieberegistern angesteuert.

[<img src="pictures/Uhr_1.jpg" height="400px">](pictures/Uhr_1.jpg)
[<img src="pictures/Uhr_2.jpg" height="400px">](pictures/Uhr_2.jpg)
[<img src="pictures/Uhr_innen.jpg" height="400px">](pictures/Uhr_innen.jpg)

## Features
- Einbau in einem IKEA Ribba Bilderrahmen 13x18 cm (bzw. 10x15 cm)
- Die Zeit wird von einer DS3231 RTC bereitgestellt
- Ein Taster zum ändern der Anzeige:
  - Normalmodus: Zeitanzeige - Stunden, Minuten, Sekunden
  - Datumsanzeige - Tag, Monat, Tag der Woche (1-7)
  - Temperaturanzeige - Temperaturmessung erfolgt durch das RTC-Modul 
    - Wenn die Anzeige im Datum- oder Temperaturmodus ist, wechselt sie nach 10 Sekunden automatisch zum Normalmodus zurück
- Eine extra LED blinkt 2 mal jede Sekunde

# Hardware
## Schaltplan
**Im Schaltplan sind keine Vorwiderstände für die einzelnen LEDs eingetragen, diese sollten jedoch verbaut werden! (Wert: 220R)** <br><br>
[<img src="pictures/Binaeruhr_Schaltplan.png" height="700px">](pictures/Binaeruhr_Schaltplan.png)

## Leiterplatte
[<img src="pictures/Binaeruhr_Platine_Leiterplatte.png" height="400px">](pictures/Binaeruhr_Platine_Leiterplatte.png)

## Frontplatte
Ich habe für den Bilderrahmen eine Frontplatte erstellt (Software: Frontplatten Designer, Schaeffer AG). Diese ist passend für den IKEA Bilderrahmen und kann im Format **10x15 cm** ausgeruckt werden. 
<br><br>
[<img src="Frontplatte.png" height="600px">](Frontplatte.png)

# Software
Der Code kann ohne weitere Änderungen verwendet werden. Um die Zeit des RTC-Moduls einzustellen müssen im Code die entsprechenden Zeilen auskommentiert und mit der aktuellen Uhrzeit gefüllt werden. Anschließend muss dieser Code **einmalig** auf dem Arduino ausgeführt werden.

Die Verwendete Bibiliothek für die DS3231 ist im Ordner des Programmes bereits hinterlegt und muss nicht extra heruntergeladen werden. Zusätzlich ist die Quelle der Bibiliothek jedoch im Code verlinkt.

# Quellen
- https://pascalstechtips.weebly.com/projekte/arduino-binruhr-v10 
- DS3231: http://www.rinkydinkelectronics.com/library.php?id=73
- Software für Frontplatte: https://www.schaeffer-ag.de/frontplatten-designer#

<br><br>
<p xmlns:dct="http://purl.org/dc/terms/" xmlns:cc="http://creativecommons.org/ns#" class="license-text">This work by <span property="cc:attributionName">Dustin Brunner</span> is licensed under <a rel="license" href="https://creativecommons.org/licenses/by/4.0">CC BY 4.0<img style="height:15px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1" /><img style="height:15px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1" /></a></p>

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons Lizenzvertrag" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a><br />Dieses Werk von <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Dustin Brunner</span> ist lizenziert unter einer <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Namensnennung 4.0 International Lizenz</a>.



# dinoSpiel
C-Projekt - Nachprogrammierung des Google Chrome Dino Spiels  
Zu bewertendes Projekt von Benjamin und Philip für das Fach C-Programmierung am BSZ-WiDat in Würzburg.

Eine Nachprogrammierung des [Spieles, dass Google Chrome anzeigt wenn man keine Verbindung hat.](http://apps.thecodepost.org/trex/trex.html)  
Realisiert unter Linux auf der Konsole mithilfe der ncurses-Bibliothek.

![Screenshot dinoSpiel](screenshot.png)

## Installation
(Sobald die Entwicklung abgeschlossen ist.)

- Klonen sie das Repository oder laden sie den Ordner Dinospiel herunter.
- Installieren sie die ncurses Bibliothek über ihren Packagemanager, auf Ubunutu: `apt-get install libncurses5-dev`
- Im Ordner Dinospiel kompilieren Sie dinospiel.c: `gcc dinospiel.c -lncurses`
- Führen sie die erstellte Datei aus: `./a.out`

## Benutzerhandbuch

Zu Beginn wird Sie das Spiel bitten, Ihre Konsole auf die richtige Größe einzustellen. Vergrößern Sie Ihr Konsolenfenster oder verkleinern sie die Schriftgröße so weit, dass der komplette Dino auf den Bildschirm passt. Drücken sie dann Enter zum Fortfahren.  
Das Titelmenü wird angezeigt, am unteren Bildschirmrand sehen sie alle Steuerungstasten:

### Steuerung
#### In Menüs:
- Pfeiltasten hoch und runter zum Ändern der Auswahl
- Enter zum Auswählen des markierten Menüpunktes

#### Im Spiel:
- Pfeiltaste oben oder Leertaste zum Springen
- ESC zum Pausieren

### Spielablauf
Ein Meteorit wird bald in Dinoland einschlagen. Die Dinos müssen fliehen, aber der einzige Weg führt durch die __lange und gefährliche Kakteenwüste__.  
Helfen Sie dem Dino zu entkommen! Springen Sie über die Kakteen und __überleben Sie so lange wie möglich__. Je länger Sie überleben, desto mehr __Punkte__ erhalten Sie.  
Schaffen Sie es nicht, einem Kaktus auszuweichen, bedeutet das Game Over. Wenn Sie genug Punkte erreicht haben, erhalten Sie einen Platz in der __Highscoreliste!__ Geben Sie Ihren Namen oder einen coolen Nicknamen ein und drücken Sie Enter.  

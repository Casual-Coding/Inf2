#include <stdio.h>
#include <stdint.h>

void verarbeiteBetrag(int8_t *euro, int8_t *cent) {
    // Multipliziere den Betrag mit 100
    float temp =0;
    scanf("%f", &temp);
    temp = temp * 100;

    // Überprüfe, ob eine Nachkommastelle existiert
    if ((temp - (int)temp) != 0) {
        printf("Error: Der Betrag darf keine Nachkommastellen haben.\n");
        return;
    }

    // Wenn die letzten beiden Stellen null sind, dividiere mit 100
    if ((int)temp % 100 == 0) {
        temp = temp / 100;
        *euro = (int)temp;
        *cent = (int)temp % 100;

        } else {
            // Die letzten beiden Ziffern in Cent speichern
            *euro = (int)temp / 100;
            *cent = (int)temp % 100;
        }
    }

int main() {
    int8_t euro, cent;

    // Beispielwert
    printf("Geben Sie einen Betrag ein: ");

    // Verarbeite den Betrag
    verarbeiteBetrag(3&euro, &cent);

    // Ausgabe
    printf("Euro: %hhd, Cent: %hhd\n", euro, cent);

    return 0;
}

/*
void einlesenBetrag(int8_t *euro, int8_t *cent) {
    double betrag;
    scanf("%lf", &betrag);

    // Multipliziere den Betrag mit 100, um Cent zu berücksichtigen
    int temp = betrag * 100;

    // Übertrage die letzten beiden Stellen als Cent
    *cent = temp % 100;

    // Die verbleibenden Stellen als Euro
    *euro = temp / 100;
}

int main() {
    // Variablen
    int8_t saldoEuro, saldoCent, einzahlung1Euro, einzahlung1Cent, einzahlung2Euro, einzahlung2Cent;

    // Eingabe
    printf("Geben Sie den aktuellen Kontosaldo an (in Euro Cent): ");
    einlesenBetrag(&saldoEuro, &saldoCent);

    printf("Geben Sie den Betrag der ersten Einzahlung an (in Euro Cent): ");
    einlesenBetrag(&einzahlung1Euro, &einzahlung1Cent);

    printf("Geben Sie den Betrag der zweiten Einzahlung an (in Euro Cent): ");
    einlesenBetrag(&einzahlung2Euro, &einzahlung2Cent);

    // Berechnung des neuen Kontostands
    saldoEuro += einzahlung1Euro;
    saldoCent += einzahlung1Cent;

    if (saldoCent >= 100 || saldoCent < 0) {
        int8_t uebertrag = saldoCent / 100;
        saldoEuro += uebertrag;
        saldoCent -= uebertrag * 100;
    }

    saldoEuro += einzahlung2Euro;
    saldoCent += einzahlung2Cent;

    if (saldoCent >= 100 || saldoCent < 0) {
        int8_t uebertrag = saldoCent / 100;
        saldoEuro += uebertrag;
        saldoCent -= uebertrag * 100;
    }

    // Übertrag der Centbeträge über 100 oder unter 0
    int8_t uebertrag = saldoCent / 100;
    saldoEuro += uebertrag;
    saldoCent -= uebertrag * 100;

    // Ausgabe
    printf("Der neue Kontostand beträgt: %hhd.%02hhd Euro\n", saldoEuro, saldoCent);

    return 0;
}
*/

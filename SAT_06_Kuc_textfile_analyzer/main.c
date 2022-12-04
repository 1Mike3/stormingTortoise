#include <stdio.h>

// print 2d array modified for letterarrayoutput
void print_2d_arraymod(int size1, int size2, char matrix[size1][size2], int matrixwerte[size1][size2], FILE *filepointer){
    for (int i = 0; i < size2 ; ++i) {
        fprintf(filepointer, "\n");
        for (int j = 0; j < size1; ++j) {

            if(matrix[j][i] != 0) {
                fprintf(filepointer,"%c: %03i ", matrix[j][i], matrixwerte[j][i]);
            }

        }
    }

}

 int main() {
     //###########################USER INPUT FILEPATH#######################################
     char FileInputString[] = "Randomfilename"; //der pfad den der user für das abgelegte pfile angibt
     printf("__________________Text-Analyzer___________________\n\n");
     printf("The statistic will be saved in text_stats.txt!\n\n");
     printf("Select the File you want to analyze: \n");
scanf("%s", FileInputString);
printf("\n");



     //Multidimensionale Arrays Ersachaffen
     char multarrc[4][7] = {}; //multidimensionales array das die Chars enthält
     int multarrcv[4][7] = {};  //multidimensionales array das deren anzahl enthält
     //#########################ZAHLEN ZÄHLEN#################################################
     char Zreadin[10][2] = {}; //multidimensionales array in das alle gelesenen Werte gespeichert werden
     int  Zvaluecounter[21] = {}; //multidimensionales array Enthält zum ersten Array die korrespondierende Anzahl
     int gesamtzahlenzaehler = 0; ////AUSGABE
     //multidimensionales array das die Zahlen enthält 0 -20
     char Zvalues[21][2] = {{'0', '0'},
                            {'0', '1'},
                            {'0', '2'},
                            {'0', '3'},
                            {'0', '4'},
                            {'0', '5'},
                            {'0', '6'},
                            {'0', '7'},
                            {'0', '8'},
                            {'0', '9'},
                            {'1', '0'},
                            {'1', '1'},
                            {'1', '2'},
                            {'1', '3'},
                            {'1', '4'},
                            {'1', '5'},
                            {'1', '6'},
                            {'1', '7'},
                            {'1', '8'},
                            {'1', '9'},
                            {'2','0'}};
     //Zählelemente
     int tmp = 0;
    //diesen nicht für finale auswertung verwenden er enthält wirklich alle zeichen
    int gesamtzeichenzaaehler = -1; // -1 wegen versatz beginn zählschleife //PROGRAMMSTEUERELEMENT

     int zeichenzaehler = 0; // AUSGABE alle zeichen ohne textkontrollelemente
     int zeilenzaehler = 1; // AUSGEBE alle zeilen, 1 weil erste Zeile immer da
     char chars[1000];  //die chars entsprechen dem Inhalt des Ausgelesenen files
     char wertermittlerLO = 'a'; // ist die Variable mit der verglichen wird um den wert der kleinbuchstavben zu ermitteln
     char kleinbuchstabenAlleArray[26]= {};   //tatsächliche werte von lowercase chars in einem Array
     int  anzahlGrosUndKleinBuchst[26] = {}; //deren korrespondierende Anzahl aufsteigend sortiert
     char wertermittlerHI = 'A'; // ist die Variable mit der verglichen wird um den wert der großbuchstaben zu ermitteln


//##############Start des Hauptablaufs mit öffnen des Filestreams####################################
    FILE *pfile;
  if ((pfile = fopen(FileInputString, "r"))) {


      // HAUPTZÄHLSCHLEIFE beginnt
      for (int i = 0; i < 1000 ; ++i) { //forloop zum holen der chars aus dem pfile
       //   fscanf(pfile,"%s" , words[i]);
          chars[i] = (char)fgetc(pfile);

       //Zählt !EINFACH ALLE ZEICHEN! für Programmablauf nicht ausgabe
          gesamtzeichenzaaehler++;

          //Zählt alle Zeichen von bedeutung für AUSGABE
       if(chars[i] >= 21/* && chars[i] != 32 */)
          {
              zeichenzaehler++;
          }

       //Zählt alle Zeilen für AUSGABE
          if((chars[i] == '\n' || chars[i] == '\r'))
          {
              zeilenzaehler++;
          }


       if(chars[i] == EOF){// Zeichnen Zählen
           break;
       }
      }// HAUPTZÄHLSCHLEIFE endet


      //filestrean 1 close
     fclose(pfile);
  } else{
      printf("Error");
      fprintf(stderr, "error while opening the file, wrong Filename?");
      return 1;
  }

     //:::::::::::::::::::ZAHLEN:::::::::::::::::::::::::::::::::
     //-----Auslesen der Werte aus Text in WerteArray
     for (int i = 0; i < gesamtzeichenzaaehler; ++i) {
         if((chars[i] <= 57 && chars[i] >= 48 )) {
             Zreadin[tmp][1] = chars[i];
gesamtzahlenzaehler++;

             if(chars[i+1] <= 57 && chars[i] >= 48){
                 Zreadin[tmp][0] = chars[i+1];
                 i++;
             }
             tmp++;
         }
     }
     //----Vergleichen von Ausgelesenen Werten mit Index array und erhöhen des Zahlenzählers
     for (int i = 0; i < 21; ++i) {

         for (int j = 0; j < 10; ++j) {
             //case zweistellige Zahl
             if(Zvalues[i][1] ==  Zreadin[j][1] && (Zvalues[i][0] == Zreadin[j][0]) ){
                 Zvaluecounter[i]++;
             }
             //case einstellige Zahl
             if((Zvalues[i][1] ==  Zreadin[j][1]) && (Zvalues[i][0] == '0' && Zreadin[j][0] == 32)){
                 Zvaluecounter[i]++;
             }
         }
     }

//:::::::::::::::::::ZAHLEN ENDE::::::::::::::::::::::::::::::::::::::::::

     //Forloop zum Zählen der Chars ALLE AUSGELESENEN BUCHSTABEN
     for (int j = 0; j < 26; ++j) {
         kleinbuchstabenAlleArray[j] = wertermittlerLO;
      //kleinbuchtaben
         for (int i = 0; i < gesamtzeichenzaaehler  ; ++i) {
      if(chars[i] == wertermittlerLO) {
          anzahlGrosUndKleinBuchst[j]++;
      }
         }
         wertermittlerLO ++; // buchstaben klein indexzähler eins weiter rücken
         //großbuchstaben
         for (int i = 0; i < gesamtzeichenzaaehler  ; ++i) {
             if(chars[i] == wertermittlerHI) {
                 anzahlGrosUndKleinBuchst[j]++;
             }
         }
         wertermittlerHI ++; // buchstaben groß indexzähler eins weiter rücken
     }

     //loop weist den Buchstabenarrays ihre werte zu
     for (int i = 0, k = 0; i < 4; ++i) {  // k für zählen con arrayindex aus dem gelesen wird

         for (int j = 0; j < 7; ++j) {
             if(k < 26) {
                 multarrc[i][j] = kleinbuchstabenAlleArray[k];
                 multarrcv[i][j] = anzahlGrosUndKleinBuchst[k];
             }
             k++;
         }
     }
     //Multidimensionale Arrays Erstellen ENDE


//in Datei Schreiben
//ERFOLGREICH Kann nun zwischen FILE2 und FILE2 END die Ausgabedatei manipulieren
     FILE *pfile2;
     pfile2 = fopen("text_stats.txt", "w");
     //FILE2
     fprintf(pfile2,"__________TextStats____________\n");
     fprintf(pfile2,"Selected File: %s\n\n", FileInputString);
     fprintf(pfile2, "== total number of characters: %i, lines: %i ==\n", zeichenzaehler, zeilenzaehler);
     print_2d_arraymod(4, 7, multarrc, multarrcv, pfile2);
     fprintf(pfile2, "\n\n== Total Numbers: %i in %i lines ==\n", gesamtzahlenzaehler, zeilenzaehler );

     for (int i = 0; i < 21; ++i) {
         if(Zvaluecounter[i] != 0){
             fprintf(pfile2, "%c%c: %i  ",Zvalues[i][0],Zvalues[i][1],Zvaluecounter[i]);
         }
     }

     //FILE2 END
     fclose(pfile2);
//in Datei schreiben ENDE
     return 0;
}

//Einschränkungen Prog durch ausgewählte variablen:
//Textlänge max 1000 Zeichen
//Max 10 Zahlen 0-20 im Text

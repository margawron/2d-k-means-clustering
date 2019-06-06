#ifndef _IO_H_
#define	_IO_H_

#include "SFML\Graphics.h"

//
// Funkcja readArgs
// funkcja ma za zadanie oczytanie nazw plików we/wy z argumentów uruchomieniowych programu
// int arg_count - liczba argumentów podana do programu
// char ** arg_value - wskażnik na tablicę z argumentami
// char ** inputFile - wskażnik na tablicę znaków do której zostanie przypisana nazwa pliku wejsciowego
// char ** outputFile - wskaźnik na tablicę znaków do której zostanie przypisana nazwa pliku wyjściowego
// unsigned int * iterations - przekazanie przez argument maksymalnej ilości iteracji
// unsigned int * numberOfFocals - przekazanie przez argument ilości grup skupienia
// return - zwraca 1 jeżeli oczytano argumenty z pliku, lub 0 jeżeli nie udało się odczytać argumentów
//
int readArgs(int arg_count, char ** arg_value, char ** inputFile, char ** outputFile, unsigned int * iterations, unsigned int * numberOfFocals);

//
// Funkcja openFile
// funkcja otwiera plik o zadanej nazwie i zwraca uchwyt do niego (adres do struktury z danymi)
// char * inputFile - wskaźnik na tablicę znaków z nazwą pliku wejściowego
// sfImage ** handle - wskaźnik na uchwyt do struktury z pikselami
// return - zwraca 1 jeżeli udało się otworzyć plik
//
int openFile(char * inputFile, sfImage ** handle);

//
// Funkcja saveFile
// funkcja zapisuje bufor z pikselami do pliku o nazwie podanej w tablicy outputFile
// char * outputFile - przechowuje nazwę pliku do którego ma zostać zapisany obraz
// sfImage * handle - zawiera uchwyt do struktury z buforem pikseli
// return - zwraca 1 jeżeli obraz udało się zapisać do pliku, 0 jeżeli nie udało sie zapisać obrazu
//
int saveFile(char * outputFile, sfImage * handle);


//
// funkcja closeFile
// funkcja zamyka plik
// sfImage * handle - uchwyt do struktury danych
// funkcja nic nie zwraca
//
void closeFile(sfImage ** handle);


#endif // !_IO_H_

#ifndef _IO_H_
#define	_IO_H_

#include "SFML\Graphics.h"

//
// Funkcja readArgs
// funkcja ma za zadanie oczytanie nazw plików we/wy z argumentów uruchomieniowych programu
// int arg_count - liczba argumentów podana do programu
// char ** arg_value - wska¿nik na tablicê z argumentami
// char ** inputFile - wska¿nik na tablicê znaków do której zostanie przypisana nazwa pliku wejsciowego
// char ** outputFile - wskaŸnik na tablicê znaków do której zostanie przypisana nazwa pliku wyjœciowego
// unsigned int * iterations - przekazanie przez argument maksymalnej iloœci iteracji
// unsigned int * numberOfFocals - przekazanie przez argument iloœci grup skupienia
// return - zwraca 1 je¿eli oczytano argumenty z pliku, lub 0 je¿eli nie uda³o siê odczytaæ argumentów
//
int readArgs(int arg_count, char ** arg_value, char ** inputFile, char ** outputFile, unsigned int * iterations, unsigned int * numberOfFocals);

//
// Funkcja openFile
// funkcja otwiera plik o zadanej nazwie i zwraca uchwyt do niego (adres do struktury z danymi)
// char * inputFile - wskaŸnik na tablicê znaków z nazw¹ pliku wejœciowego
// sfImage ** handle - wskaŸnik na uchwyt do struktury z pikselami
// return - zwraca 1 je¿eli uda³o siê otworzyæ plik
//
int openFile(char * inputFile, sfImage ** handle);

//
// Funkcja saveFile
// funkcja zapisuje bufor z pikselami do pliku o nazwie podanej w tablicy outputFile
// char * outputFile - przechowuje nazwê pliku do którego ma zostaæ zapisany obraz
// sfImage * handle - zawiera uchwyt do struktury z buforem pikseli
// return - zwraca 1 je¿eli obraz uda³o siê zapisaæ do pliku, 0 je¿eli nie uda³o sie zapisaæ obrazu
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

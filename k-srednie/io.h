#ifndef _IO_H_
#define	_IO_H_

#include "SFML\Graphics.h"

//
// Funkcja readArgs
// funkcja ma za zadanie oczytanie nazw plik�w we/wy z argument�w uruchomieniowych programu
// int arg_count - liczba argument�w podana do programu
// char ** arg_value - wska�nik na tablic� z argumentami
// char ** inputFile - wska�nik na tablic� znak�w do kt�rej zostanie przypisana nazwa pliku wejsciowego
// char ** outputFile - wska�nik na tablic� znak�w do kt�rej zostanie przypisana nazwa pliku wyj�ciowego
// unsigned int * iterations - przekazanie przez argument maksymalnej ilo�ci iteracji
// unsigned int * numberOfFocals - przekazanie przez argument ilo�ci grup skupienia
// return - zwraca 1 je�eli oczytano argumenty z pliku, lub 0 je�eli nie uda�o si� odczyta� argument�w
//
int readArgs(int arg_count, char ** arg_value, char ** inputFile, char ** outputFile, unsigned int * iterations, unsigned int * numberOfFocals);

//
// Funkcja openFile
// funkcja otwiera plik o zadanej nazwie i zwraca uchwyt do niego (adres do struktury z danymi)
// char * inputFile - wska�nik na tablic� znak�w z nazw� pliku wej�ciowego
// sfImage ** handle - wska�nik na uchwyt do struktury z pikselami
// return - zwraca 1 je�eli uda�o si� otworzy� plik
//
int openFile(char * inputFile, sfImage ** handle);

//
// Funkcja saveFile
// funkcja zapisuje bufor z pikselami do pliku o nazwie podanej w tablicy outputFile
// char * outputFile - przechowuje nazw� pliku do kt�rego ma zosta� zapisany obraz
// sfImage * handle - zawiera uchwyt do struktury z buforem pikseli
// return - zwraca 1 je�eli obraz uda�o si� zapisa� do pliku, 0 je�eli nie uda�o sie zapisa� obrazu
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

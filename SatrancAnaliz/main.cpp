#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "NoPiece.h"

void readFile(Board& mBoard, const std::string& path);
void writeFile(const std::string& path, const double& white_value, const double& black_value);

int main()
{
	Board mBoard;
	const std::string input_path = "..//input.txt";
	readFile(mBoard, input_path);
	
	mBoard.analyze(); // Tahtayi analiz et

	const std::string output_path = "..//output.txt";
	writeFile(output_path, mBoard.get_white_value(), mBoard.get_black_value());

	return 0;
}

void readFile(Board& mBoard, const std::string& path)
{
	// Dosyadan Okuma 
	std::string piece;
	std::fstream file;
	file.open(path, std::ios::in);
	// Dosyayi sol yukaridan okumaya baslayacagi icin baslangic pozisyonunu x = 0, y = 7 olarak ata
	int x_pos = 0;
	int y_pos = 7;
	// Kelime Kelime Okuma
	while (file >> piece) {
		//Okunan kelime k ile basliyorsa kale olustur tahtaya ekle
		if (piece[0] == 'k')
		{
			Piece* r = new Rook(x_pos, y_pos, piece[1]); //x, y pozisyonlarýný ve kelimenin 2. harfini renk olarak kullanarak nesne olustur
			mBoard.add_piece(r);
		}
		//Okunan kelime a ile basliyorsa at olustur tahtaya ekle
		else if (piece[0] == 'a')
		{
			Piece* k = new Knight(x_pos, y_pos, piece[1]);
			mBoard.add_piece(k);
		}
		//Okunan kelime f ile basliyorsa fil olustur tahtaya ekle
		else if (piece[0] == 'f')
		{
			Piece* b = new Bishop(x_pos, y_pos, piece[1]);
			mBoard.add_piece(b);
		}
		//Okunan kelime v ile basliyorsa vezir olustur tahtaya ekle
		else if (piece[0] == 'v')
		{
			Piece* q = new Queen(x_pos, y_pos, piece[1]);
			mBoard.add_piece(q);
		}
		//Okunan kelime s ile basliyorsa sah olustur tahtaya ekle
		else if (piece[0] == 's')
		{
			Piece* k = new King(x_pos, y_pos, piece[1]);
			mBoard.add_piece(k);
		}
		//Okunan kelime p ile basliyorsa piyon olustur tahtaya ekle
		else if (piece[0] == 'p')
		{
			Piece* p = new Pawn(x_pos, y_pos, piece[1]);
			mBoard.add_piece(p);
		}
		// yukaridakiler degilse bos kare demektir, parca yok nesnesi olustur tahtaya ekle
		else
		{
			Piece* np = new NoPiece(x_pos, y_pos, 'E');
			mBoard.add_piece(np);
		}
		x_pos++; // x pozisyonunu her kelimeden sonra 1 artir
		if (x_pos > 7) // eger x pozisyonu 7 den buyuk olmus ise yeni satira gecmis demektir
		{
			y_pos--; // y pozisyonunu 1 azalt
			x_pos = 0; // x pozisyonunu 0 la
		}

	}

	// Dosya Kapama
	file.close();
}

void writeFile(const std::string& path, const double& white_value, const double& black_value)
{
	std::fstream outFile;
	outFile.open(path, std::ios::out);

	// Siyahlar icin sonucu yazdir
	outFile << "Siyah : " << black_value << '\n';
	// Beyazlar icin sonucu yazdir
	outFile << "Beyaz : " << white_value << '\n';

	// Dosya Kapama
	outFile.close();
}
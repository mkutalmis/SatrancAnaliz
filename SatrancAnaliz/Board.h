#pragma once
#include"Piece.h"
class Piece;

class Board
{
public:
	// Constructor
	Board();
	// Tahtaya tas ekleme
	void add_piece(Piece* p);
	// Tahtanin belirtilen konumundaki tasi donderir
	Piece* get_piece(int x_pos, int y_pos);
	// Tahtadaki taslari analiz etme
	void analyze();
	// Siyah taslar icin toplam degeri donderir
	double get_black_value() const;
	// Beyaz taslar icin toplam degeri donderir
	double get_white_value() const;
	// Deconstructor
	~Board();
private:
	Piece** pieces; // Tahta


};


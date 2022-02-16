#include "Board.h"


// Constructor
Board::Board()
{
	this->pieces = new Piece*[64];
}

// Tahtaya tas ekleme
void Board::add_piece(Piece* p)
{
	this->pieces[p->get_posY() * 8 + p->get_posX()] = p;
}

// Tahtanin belirtilen konumundaki tasi donderir
Piece* Board::get_piece(int x_pos, int y_pos)
{
	return pieces[y_pos * 8 + x_pos];
}

// Tahtadaki taslari analiz etme
void Board::analyze()
{
	for (int i = 0; i < 64; i++)
	{
		pieces[i]->Attack(*this);
	}
}
// Siyah taslar icin toplam degeri donderir
double Board::get_black_value() const
{
	double result = 0;
	for (int i = 0; i < 64; i++)
	{
		if (pieces[i]->get_colour() == 's')
			result += pieces[i]->getValue();
	}
	return result;
}

// Beyaz taslar icin toplam degeri donderir
double Board::get_white_value() const
{
	double result = 0;
	for (int i = 0; i < 64; i++)
	{
		if (pieces[i]->get_colour() == 'b')
			result += pieces[i]->getValue();
	}
	return result;
}


// Deconstructor
Board::~Board()
{
	for (int i = 0; i < 64; i++)
	{
		delete pieces[i]; // dinamik olarak olusturulan elemanlari sil
	}
	delete[] pieces; // dinamik olarak olusturulan diziyi sil
}
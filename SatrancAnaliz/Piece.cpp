#include "Piece.h"

// Default Constructor
Piece::Piece()
{

}
// Constructor : argumanlari sinifin özel degiskenlerine atiyor
Piece::Piece(int pos_x, int pos_y, char colour)
{
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->colour = colour;
	this->underAttack = false;
}

// Polimorfizm yapisini kullanabilmek icin fonksiyon, turetilmis siniflarda kullanilacak
double Piece::getValue() const
{
	return 0.0;
}
// Polimorfizm yapisini kullanabilmek icin fonksiyon, turetilmis siniflarda kullanilacak
void Piece::Attack(Board& b)
{

}
// Tasin saldiri altinda oldugunu belirten degiskene 'true' degerini atar.
void Piece::setUnderAttack()
{
	this->underAttack = true;
}

// Tasin hangi sutunda oldugunu donderir
int Piece::get_posX() const
{
	return this->pos_x;
}
// Tasin hangi satirda oldugunu donderir
int Piece::get_posY() const
{
	return this->pos_y;
}
// Tasin rengini donderir
char Piece::get_colour() const
{
	return this->colour;
}
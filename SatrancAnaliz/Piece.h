#pragma once
#include "Board.h"
class Board;

// Tum taslarin turetilecegi temel sinif
class Piece
{
public:
	// Default Constructor
	Piece();

	// Constructor tasin tahta uzerindeki konumunu ve tasin rengini arguman olarak aliyor
	Piece(int pos_x, int pos_y, char colour); 

	/* Taslarin degerini hesaplayacak fonksiyon
	   Polimorfizm yapisini kullanabilmek icin virtual fonksiyon */
	virtual double getValue() const; 

	// Ilgili tasin saldirdigi taslari belirleyecek fonksiyon
	virtual void Attack(Board& b);

	// underAttack degiskenine 'true' atayacak fonksiyon
	void setUnderAttack();

	// Tasin hangi sutunda oldugunu donderir
	int get_posX() const;

	// Tasin hangi satirda oldugunu donderir
	int get_posY() const;

	// Tasin rengini donderir
	char get_colour() const;

protected:
	/* Tasa saldiran baska tas var mi 
	   Bu degisken protected cunku turetilmis siniflar bu degiskene erisebilmeli */
	bool underAttack; 

private:
	int pos_x, pos_y; // Tasin x, y konumlari
	char colour; // Tasin rengi
};


#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
	Pawn(int pos_x, int pos_y, char colour);

	// Tasin degerini donderiyor
	double getValue() const override;

	// Tasin saldirdigi taslari belirliyor
	void Attack(Board& b) override;
private:
	double value; // Tasin degeri
private:
	// Piyonun saldirdigi taslari bulmada kullanilan yardimci fonksiyon
	void attack(Board& b, int x_pos, int y_pos);
};


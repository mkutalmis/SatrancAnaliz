#pragma once
#include "Piece.h"
class NoPiece :
	public Piece
{
public:
	// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
	NoPiece(int pos_x, int pos_y, char colour);

	// Tasin degerini donderiyor
	double getValue() const override;

	// Tasin saldirdigi taslari belirliyor
	void Attack(Board& b) override;
};


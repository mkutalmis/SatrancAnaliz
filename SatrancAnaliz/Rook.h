#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
	Rook(int pos_x, int pos_y, char colour);

	// Tasin degerini donderiyor
	double getValue() const override;

	// Tasin saldirdigi taslari belirliyor
	void Attack(Board& b) override;
private:
	double value; // Tasin degeri
private:
	// Kalenin (sag) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR(Board& b, int x_pos, int y_pos);
	// Kalenin (sol) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL(Board& b, int x_pos, int y_pos);
	// Kalenin (yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackU(Board& b, int x_pos, int y_pos);
	// Kalenin (asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackD(Board& b, int x_pos, int y_pos);
};


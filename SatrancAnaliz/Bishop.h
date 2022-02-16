#pragma once
#include "Piece.h"
// Fil tasina ait sinif
class Bishop :
	public Piece
{
public:
	// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
	Bishop(int pos_x, int pos_y, char colour);

	// Tasin degerini donderiyor
	double getValue() const override;

	// Tasin saldirdigi taslari belirliyor
	void Attack(Board& b) override;
private:
	double value; // Tasin degeri
private:
	// Filin (sag, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR_U(Board& b, int x_pos, int y_pos);
	// Filin (sag, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR_D(Board& b, int x_pos, int y_pos);
	// Filin (sol, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL_U(Board& b, int x_pos, int y_pos);
	// Filin (sol, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL_D(Board& b, int x_pos, int y_pos);
};


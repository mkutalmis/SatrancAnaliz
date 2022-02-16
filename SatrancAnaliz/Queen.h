#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
	Queen(int pos_x, int pos_y, char colour);

	// Tasin degerini donderiyor
	double getValue() const override;

	// Tasin saldirdigi taslari belirliyor
	void Attack(Board& b) override;
private:
	double value; // Tasin degeri
private:
	// Vezirin (sag) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR(Board& b, int x_pos, int y_pos);
	// Vezirin (sol) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL(Board& b, int x_pos, int y_pos);
	// Vezirin (yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackU(Board& b, int x_pos, int y_pos);
	// Vezirin (asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackD(Board& b, int x_pos, int y_pos);
	// Vezirin (sag, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR_U(Board& b, int x_pos, int y_pos);
	// Vezirin (sag, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackR_D(Board& b, int x_pos, int y_pos);
	// Vezirin (sol, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL_U(Board& b, int x_pos, int y_pos);
	// Vezirin (sol, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
	void attackL_D(Board& b, int x_pos, int y_pos);
};


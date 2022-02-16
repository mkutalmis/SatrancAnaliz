#include "Pawn.h"


// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
Pawn::Pawn(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
	this->value = 1;
}

// Piyonun degerini donderiyor
double Pawn::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Piyonun saldirdigi taslari belirliyor
void Pawn::Attack(Board& b)
{
	// Eger beyaz piyonsa yukari yonde saldirir
	if (this->get_colour() == 'b')
	{
		// Piyonun (sag, yukari) yonde yaptigi saldirilar
		this->attack(b, get_posX() + 1, get_posY() + 1);
		// Piyonun (sol, yukari) yonde yaptigi saldirilar
		this->attack(b, get_posX() - 1, get_posY() + 1);
	}
	// Eger siyah piyonsa asagi yonde saldirir
	else
	{
		// Piyonun (sag, asagi) yonde yaptigi saldirilar
		this->attack(b, get_posX() + 1, get_posY() - 1);
		// Piyonun (sol, asagi) yonde yaptigi saldirilar
		this->attack(b, get_posX() - 1, get_posY() - 1);
	}
}

// Piyonun saldirdigi taslari bulmada kullanilan yardimci fonksiyon
void Pawn::attack(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise geri don
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return;

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	return;
}
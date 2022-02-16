#include "Knight.h"


// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
Knight::Knight(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
	this->value = 3;
}

// Atin degerini donderiyor
double Knight::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Atin saldirdigi taslari belirliyor
void Knight::Attack(Board& b)
{
	// Atin (2 asagi, 1 sag) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 1, get_posY() - 2);
	// Atin (2 asagi, 1 sol) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 1, get_posY() - 2);
	// Atin (1 asagi, 2 sol) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 2, get_posY() - 1);
	// Atin (1 yukari, 2 sol) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 2, get_posY() + 1);
	// Atin (2 yukari, 1 sol) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 1, get_posY() + 2);
	// Atin (2 yukari, 1 sag) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 1, get_posY() + 2);
	// Atin (1 asagi, 2 sag) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 2, get_posY() - 1);
	// Atin (1 yukari, 2 sag) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 2, get_posY() + 1);
}

// Atin saldirdigi taslari bulmada kullanilan yardimci fonksiyon
void Knight::attack(Board& b, int x_pos, int y_pos)
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
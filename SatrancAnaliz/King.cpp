#include "King.h"


// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
King::King(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
	this->value = 100;
}

// Sahin degerini donderiyor
double King::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Sahin saldirdigi taslari belirliyor
void King::Attack(Board& b)
{
	// Sadece vezir, at ve piyonun tehditleri hesaplanmasi istendigi icin bu fonksiyondan cikiliyor
	return;
	// Sahin (ust) yonde yaptigi saldirilar
	this->attack(b, get_posX(), get_posY() + 1);
	// Sahin (alt) yonde yaptigi saldirilar
	this->attack(b, get_posX(), get_posY() - 1);
	// Sahin (sag) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 1, get_posY());
	// Sahin (sol) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 1, get_posY() - 1);
	// Sahin (sag, ust) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 1, get_posY() + 1);
	// Sahin (sol, ust) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 1, get_posY() + 1);
	// Sahin (sag, alt) yonde yaptigi saldirilar
	this->attack(b, get_posX() + 1, get_posY() - 1);
	// Sahin (sol, alt) yonde yaptigi saldirilar
	this->attack(b, get_posX() - 1, get_posY() - 1);
}

// Sahin saldirdigi taslari bulmada kullanilan yardimci fonksiyon
void King::attack(Board& b, int x_pos, int y_pos)
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

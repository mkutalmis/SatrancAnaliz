#include "Rook.h"

// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
Rook::Rook(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
	this->value = 5;
}

// Kalenin degerini donderiyor
double Rook::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Kalenin saldirdigi taslari belirliyor
void Rook::Attack(Board& b)
{
	// Sadece vezir, at ve piyonun tehditleri hesaplanmasi istendigi icin bu fonksiyondan cikiliyor
	return;
	// Kalenin (sag) yonde yaptigi saldirilar
	this->attackR(b, get_posX() + 1, get_posY());
	// Kalenin (sol) yonde yaptigi saldirilar
	this->attackL(b, get_posX() - 1, get_posY());
	// Kalenin (yukari) yonde yaptigi saldirilar
	this->attackU(b, get_posX(), get_posY() + 1);
	// Kalenin (asagi) yonde yaptigi saldirilar
	this->attackD(b, get_posX(), get_posY() - 1);
}
// Kalenin (sag) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Rook::attackR(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR(b, x_pos + 1, y_pos);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Kale taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Kalenin (sol) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Rook::attackL(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL(b, x_pos - 1, y_pos);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Kale taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Kalenin (yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Rook::attackU(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackU(b, x_pos, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Kale taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Kalenin (asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Rook::attackD(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackD(b, x_pos, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Kale taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
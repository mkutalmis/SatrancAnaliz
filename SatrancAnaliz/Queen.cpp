#include "Queen.h"

// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
Queen::Queen(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
	this->value = 9;
}

// Vezirin degerini donderiyor
double Queen::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Vezirin saldirdigi taslari belirliyor
void Queen::Attack(Board& b)
{
	// Vezirin (sag) yonde yaptigi saldirilar
	this->attackR(b, get_posX() + 1, get_posY());
	// Vezirin (sol) yonde yaptigi saldirilar
	this->attackL(b, get_posX() - 1, get_posY());
	// Vezirin (yukari) yonde yaptigi saldirilar
	this->attackU(b, get_posX(), get_posY() + 1);
	// Vezirin (asagi) yonde yaptigi saldirilar
	this->attackD(b, get_posX(), get_posY() - 1);
	// Vezirin (sag, ust) yonde yaptigi saldirilar
	this->attackR_U(b, get_posX() + 1, get_posY() + 1);
	// Vezirin (sol, ust) yonde yaptigi saldirilar
	this->attackL_U(b, get_posX() - 1, get_posY() + 1);
	// Vezirin (sag, alt) yonde yaptigi saldirilar
	this->attackR_D(b, get_posX() + 1, get_posY() - 1);
	// Vezirin (sol, alt) yonde yaptigi saldirilar
	this->attackL_D(b, get_posX() - 1, get_posY() - 1);
}
// Vezirin (sag) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackR(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR(b, x_pos + 1, y_pos);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (sol) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackL(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL(b, x_pos - 1, y_pos);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackU(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackU(b, x_pos, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackD(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackD(b, x_pos, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}

// Vezirin (sag, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackR_U(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR_U(b, x_pos + 1, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (sag, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackR_D(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR_D(b, x_pos + 1, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (sol, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackL_U(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL_U(b, x_pos - 1, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Vezirin (sol, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Queen::attackL_D(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL_D(b, x_pos - 1, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//Vezir taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
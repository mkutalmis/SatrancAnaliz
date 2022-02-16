#include "Bishop.h"


// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
Bishop::Bishop(int pos_x, int pos_y, char colour):Piece(pos_x,pos_y,colour)
{
	this->value = 3;
}

// Filin degerini donderiyor
double Bishop::getValue() const
{
	// Eger tas saldiri altindaysa degerinin yarisini donder
	// Degilse degeri donder
	if (underAttack)
		return this->value / 2.0;
	else
		return this->value;
}

// Filin saldirdigi taslari belirliyor
void Bishop::Attack(Board& b)
{
	// Sadece vezir, at ve piyonun tehditleri hesaplanmasi istendigi icin bu fonksiyondan cikiliyor
	return;
	// Filin (sag, ust) yonde yaptigi saldirilar
	this->attackR_U(b, get_posX() + 1, get_posY() + 1);
	// Filin (sol, ust) yonde yaptigi saldirilar
	this->attackL_U(b, get_posX() - 1, get_posY() + 1);
	// Filin (sag, alt) yonde yaptigi saldirilar
	this->attackR_D(b, get_posX() + 1, get_posY() - 1);
	// Filin (sol, alt) yonde yaptigi saldirilar
	this->attackL_D(b, get_posX() - 1, get_posY() - 1);
}

// Filin (sag, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Bishop::attackR_U(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if(b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR_U(b, x_pos + 1, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//fil taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Filin (sag, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Bishop::attackR_D(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackR_D(b, x_pos + 1, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//fil taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Filin (sol, yukari) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Bishop::attackL_U(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL_U(b, x_pos - 1, y_pos + 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//fil taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
// Filin (sol, asagi) yonde saldirdigi taslari bulmada kullanilan yardimci recursive fonksiyon
void Bishop::attackL_D(Board& b, int x_pos, int y_pos)
{
	// Eger tahta sinirlari disina cikmissa geri don
	if (x_pos > 7 || x_pos < 0) return;
	if (y_pos > 7 || y_pos < 0) return;

	// Eger bos kare gelmis ise obur kareye gec
	if (b.get_piece(x_pos, y_pos)->get_colour() == 'E') return attackL_D(b, x_pos - 1, y_pos - 1);

	// Eger karsi renkteki tasa gelmis ise o tasi saldiri altinda diye isaretle
	if (b.get_piece(x_pos, y_pos)->get_colour() != this->get_colour()) b.get_piece(x_pos, y_pos)->setUnderAttack();

	// Yukaridaki kosullar tutmamis ise ayni renkli tasa gelmistir 
	//fil taslarin ustunden atlayamayacagi icin fonksiyondan cik.
	return;
}
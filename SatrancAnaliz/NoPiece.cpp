#include "NoPiece.h"

// Constructor tasin x,y pozisyonlari ve rengini arguman olarak aliyor
NoPiece::NoPiece(int pos_x, int pos_y, char colour) :Piece(pos_x, pos_y, colour)
{
}

// Bos kare oldugu icin 0 donderiyor
double NoPiece::getValue() const
{
	return 0.0;
}

// Bos kare oldugu icin hic birsey yapmiyor
void NoPiece::Attack(Board& b)
{
}
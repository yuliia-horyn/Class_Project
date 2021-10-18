#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::to_str()
{
	switch (code)
	{
	case Incorrect_year:
		return "Year is incorrect";
	case Incorrect_price:
		return "Price is negative";
	case Incorrect_quantity:
		return "Quantity is negative";
	case IndexOutsideLimit:
		return "Index is outside the limit";
	case MaxSizeReached:
		return "Max size reached";
	case ZeroQuantity:
		return "In this year was made no drone";
	default:
		return "";
	}
}
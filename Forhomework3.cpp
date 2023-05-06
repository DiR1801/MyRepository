#include <iostream>
#include <string> //Добавляем string, чтобы его можно было использовать

using namespace std;

class SeasonsBase //Базовый класс
{
public:
	enum AllSeasons //перечисление времен года, реализованное с помощью типа enum
	{
		Winter, Spring, Summer, Autumn
	};
	AllSeasons Season = Winter;//какое время года в данный момент
	void virtual Change() {} //Виртуальный метод
	virtual ~SeasonsBase() { cout << "Cleared" << endl; } //Виртуальный деструктор



};

class Seasons : public SeasonsBase// класс, наследующий от класса Seasons
{
public:

	void Change() override //Метод при вызове котрого будет меняться время года
	{
		switch (Season) {
		case Winter:
			Season = Spring;
			break;
		case Spring:
			Season = Summer;
			break;
		case Summer:
			Season = Autumn;
			break;
		case Autumn:
			Season = Winter;
			break;
		}
	}
};
class ReverseSeasons : public SeasonsBase // класс, наследующий от класса Seasons, в котором переопределено, чтобы перечисление времен года, шло в обратном порядке.
{

	void Change() override
	{
		switch (Season) {
		case Winter:
			Season = Winter;
			break;
		case Spring:
			Season = Autumn;
			break;
		case Summer:
			Season = Summer;
			break;
		case Autumn:
			Season = Spring;
			break;
		}
	}
};



int main()
{
	SeasonsBase seasonbase;
	Seasons seasons;
	ReverseSeasons reverseseasons;

	cout << seasons.Season << endl;//Время года на данный момент
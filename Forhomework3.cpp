#include <iostream>
#include <string> //��������� string, ����� ��� ����� ���� ������������

using namespace std;

class SeasonsBase //������� �����
{
public:
	enum AllSeasons //������������ ������ ����, ������������� � ������� ���� enum
	{
		Winter, Spring, Summer, Autumn
	};
	AllSeasons Season = Winter;//����� ����� ���� � ������ ������
	void virtual Change() {} //����������� �����
	virtual ~SeasonsBase() { cout << "Cleared" << endl; } //����������� ����������



};

class Seasons : public SeasonsBase// �����, ����������� �� ������ Seasons
{
public:

	void Change() override //����� ��� ������ ������� ����� �������� ����� ����
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
class ReverseSeasons : public SeasonsBase // �����, ����������� �� ������ Seasons, � ������� ��������������, ����� ������������ ������ ����, ��� � �������� �������.
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

	cout << seasons.Season << endl;//����� ���� �� ������ ������
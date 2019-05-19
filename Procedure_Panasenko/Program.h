#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------------------------
// �������������
//----------------------------------------------------------------------------------------------
struct rectangle
{
	int x, y;
};
void InRectangle(rectangle& r, ifstream& ifst);
void OutRectangle(rectangle& r, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// ����
//----------------------------------------------------------------------------------------------
struct circle
{
	int r;
};
void InCircle(circle& c, ifstream& ifst);
void OutCircle(circle& c, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// �������������� ������
//----------------------------------------------------------------------------------------------
struct shape
{
	enum key { RECTANGLE, CIRCLE };
	key k;
	union
	{
		rectangle r;
		circle c;
	};
};
void InShape(shape& s, ifstream& ifst);
void OutShape(shape& s, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// ������� ���������� - ������������ ������
//----------------------------------------------------------------------------------------------
struct node
{
	shape data;
	node* next;
};
//----------------------------------------------------------------------------------------------
// ��������� - ����������� ������
//----------------------------------------------------------------------------------------------
struct container
{
	node* head;
	node* last;
};
void InitContainer(container& c);
void InContainer(container& c, ifstream& ifst);
void OutContainer(container& c, ofstream& ofst);
void ClearContainer(container& c);
void OutRectangles(container& c, ofstream& ofst);
#endif
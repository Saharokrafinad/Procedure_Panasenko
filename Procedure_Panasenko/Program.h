#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------------------------
// �������������
//----------------------------------------------------------------------------------------------
struct rectangle
{
	int side1, side2;
};
void InRectangle(rectangle& r, ifstream& ifst);
void OutRectangle(rectangle& r, ofstream& ofst);
int Perimeter(rectangle& r);
//----------------------------------------------------------------------------------------------
// ����
//----------------------------------------------------------------------------------------------
struct circle
{
	int radius;
};
void InCircle(circle& c, ifstream& ifst);
void OutCircle(circle& c, ofstream& ofst);
int Perimeter(circle& c);
//----------------------------------------------------------------------------------------------
// �����������
//----------------------------------------------------------------------------------------------
struct triangle
{
	int side1, side2, side3;
};
void InTriangle(triangle& t, ifstream& ifst);
void OutTriangle(triangle& t, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// �������������� ������
//----------------------------------------------------------------------------------------------
struct shape
{
	enum key { RECTANGLE, CIRCLE, TRIANGLE};
	key type;
	int density;
	union
	{
		rectangle r;
		circle c;
		triangle t;
	};
};
void InShape(shape& s, ifstream& ifst);
void OutShape(shape& s, ofstream& ofst);
int Perimeter(shape& s);
bool Compare(shape& first, shape& second);
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
struct Container
{
	node* head;
	node* last;
};
void InitContainer(Container& c);
void InContainer(Container& c, ifstream& ifst);
void OutContainer(Container& c, ofstream& ofst);
void ClearContainer(Container& c);
void Sort(Container& c);
void OutRectangles(Container& c, ofstream& ofst);
#endif
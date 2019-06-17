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
int Perimeter(rectangle& r);
//----------------------------------------------------------------------------------------------
// ����
//----------------------------------------------------------------------------------------------
struct circle
{
	int r;
};
void InCircle(circle& c, ifstream& ifst);
void OutCircle(circle& c, ofstream& ofst);
int Perimeter(circle& c);
//----------------------------------------------------------------------------------------------
// �����������
//----------------------------------------------------------------------------------------------
struct triangle
{
	int x1, x2, x3;
};
void InTriangle(triangle& t, ifstream& ifst);
void OutTriangle(triangle& t, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// �������������� ������
//----------------------------------------------------------------------------------------------
struct shape
{
	enum key { RECTANGLE, CIRCLE, TRIANGLE};
	key k;
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
struct container
{
	node* head;
	node* last;
};
void InitContainer(container& c);
void InContainer(container& c, ifstream& ifst);
void OutContainer(container& c, ofstream& ofst);
void ClearContainer(container& c);
void Sort(container& c);
void OutRectangles(container& c, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// �����������
//----------------------------------------------------------------------------------------------
void MultiMethod(container& c, ofstream& ofst);
#endif
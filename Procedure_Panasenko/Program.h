#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
struct rectangle
{
	int side1, side2;
};
void InRectangle(rectangle& r, ifstream& ifst);
void OutRectangle(rectangle& r, ofstream& ofst);
int Perimeter(rectangle& r);
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
struct circle
{
	int radius;
};
void InCircle(circle& c, ifstream& ifst);
void OutCircle(circle& c, ofstream& ofst);
int Perimeter(circle& c);
//----------------------------------------------------------------------------------------------
// Треугольник
//----------------------------------------------------------------------------------------------
struct triangle
{
	int side1, side2, side3;
};
void InTriangle(triangle& t, ifstream& ifst);
void OutTriangle(triangle& t, ofstream& ofst);
//----------------------------------------------------------------------------------------------
// Геометрическая фигура
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
// Элемент контейнера - односвязного списка
//----------------------------------------------------------------------------------------------
struct node
{
	shape data;
	node* next;
};
//----------------------------------------------------------------------------------------------
// Контейнер - односвязный список
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
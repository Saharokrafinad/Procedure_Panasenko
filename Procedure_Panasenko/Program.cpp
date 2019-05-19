#include "Program.h"
using namespace std;
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
void InRectangle(rectangle& r, ifstream& ifst)
{
	ifst >> r.x >> r.y;
}
void OutRectangle(rectangle& r, ofstream& ofst)
{
	ofst << "Прямоугольник: x = " << r.x << ", y = " << r.y;
}
int Perimeter(rectangle& r)
{
	return 2 * (r.x + r.y);
}
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
void InCircle(circle& c, ifstream& ifst)
{
	ifst >> c.r;
}
int Perimeter(circle& c)
{
	return int(2 * 3.14 * c.r);
}
void OutCircle(circle& c, ofstream& ofst)
{
	ofst << "Круг: r = " << c.r;
}
//----------------------------------------------------------------------------------------------
// Треугольник
//----------------------------------------------------------------------------------------------
void InTriangle(triangle& t, ifstream& ifst)
{
	ifst >> t.x1 >> t.x2 >> t.x3;
}
void OutTriangle(triangle& t, ofstream& ofst)
{
	ofst << "Треугольник: x1 = " << t.x1 << ", x2 = " << t.x2 << ", x3 = " << t.x3;
}
int Perimeter(triangle& t)
{
	return t.x1 + t.x2 + t.x3;
}
//----------------------------------------------------------------------------------------------
// Геометрическая фигура
//----------------------------------------------------------------------------------------------
void InShape(shape& s, ifstream& ifst)
{
	int k;
	ifst >> k;
	switch (k)
	{
	case 1:
		s.k = shape::key::RECTANGLE;
		InRectangle(s.r, ifst);
		break;
	case 2:
		s.k = shape::key::CIRCLE;
		InCircle(s.c, ifst);
		break;
	case 3:
		s.k = shape::key::TRIANGLE;
		InTriangle(s.t, ifst);
		break;
	}
}
void OutShape(shape& s, ofstream& ofst)
{
	switch (s.k)
	{
	case shape::key::RECTANGLE:
		OutRectangle(s.r, ofst);
		break;
	case shape::key::CIRCLE:
		OutCircle(s.c, ofst);
		break;
	case shape::key::TRIANGLE:
		OutTriangle(s.t, ofst);
		break;
	}
}

	int Perimeter(shape & s)
	{
		switch (s.k)
		{
		case shape::key::RECTANGLE:
			return Perimeter(s.r);
		case shape::key::CIRCLE:
			return Perimeter(s.c);
		case shape::key::TRIANGLE:
			return Perimeter(s.t);
		}
	}
	bool Compare(shape& first, shape& second)
	{
		return Perimeter(first) < Perimeter(second);
	}

//----------------------------------------------------------------------------------------------
// Контейнер - односвязный список
//----------------------------------------------------------------------------------------------
void InitContainer(container& c)
{
	c.head = NULL;
	c.last = NULL;
}
void InContainer(container& c, ifstream& ifst)
{
	while (!ifst.eof())
	{
		shape data;
		InShape(data, ifst);
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		if (c.head == NULL)
		{
			c.head = temp;
			c.last = temp;
		}
		else
		{
			c.last->next = temp;
			c.last = temp;
		}
	}
}
void OutContainer(container& c, ofstream& ofst)
{
	ofst << "Контейнер содержит:" << endl;
	node* current = c.head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		OutShape(current->data, ofst);
		ofst << " Периметр: " << Perimeter(current->data) << endl;
		current = current->next;
	}
}
void ClearContainer(container& c)
{
	while (c.head != NULL)
	{
		node* forDelete = c.head;
		c.head = c.head->next;
		delete forDelete;
	}
}
void Sort(container& c)
{
	for (node* i = c.head; i; i = i->next)
		for (node* j = c.head; j; j = j->next)
			if (Compare(i->data, j->data))
				swap(i->data, j->data);
}
void OutRectangles(container& c, ofstream& ofst)
{
	ofst << "\nТолько прямоугольники:" << endl;
	node* current = c.head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		if (current->data.k == shape::RECTANGLE)
		{
			
			OutShape(current->data, ofst);
			ofst << "\n" << endl;
		}
		current = current->next;
		
	}
}
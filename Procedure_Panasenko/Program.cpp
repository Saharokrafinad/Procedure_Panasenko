#include "Program.h"
using namespace std;
//----------------------------------------------------------------------------------------------
// Прямоугольник
//----------------------------------------------------------------------------------------------
void InRectangle(rectangle& r, ifstream& ifst)
{
	ifst >> r.side1 >> r.side2;
}
void OutRectangle(rectangle& r, ofstream& ofst)
{
	ofst << "Прямоугольник: x = " << r.side1 << ", y = " << r.side2;
}
int Perimeter(rectangle& r)
{
	return 2 * (r.side1 + r.side2);
}
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
void InCircle(circle& container, ifstream& ifst)
{
	ifst >> container.radius;
}
int Perimeter(circle& container)
{
	return int(2 * 3.14 * container.radius);
}
void OutCircle(circle& container, ofstream& ofst)
{
	ofst << "Круг: r = " << container.radius;
}
//----------------------------------------------------------------------------------------------
// Треугольник
//----------------------------------------------------------------------------------------------
void InTriangle(triangle& t, ifstream& ifst)
{
	ifst >> t.side1 >> t.side2 >> t.side3;
}
void OutTriangle(triangle& t, ofstream& ofst)
{
	ofst << "Треугольник: x1 = " << t.side1 << ", x2 = " << t.side2 << ", x3 = " << t.side3;
}
int Perimeter(triangle& t)
{
	return t.side1 + t.side2 + t.side3;
}
//----------------------------------------------------------------------------------------------
// Геометрическая фигура
//----------------------------------------------------------------------------------------------
void InShape(shape& s, ifstream& ifst)
{
	int index;
	ifst >> index;
	switch (index)
	{
	case 1:
		s.type = shape::key::RECTANGLE;
		InRectangle(s.r, ifst);
		break;
	case 2:
		s.type = shape::key::CIRCLE;
		InCircle(s.c, ifst);
		break;
	case 3:
		s.type = shape::key::TRIANGLE;
		InTriangle(s.t, ifst);
		break;
	}
	ifst >> s.density;
}
void OutShape(shape& s, ofstream& ofst)
{
	switch (s.type)
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
	ofst << " Плотность = " << s.density;
}
	int Perimeter(shape & s)
	{
		switch (s.type)
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
void InitContainer(Container& container)
{
	container.head = NULL;
	container.last = NULL;
}
void InContainer(Container& container, ifstream& ifst)
{
	while (!ifst.eof())
	{
		shape data;
		InShape(data, ifst);
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		if (container.head == NULL)
		{
			container.head = temp;
			container.last = temp;
		}
		else
		{
			container.last->next = temp;
			container.last = temp;
		}
	}
}
void OutContainer(Container& container, ofstream& ofst)
{
	ofst << "Контейнер содержит:\n" << endl;
	node* current = container.head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		OutShape(current->data, ofst);
		ofst << " Периметр: " << Perimeter(current->data) << endl;
		current = current->next;
	}
}
void ClearContainer(Container& container)
{
	while (container.head != NULL)
	{
		node* forDelete = container.head;
		container.head = container.head->next;
		delete forDelete;
	}
}
void Sort(Container& container)
{
	for (node* i = container.head; i; i = i->next)
		for (node* j = container.head; j; j = j->next)
			if (Compare(i->data, j->data))
				swap(i->data, j->data);
}
void OutRectangles(Container& container, ofstream& ofst)
{
	ofst << "\nТолько прямоугольники:" << endl;
	node* current = container.head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		if (current->data.type == shape::RECTANGLE)
		{
			
			OutShape(current->data, ofst);
		}
		current = current->next;
		
	}
}
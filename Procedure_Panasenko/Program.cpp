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
	ofst << "Прямоугольник: x = " << r.x << ", y = " << r.y << endl;
}
//----------------------------------------------------------------------------------------------
// Круг
//----------------------------------------------------------------------------------------------
void InCircle(circle& c, ifstream& ifst)
{
	ifst >> c.r;
}
void OutCircle(circle& c, ofstream& ofst)
{
	ofst << "Круг: r = " << c.r << endl;
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
	}
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
//----------------------------------------------------------------------------------------------
// Мультиметод
//----------------------------------------------------------------------------------------------
void MultiMethod(container& c, ofstream& ofst)
{
	ofst << "Мултиметод:" << endl;
	node* i = c.head;
	while (i->next)
	{
		node* j = i->next;
		while (j)
		{
			switch (i->data.k)
			{
			case shape::RECTANGLE:
				switch (j->data.k)
				{
				case shape::RECTANGLE:
					ofst << "Прямоугольник и прямоугольник" << endl;
					break;
				case shape::CIRCLE:
					ofst << "Прямоугольник и круг" << endl;
					break;
				default:
					ofst << "Неизвестный тип" << endl;
				}
				break;
			case shape::CIRCLE:
				switch (j->data.k)
				{
				case shape::RECTANGLE:
					ofst << "Круг и прямоугольник" << endl;
					break;
				case shape::CIRCLE:
					ofst << "Круг и круг" << endl;
					break;
				default:
					ofst << "Неизвестный тип" << endl;
				}
				break;
			default:
				ofst << "Неизвсетный тип" << endl;
			}
			j = j->next;
		}
		i = i->next;
	}
}
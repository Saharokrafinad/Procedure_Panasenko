#include "Program.h"
using namespace std;
//----------------------------------------------------------------------------------------------
// �������������
//----------------------------------------------------------------------------------------------
void InRectangle(rectangle& r, ifstream& ifst)
{
	ifst >> r.x >> r.y;
}
void OutRectangle(rectangle& r, ofstream& ofst)
{
	ofst << "�������������: x = " << r.x << ", y = " << r.y;
}
int Perimeter(rectangle& r)
{
	return 2 * (r.x + r.y);
}
//----------------------------------------------------------------------------------------------
// ����
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
	ofst << "����: r = " << c.r;
}
//----------------------------------------------------------------------------------------------
// �������������� ������
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

	int Perimeter(shape & s)
	{
		switch (s.k)
		{
		case shape::key::RECTANGLE:
			return Perimeter(s.r);
		case shape::key::CIRCLE:
			return Perimeter(s.c);
		}
	}

//----------------------------------------------------------------------------------------------
// ��������� - ����������� ������
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
	ofst << "��������� ��������:" << endl;
	node* current = c.head;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		OutShape(current->data, ofst);
		ofst << " ��������: " << Perimeter(current->data) << endl;
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
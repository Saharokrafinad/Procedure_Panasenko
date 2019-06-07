#include <vector>
#include <string>
#include "pch.h"
#include "../Procedure_Panasenko/Program.cpp"
using namespace std;

string GetEntityStringView(shape temp)
{
	switch (temp.k)
	{
	case shape::key::RECTANGLE:
		return to_string(temp.r.x) + " " + to_string(temp.r.y) + " " + to_string(temp.density);
	case shape::key::CIRCLE:
		return to_string(temp.c.r) + " " + to_string(temp.density);
	case shape::key::TRIANGLE:
		return to_string(temp.t.x1) + " " + to_string(temp.t.x2) + " " + to_string(temp.t.x3) + to_string(temp.density);
	default:
		return "";
	}
}

TEST(ReadTests, IsReadCorrect)//Тест ввода
{
	container actual, expected;
	InitContainer(actual);
	InitContainer(expected);
	InContainer(actual, ifstream("../../ProcTests/ReadTestFile.txt"));
	AddElement(expected, new shape({ shape::RECTANGLE, {10, 20}, 100 }));
	AddElement(expected, new shape({ shape::CIRCLE, {25}, 200 }));
	AddElement(expected, new shape({ shape::TRIANGLE, {18,41}, 300 }));

	container actualElement = actual;
	container expectedElement = expected;
	actualElement.last = actualElement.head;
	expectedElement.last = expectedElement.head;
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(GetEntityStringView(actualElement.last->data), GetEntityStringView(expectedElement.last->data));
		actualElement.last = actualElement.last->next;
		expectedElement.last = expectedElement.last->next;
	}
}

TEST(SortTests, IsSortCorrect)//Тест сортировки
{
	container actual, expected;
	InitContainer(actual);
	InitContainer(expected);
	InContainer(actual, ifstream("../../ProcTests/SortTestFile.txt"));
	Sort(actual);
	AddElement(expected, new shape({ shape::TRIANGLE, {1,2}, 400 }));
	AddElement(expected, new shape({ shape::RECTANGLE, {10, 20}, 100 }));
	AddElement(expected, new shape({ shape::RECTANGLE, {14, 40}, 100 }));
	AddElement(expected, new shape({ shape::RECTANGLE, {100, 200}, 100 }));
	AddElement(expected, new shape({ shape::CIRCLE, {100}, 200 }));
	
	container actualElement = actual;
	container expectedElement = expected;
	actualElement.last = actualElement.head;
	expectedElement.last = expectedElement.head;
	for (int i = 0; i < 3; i++)
	{
		EXPECT_EQ(GetEntityStringView(actualElement.last->data), GetEntityStringView(expectedElement.last->data));
		actualElement.last = actualElement.last->next;
		expectedElement.last = expectedElement.last->next;
	}
}

TEST(PerimeterTests, IsPerimeterCorrect)
{
	triangle t = { 1, 2, 3 };
	EXPECT_EQ(Perimeter(t), 6);
	rectangle r = { 10, 20 };
	EXPECT_EQ(Perimeter(r), 60);
	circle c = { 10 };
	EXPECT_EQ (Perimeter(c), 62);
}

bool CompareFiles(string path1, string path2)
{
	string temp;
	ifstream File1(path1);
	vector<string> File1Lines;
	while (File1)
	{
		getline(File1, temp);
		File1Lines.push_back(temp);
	}
	ifstream File2(path2);
	vector<string> File2Lines;
	while (File2)
	{
		getline(File2, temp);
		File2Lines.push_back(temp);
	}
	if (File1Lines.size() != File2Lines.size())
		return false;
	for (int i = 0; i < (int)File1Lines.size(); i++)
		if (File1Lines[i] != File2Lines[i])
			return false;
	return true;
}


TEST(WriteTests, IsWriteCorrect)
{
	container data;
	InitContainer(data);
	AddElement(data, new shape({ shape::RECTANGLE, {10, 20}, 100 }));
	AddElement(data, new shape({ shape::CIRCLE, {25}, 200 }));
	AddElement(data, new shape({ shape::TRIANGLE, {18,41}, 300 }));
	
	ofstream WriteStream("../../ProcTests/ActualWriteFile.txt");
	OutContainer(data, WriteStream);
	EXPECT_TRUE(CompareFiles("../../ProcTests/ActualWriteFile.txt", "../../ProcTests/ExpectedWriteFile.txt"));
}

TEST(WriteTests, IsFilteredWriteCorrect)
{
	container data;
	InitContainer(data);
	AddElement(data, new shape({ shape::TRIANGLE, {1,2}, 400 }));
	AddElement(data, new shape({ shape::RECTANGLE, {10, 20}, 100 }));
	AddElement(data, new shape({ shape::RECTANGLE, {14, 40}, 100 }));
	AddElement(data, new shape({ shape::RECTANGLE, {100, 200}, 100 }));
	AddElement(data, new shape({ shape::CIRCLE, {100}, 200 }));
	AddElement(data, new shape({ shape::TRIANGLE, {1,3}, 400 }));
	AddElement(data, new shape({ shape::RECTANGLE, {100, 200}, 100 }));

	ofstream WriteStream("../../ProcTests/ActualFilteredWriteFile.txt");
	OutRectangles(data, WriteStream);
	EXPECT_TRUE(CompareFiles("../../ProcTests/ExpectedFilteredOutputFile.txt", "../../ProcTests/ExpectedFilteredOutputFile.txt"));
}

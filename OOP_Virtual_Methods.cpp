#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

// Task 1
class Shape
{
public:
	virtual void Show() const = 0;
	virtual void Save(FILE* file) = 0;
	virtual void Load(FILE* file) = 0;

	virtual ~Shape() = default;
};

class MyRectangle : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	
	MyRectangle(int x = 0, int y = 0, int width = 0, int height = 0)
		: x(x), y(y), width(width), height(height) {}
	
	void Show() const override
	{
		cout << "Rectangle" << endl;
		cout << "Position: (" << x << ", " << y << ")" << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
	}
	
	void Save(FILE* file) override
	{
		fprintf(file, "Rectangle %d %d %d %d\n", x, y, width, height);
	}

	void Load(FILE* file) override
	{
		int result = fscanf(file, "%d %d %d %d", &x, &y, &width, &height);

		if (result != 4)
		{
			cout << "Error loading Rectangle!" << endl;
			return;
		}
		
	}


};

class MyCircle : public Shape
{
private:
	int x;
	int y;
	int R;
public:
	MyCircle(int x = 0, int y = 0, int R = 0) : x(x), y(y), R(R) {}

	void Show() const override
	{
		cout << "Circle" << endl;
		cout << "Position: (" << x << ", " << y << ")" << endl;
		cout << "Radius: " << R << endl;
	}

	void Save(FILE* file) override
	{
		fprintf(file, "Circle %d %d %d\n", x, y, R);
	}

	void Load(FILE* file) override
	{
		int result = fscanf(file, "%d %d %d", &x, &y, &R);

		if (result != 3)
		{
			cout << "Error loading Circle!" << endl;
			return;
		}


	}


};

class MyEllipse : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	MyEllipse(int x = 0, int y = 0, int width = 0, int height = 0)
		: x(x), y(y), width(width), height(height) {}

	void Show() const override
	{
		cout << "Ellipse" << endl;
		cout << "Position: (" << x << ", " << y << ")" << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;
	}

	void Save(FILE* file) override
	{
		fprintf(file, "Ellipse %d %d %d %d\n", x, y, width, height);
	}

	void Load(FILE* file) override
	{
		int result = fscanf(file, "%d %d %d %d", &x, &y, &width, &height);

		if (result != 4)
		{
			cout << "Error loading Ellipse!" << endl;
			return;
		}


	}

};

//Task 2
class String
{
protected:
	char* arrChars;
public:
	String()
	{
		arrChars = new char[80 + 1];
		arrChars[0] = '\0';
	}

	String(const char* arrChars) :arrChars(nullptr)
	{
		if (arrChars == nullptr)
		{
			this->arrChars = new char[1];
			this->arrChars[0] = '\0';
		}
		else
		{
			size_t length = strlen(arrChars);
			this->arrChars = new char[length + 1];
			strcpy_s(this->arrChars, length + 1, arrChars);
		}
	}

	String(const String& other)
	{
		size_t length = strlen(other.arrChars);
		arrChars = new char[length + 1];
		strcpy_s(arrChars, length + 1, other.arrChars);
	}

	String& operator=(const String& other)
	{
		if (this == &other)
			return *this;

		size_t length = strlen(other.arrChars);
		char* newChars = new char[length + 1];
		strcpy_s(newChars, length + 1, other.arrChars);

		delete[] arrChars;
		arrChars = newChars;

		return *this;
	}

	size_t GetLength() const
	{
		return strlen(arrChars);
	}

	void ClearStr()
	{
		arrChars[0] = '\0';
	}
	
	String operator+(const String& other) const
	{

		size_t length1 = strlen(arrChars);
		size_t length2 = strlen(other.arrChars);

		char* allChars = new char[length1 + length2 + 1];

		strcpy_s(allChars, length1 + length2 + 1, arrChars);
		strcat_s(allChars, length1 + length2 + 1, other.arrChars);

		String result(allChars);

		delete[] allChars;

		return result;
	}

	String& operator+=(const String& other)
	{
		size_t length1 = strlen(arrChars);
		size_t length2 = strlen(other.arrChars);

		char* allChars = new char[length1 + length2 + 1];

		strcpy_s(allChars, length1 + length2 + 1, arrChars);
		strcat_s(allChars, length1 + length2 + 1, other.arrChars);

		delete[] arrChars;
		arrChars = allChars;

		return *this;
	}

	String operator*(const String& other) const
	{
		size_t length1 = strlen(arrChars);
		size_t length2 = strlen(other.arrChars);

		char* result = new char[length1 + 1];
		int similarity = 0;

		for (size_t i = 0; i < length1; i++)
		{
			for (size_t j = 0; j < length2; j++)
			{
				if (arrChars[i] == other.arrChars[j])
				{
					result[similarity] = arrChars[i];
					similarity++;
					break;
				}
			}
		}

		result[similarity] = '\0';
		String intersection = result;
		delete[] result;

		return intersection;
	}

	String operator/(const String& other) const
	{
		size_t length1 = strlen(arrChars);
		size_t length2 = strlen(other.arrChars);

		char* result = new char[length1 + 1];
		int similarity = 0;


		for (size_t i = 0; i < length1; i++)
		{
			bool check = false;

			for (size_t j = 0; j < length2; j++)
			{
				if (arrChars[i] == other.arrChars[j])
				{
					check = true;
					break;
				}
			}
			if (!check)
			{
				result[similarity] = arrChars[i];
				similarity++;
			}

		}

		result[similarity] = '\0';
		String difference = result;
		delete[] result;

		return difference;

	}

	bool operator==(const String& other) const
	{
		return strcmp(arrChars, other.arrChars) == 0;
	}

	bool operator!=(const String& other) const
	{
		return strcmp(arrChars, other.arrChars) != 0;
	}


	void show() const
	{
		cout << arrChars;
	}

	~String()
	{
		delete[] arrChars;
	}


	friend istream& operator>>(istream& is, String& str);
	friend ostream& operator<<(ostream& os, const String& str);

};

class BitString : public String
{
public:
	BitString() : String() {}

	BitString(const char* str) : String() 
	{
		if (str == nullptr)
			return;
		
		bool check = true;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] < '0' || str[i] > '1')
			{
				check = false;
				break;
			}
		}

		if (check)
		{
			delete[] arrChars;

			size_t length = strlen(str);
			arrChars = new char[length + 1];
			strcpy_s(arrChars, length + 1, str);
		}
	}

	BitString(const BitString& other) : String(other)
	{
		
	}
	BitString(const String& str) : String(str)
	{
	}

	void ChangeSign()
	{
		
		if (arrChars[0] == '1' || arrChars[0] == '\0')
			return;

		int i = 0;

		int length = strlen(arrChars);

		for (;i < length; i++)
		{
			if (arrChars[i] == '0')
			{
				arrChars[i] = '1';
			}
			else
			{
				arrChars[i] = '0';
			}
		}

		for (int i = length - 1; i >= 0; i--)
		{
			if (arrChars[i] == '0')
			{
				arrChars[i] = '1';
				break;
			}
			else
				arrChars[i] = '0';
		}

	}

	BitString& operator=(const BitString& other)
	{
	
		String::operator=(other);
		return *this;
	}

	BitString operator+(const BitString& other) const	
	{

		BitString a = String::operator+(other);
		return a;
	}

	BitString& operator+=(const BitString& other)
	{

		String::operator+=(other);
		return *this;
	}

	bool operator==(const BitString& other) const
	{
		return String::operator==(other);
	}

	bool operator!=(const BitString& other) const
	{
		return String::operator!=(other);
	}

	~BitString()
	{
	
	}

};

istream& operator>>(istream& is, String& str)
{
	char buffer[1024];

	is >> buffer;

	if (is)
	{
		size_t length = strlen(buffer);
		char* newChars = new char[length + 1];

		strcpy_s(newChars, length + 1, buffer);

		delete[] str.arrChars;
		str.arrChars = newChars;
	}

	return is;
}

ostream& operator<<(ostream& os, const String& str)
{
	os << str.arrChars;
	return os;
}


int main()
{
	// Task 1
	/*MyRectangle r(10, 20, 150, 80);
	MyCircle c(50, 60, 30);
	MyEllipse el(100, 120, 200, 100);
	
	FILE* file = fopen("figures.txt", "w");
	
	if (file == nullptr)
	{
		perror("File opening error");
		return 1;
	}

	const int SIZE = 3;

	Shape* shapes[SIZE]{ &r,&c,&el };
	
	for (int i = 0; i < SIZE; i++)
	{
		shapes[i]->Save(file);
	}

	fclose(file);

	file = fopen("figures.txt", "r");

	if (file == nullptr)
	{
		perror("File opening error");
		return 1;
	}

	int countShapes = 0;

	char line[100];


	while (fgets(line, sizeof(line), file) != nullptr)
	{
		if (line[0] != '\n')
		{
			countShapes++;
		}
	}

	Shape** loadedShapes = new Shape*[countShapes];
	int count = 0;

	rewind(file);
	
	char type[20];
	while (fscanf(file, "%19s", type) == 1 && count < countShapes)
	{
		if (strcmp(type, "Circle") == 0)
		{
			loadedShapes[count] = new MyCircle();
		}
		else if (strcmp(type, "Rectangle") == 0)
		{
			loadedShapes[count] = new MyRectangle();
		}
		else if (strcmp(type, "Ellipse") == 0)
		{
			loadedShapes[count] = new MyEllipse();
		}
		else
		{
			break;
		}

		loadedShapes[count]->Load(file);
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		loadedShapes[i]->Show();
		cout << "----------------" << endl;
	}
	
	for (int i = 0; i < count; i++)
	{
		delete loadedShapes[i];
	}

	delete[] loadedShapes;

	fclose(file);*/


	// Task 2
	BitString a("0101");
	BitString b("0011");

	cout << "a: ";
	a.show();
	cout << endl;
	cout << "b: ";
	b.show();
	cout << endl;
	BitString c(a);
	cout << "Copy of a: ";
	c.show();
	cout << endl;
	BitString d;
	d = b;
	cout << "d = b: ";
	d.show();
	cout << endl;
	BitString negative("0101");
	negative.ChangeSign();
	cout << "Change sign: ";
	negative.show();
	cout << endl;
	BitString sum = a + b;
	cout << "a + b: ";
	sum.show();
	cout << endl;
	a += b;
	cout << "a += b: ";
	a.show();
	cout << endl;
	cout << boolalpha;
	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;



	return 0;

}


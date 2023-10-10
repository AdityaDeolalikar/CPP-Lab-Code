// Assignment 4 :

#include <iostream>
using namespace std;

typedef struct
{
  float coefficient;
  int exponent;
} polynomial;

class sample
{
private:
  int choice;
  polynomial poly[100];
  int total;

public:
  void read()
  {
    cout << endl
         << "enter the total term : " << endl;
    cin >> total;
    for (int i = 0; i < total; i++)
    {

      cout << "enter the coefficient : " << endl;
      cin >> poly[i].coefficient;
      cout << "enter the exponent : " << endl;
      cin >> poly[i].exponent;
    }
  }
  void display()
  {
    cout << endl;

    cout << "Your polynomial is : " << endl;
    for (int i = 0; i < total; i++)
    {
      if (poly[i].exponent == 1)
      {
        cout << poly[i].coefficient;
      }
      else
      {
        cout << poly[i].coefficient << "x^" << poly[i].exponent;
      }

      if (i != total - 1)
      {
        cout << " + ";
      }
    }
  }

  void add(sample b)
  {
    int a = 0, bi = 0;
    sample c;
    int j = 0;
    while (b.total > bi || total > a)
    {
      if (b.poly[bi].exponent == poly[a].exponent) // Degree matched to add
      {
        c.poly[j].exponent = b.poly[bi].exponent;
        c.poly[j].coefficient = b.poly[bi].coefficient + poly[a].coefficient;
        j++;
        a++;
        bi++;
      }
      else if (b.poly[bi].exponent >= poly[a].exponent)
      {
        c.poly[j].exponent = b.poly[bi].exponent;
        c.poly[j].coefficient = b.poly[bi].coefficient;
        j++;
        bi++;
      }
      else
      {
        c.poly[j].exponent = poly[a].exponent;
        c.poly[j].coefficient = poly[a].coefficient;
        j++;
        a++;
      }
    }
    while (total > a)
    {
      c.poly[j].exponent = poly[a].exponent;
      c.poly[j].coefficient = poly[a].coefficient;
      j++;
      a++;
    }

    while (b.total > bi)
    {
      c.poly[j].exponent = b.poly[bi].exponent;
      c.poly[j].coefficient = b.poly[bi].coefficient;
      j++;
      bi++;
    }

    c.total = j;
    c.display();
  }
};
int main()
{
  int choice;
  cout << "Enter your choice :\n1.Only read and display the polynomial\n2.Add the two polynomials" << endl;
  cin >> choice;
  sample a, b, c;
  switch (choice)
  {
  case 1:
    a.read();
    a.display();
    break;
  case 2:
    a.read();
    a.display();
    b.read();
    b.display();
    a.add(b);
    break;

  default:
    cout << "Enter the valid choice ! " << endl;
    break;
  }
}

/*
Enter your choice :
1.Only read and display the polynomial
2.Add the two polynomials

2

enter the total term :
2
enter the coefficient :
2
enter the exponent :
2
enter the coefficient :
2
enter the exponent :
1

Your polynomial is :
2x^2 + 2
enter the total term :
2
enter the coefficient :
2
enter the exponent :
2
enter the coefficient :
1
enter the exponent :
1

Your polynomial is :
2x^2 + 1
Your polynomial is :
4x^2 + 3
 */
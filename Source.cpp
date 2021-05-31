#include<iostream>
#include<cmath>
#include<Windows.h>
using namespace std;
class Singleton {
public:
	 Singleton(int a, int b, int c, int d) { x = a; x1 = b; y = c; y1 = d; }
	 int x, x1, y, y1;
	 static Singleton *Kvadrat;
	 Singleton() {};
	 Singleton(Singleton&other) = delete;
	 void operator=(const static Singleton&d) = delete;
	 static Singleton*GetInstance(int &x, int&x1, int&y, int&y1);
	 static Singleton**DATA(int n);
	 int GetX() { return x; }
	 int GetX1() { return x1; }
	 int GetY() { return y; }
	 int GetY1() { return y1; }
};
Singleton *Singleton::Kvadrat = NULL;
Singleton *Singleton::GetInstance(int &x, int&x1, int&y, int&y1) {
	 if (Kvadrat == NULL) {
		  Kvadrat = new Singleton(x, x1, y, y1);
	 }
	 return Kvadrat;
}
void Prysvoity(Singleton &f, Singleton &d) {
	 f.x = d.x;
	 f.y = d.y;
	 f.x1 = d.x1;
	 f.y1 = f.y1;
}
void Print(Singleton &d) {
	 cout << "x:" << d.x << " x1:" << d.x1 << " y:" << d.y << " y1:" << d.y1 << endl;
}
Singleton**Singleton::DATA(int n) {
				Singleton **DATA = new Singleton*[n];
				cout << "\n Введіть дані: \n";
				for (int i = 0; i < n; i++) {
					 int x, x1, y, y1;
					 cin >> x >> x1 >> y >> y1;
					 DATA[i] = new Singleton(x, x1, y, y1);
				}
				return DATA;
		  }
double Distance(Singleton&d) {
	 double Distance;
	 Distance = sqrt((pow(d.GetX() - d.GetX1(), 2) + pow(d.GetY() - d.GetY1(), 2)));
	 return Distance;
}
		  int main() {
				SetConsoleOutputCP(1251);
				SetConsoleCP(1251);
				int n;
				cout << "\n Введіть кількість елементів:";
				cin >> n;
				Singleton **DATA = new Singleton*[n];
				DATA = Singleton::DATA(n);
				int l = 0;
				for (int i = 0; i < n; i++) {
					 Singleton obj;
					 if ((i + 1) == n)
						  break;
					 if (Distance(*DATA[i]) < Distance(*DATA[i+1])) {
						  l = i;
						  while (Distance(*DATA[l]) < Distance(*DATA[l + 1])) {
								Prysvoity(obj, *DATA[l]);
								Prysvoity(*DATA[l], *DATA[l + 1]);
								Prysvoity(*DATA[l + 1], obj);
								if (l == 0)
									 break;
								l--;
						  }
					 }
				}
				cout << "\n Відсортований масив:" << endl;
				for (int i = 0; i < n; i++) {
					 Print(*DATA[i]);
				}
				return 0;
		  }
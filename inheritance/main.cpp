#include <QCoreApplication>
#include <QDebug>
#include <map>
using namespace std;

class A {
public:
	int _a = 1;
};
class B : public A {
public:
	int _b = 2;
};

class Abstraciya : public map<int, A*> {
public:
	Abstraciya(const map<int, B*>& b)
	{
		if (b.size() > 0) {
			qDebug() << b.at(0)->_b;
		}
	}
};

void func(const map<int, A*> is_a)
{
	if (is_a.size() > 0) {
		qDebug() << is_a.at(0)->_a;
	}
}
int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
	B _is_b;
	map<int, B*> _b1;
	_b1[0] = &_is_b;
	func(Abstraciya(_b1));
	return a.exec();
}

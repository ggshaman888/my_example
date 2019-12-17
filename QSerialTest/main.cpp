#include <QtWidgets/QApplication>
#include "consoleform.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	ConsoleForm is_f;
	is_f.isRun();

	return a.exec();
}

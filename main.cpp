#include "Application.h"

using namespace vrt;

int main()
{
	Application app("name1.txt", "name2.txt");
	app.run();
	return 0;
}
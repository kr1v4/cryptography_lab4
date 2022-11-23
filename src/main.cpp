#include "core/Application/Application.hpp"

int main()
{
	std::unique_ptr<Application> app = std::make_unique<Application>();

	app->start();

	return 0;
}
#include "App.hpp"
#include <memory>


int main()
{

	auto exe{ std::make_unique<App>() };
	exe->Run();
}
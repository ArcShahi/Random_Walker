#include "Walker.hpp"

sf::Vector2f Walker::nextStep()
{

	auto step{ arc::randomi(0,8) };

	switch (step)
	{
	case 0:
		return { 1.f,0.f };
		break;
	case 1:
		return { -1.f,0.f };
		break;
	case 2:
		return { 0.f,1.f };
		break;
	case 3:
		return { 0.f,-1.f };
		break;
	case 4:
		return { 0.f,0.f };
		break;
	case 5:
		return { 1.f,1.f };
		break;
	case 6:
		return { -1.f,-1.f };
		break;
	case 7:
		return { 1.f,-1.f };
		break;
	case 8:
		return { -1.f,1.f };

	default:
		break;
	}
}

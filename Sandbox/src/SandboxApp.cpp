#include <Cage.h>

class Sandbox : public Cage::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Cage::Application* Cage::CreateApplication()
{
	return new Sandbox();
}
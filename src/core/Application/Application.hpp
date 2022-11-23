#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <memory>

class Application
{
	public:
	
		Application() = default;

	public:

		void start();

	public:

		Application(const Application&) = delete;
		Application(Application&&) = delete;

		Application& operator=(Application&&) = delete;
		Application& operator=(Application&) = delete;

	private:

		void show_me();
};
#endif
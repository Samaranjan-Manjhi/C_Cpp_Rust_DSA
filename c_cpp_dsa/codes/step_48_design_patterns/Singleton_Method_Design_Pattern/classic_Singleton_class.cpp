#include <iostream>

using namespace std;

class classicSingleton {
	private:
		static classicSingleton* instance;
		classicSingleton() {};
	public:
		classicSingleton (const classicSingleton&) = delete;
		classicSingleton& operator=(const classicSingleton&) = delete;

		static classicSingleton* getInstance()
		{
			if(instance == nullptr)
			{
				instance = new classicSingleton();
			}
			return instance;
		}
		void display() 
		{
		        cout << "Singleton instance." << endl;
    		}
};

classicSingleton* classicSingleton::instance = nullptr;

int main()
{
	classicSingleton* inc = classicSingleton::getInstance();
	inc->display();

	delete inc;

	return 0;
}

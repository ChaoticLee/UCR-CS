//AbstractFactoryICE.cpp : containing the main function and all classes

#include <iostream>
#define MACOS

using namespace std; 
/** Abstract base product. It should define as interface which is common to all Products. Clients will work with products thoruhg this interface. **/
class Widget{
public: 
  virtual void draw () = 0; 
};
//** concreate product family 1**//
class LinuxButton : public Widget {
public: void draw(0 {cout << "LinuxButton\n";}
};
class LinuxMenu : public Widget {
public: 
  void draw() {cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget {
public: 
  void draw() {cout << "WindowsMenu\n"; }
};

//** Client receives a facrot object from its creator. then client works with facroties thorugh abstract interface. They don't konw concrete classes of facroties. Because of this, you interchange concrete factories without breaking clients.**//
class Client {
private: 
  Factory *factory;

public: 
  client(Factory *f){
    factory = f; 
  }
void draw() {
  Widget *w = factory -> create_button();
  w->draw();
}
};

//**Now that nasty switch statement is needed only once to pick and create a proper factory. **//

int main()
{
  #ifdef LINUX
    Factory* factory = LinuxButton->Client; 
  #else
    Factory* factory = WindowsButton->Client; 
  #endif
    Client *c = new Client(factory);
  c->draw();
}

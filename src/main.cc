
#include <iostream>
#include <gtkmm.h>

#include "MyTreeView.h"

using namespace std;

int main(int argc, char ** argv) {
    
    cout << "\nAll is very very good" << endl;
    
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.ashon-associates.cpp.treeview");
    MyTreeView window;
    return app->run(window);

}

/* 
 * File:   MyTreeView.cc
 * Author: yinka
 * 
 * Created on 5 February 2016, 10:53 PM
 */

#ifndef __MY_TREE_VIEW_H__
#define __MY_TREE_VIEW_H__

#include <gtkmm/window.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treeviewcolumn.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/liststore.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/cellrendererprogress.h>

class MyTreeView : public Gtk::Window {
public:
    MyTreeView();
    MyTreeView(const MyTreeView &orig);
    virtual ~MyTreeView();

private:

protected:
    
    // Handlers
    void onQuitButtonClicked();

    // Tree Model columns:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(m_col_id);
            add(m_col_name);
            add(m_col_number);
            add(m_col_percentage);
        }
        Gtk::TreeModelColumn<unsigned int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        Gtk::TreeModelColumn<short> m_col_number;
        Gtk::TreeModelColumn<int> m_col_percentage;
    };

    ModelColumns m_Columns;

    // Protected methods
    void setupUserInterface();

    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_BtnQuit;
    Gtk::Box m_Vbox;
    Gtk::TreeView m_TreeView;
    Gtk::ScrolledWindow m_ScrolledWindow;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

};

#endif /* __MY_TREE_VIEW_H__ */


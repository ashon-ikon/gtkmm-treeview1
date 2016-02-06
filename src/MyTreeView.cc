/* 
 * File:   MyTreeView.cc
 * Author: yinka
 * 
 * Created on 5 February 2016, 10:53 PM
 */

#include <iostream>
#include <typeinfo>
#include "MyTreeView.h"

MyTreeView::MyTreeView() :
m_BtnQuit("Quit"),
m_Vbox(Gtk::ORIENTATION_VERTICAL) {
    this->setupUserInterface();
}

MyTreeView::MyTreeView(const MyTreeView& orig) {

}

MyTreeView::~MyTreeView() {

}

void MyTreeView::onQuitButtonClicked() {
    std::cout << "Quit button clicked" << std::endl;
    this->hide();
}

void MyTreeView::setupUserInterface() {
    this->set_title("Gtk::TreeView (ListStore) example");
    this->set_border_width(5);
    this->set_default_size(600, 300);

    // Add the root container
    this->add(m_Vbox);

    // Add the tree view inside a scrolledWindow, with the button underneath
    m_ScrolledWindow.add(m_TreeView);

    // Only show the scrollbars when they are necessary
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_Vbox.pack_start(m_ScrolledWindow);
    m_Vbox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);


    m_ButtonBox.pack_start(m_BtnQuit, Gtk::PACK_SHRINK);
    m_ButtonBox.set_border_width(5);
    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);

    m_BtnQuit.signal_clicked().connect(sigc::mem_fun(*this, &MyTreeView::onQuitButtonClicked));

    // Create the TreeModel
    this->m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(this->m_refTreeModel);

    // Fill the tree view's model
    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 1;
    row[m_Columns.m_col_name] = "Billy Bob";
    row[m_Columns.m_col_number] = 10;
    row[m_Columns.m_col_percentage] = 33;

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 2;
    row[m_Columns.m_col_name] = "Yinka Ashon";
    row[m_Columns.m_col_number] = 6;
    row[m_Columns.m_col_percentage] = 12;

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 3;
    row[m_Columns.m_col_name] = "Mikunmi";
    row[m_Columns.m_col_number] = 40;
    row[m_Columns.m_col_percentage] = 50;

    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Name", m_Columns.m_col_name);
    m_TreeView.append_column_numeric("Number", m_Columns.m_col_number,
            "%010d" /* 10 digits, using leading zeros. */);
    // Display a progress bar
    Gtk::CellRendererProgress * cell = Gtk::manage(new Gtk::CellRendererProgress);
    int cols_count = m_TreeView.append_column("Some percentage", *cell);
    auto pColumn = m_TreeView.get_column(cols_count - 1);
    
    if (pColumn) {
        pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
    }

    // Make all the columns reorderable:
    // This is not necessary, but it's nice to show the feature
    for (guint i = 0; i < 2; i++) {
        Gtk::TreeViewColumn* column = m_TreeView.get_column(i);
        column->set_reorderable();
    }
    
    // Show our work of art
    this->show_all_children();
}
#ifndef INTERFACE_H
#define INTERFACE_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/paned.h>
#include <gtkmm/hvpaned.h>
#include <gtkmm/toolbar.h>
#include <gtkmm/image.h>

class Interface : public Gtk::Window {
public:
  Interface();
  virtual ~Interface();

protected:
  //Signal handlers:
  void on_button_clicked( Glib::ustring data );

  //Widgets:
  Gtk::VPaned headbox; // Master setup, everything falls under this in some way
    Gtk::Notebook selector; // This are the tabs that select which interface the user is working with
      Gtk::VPaned designer_vsplit;  // Designer tab main box
        Gtk::HPaned designer_viewport_hsplit;  // Splits the viewport
          Gtk::DrawingArea designer_viewport; // The actual viewport
          Gtk::ScrolledWindow designer_viewport_sidebar;  // The viewport sidebar. Using this instead of the normal sidebar for better customizability.
            Gtk::VBox designer_viewport_sidebar_splitter;
              Gtk::Button designer_viewport_sidebar_tmpbutton1;  // Just something temporary to be the sidebar
              Gtk::Button designer_viewport_sidebar_tmpbutton2;
              Gtk::Button designer_viewport_sidebar_tmpbutton3;
              Gtk::Button designer_viewport_sidebar_tmpbutton4;
              Gtk::Button designer_viewport_sidebar_tmpbutton5;
        Gtk::HPaned spreadsheet_config_hsplit;
          Gtk::ScrolledWindow spreadsheet_scroll;
            Gtk::VBox spreadsheet_v;
              Gtk::Button spreadsheet_tmpbutton1;
              Gtk::Button spreadsheet_tmpbutton2;
              Gtk::Button spreadsheet_tmpbutton3;
              Gtk::Button spreadsheet_tmpbutton4;
              Gtk::Button spreadsheet_tmpbutton5;
          Gtk::ScrolledWindow spreadconfig_scroll;
            Gtk::VBox spreadconfig_v;
              Gtk::Button spreadconfig_tmpbutton1; 
              Gtk::Button spreadconfig_tmpbutton2; 
              Gtk::Button spreadconfig_tmpbutton3; 
              Gtk::Button spreadconfig_tmpbutton4; 
      Gtk::HPaned config_hsplit;
        Gtk::ScrolledWindow config_objects_scroll;
          Gtk::VBox config_objects;
            Gtk::Button config_tmpbutton1;
            Gtk::Button config_tmpbutton2;
            Gtk::Button config_tmpbutton3;
            Gtk::Button config_tmpbutton4;
            Gtk::Button config_tmpbutton5;
        Gtk::ScrolledWindow config_options_scroll;
          Gtk::Button config_options_tmpbutton1;
      Gtk::Notebook tolerancer_tabs;
        Gtk::HPaned tolerancer_objects_split;
          Gtk::ScrolledWindow tolerancer_objects_scroll;
            Gtk::VBox tolerancer_objects;
              Gtk::Button tolerancer_object_tmpbutton1;
              Gtk::Button tolerancer_object_tmpbutton2;
              Gtk::Button tolerancer_object_tmpbutton3;
              Gtk::Button tolerancer_object_tmpbutton4;
              Gtk::Button tolerancer_object_tmpbutton5;
          Gtk::HPaned tolerancer_config_split;
            Gtk::ScrolledWindow tolerancer_objconfig_scroll;
              Gtk::Button tolerancer_objconfig_tmpbutton;
            Gtk::ScrolledWindow tolerancer_config_scroll;
              Gtk::Button tolerancer_config_tmpbutton;

        Gtk::HPaned tolerancer_controls;
          Gtk::HPaned tolerancer_controls_option_split;
            Gtk::ScrolledWindow tolerancer_controls_broad;
              Gtk::VBox tolerancer_broad_options_vert;
                Gtk::Button broad_option_tmp1;
                Gtk::Button broad_option_tmp2;
                Gtk::Button broad_option_tmp3;
                Gtk::Button broad_option_tmp4;
                Gtk::Button broad_option_tmp5;
             Gtk::ScrolledWindow tolerancer_controls_focused;
              Gtk::VBox tolerancer_focused_options_vert; 
                Gtk::Button focused_option_tmp1;
                Gtk::Button focused_option_tmp2;
                Gtk::Button focused_option_tmp3;
          Gtk::ScrolledWindow tolerancer_optionedit_scroll;
            Gtk::VBox tolerancer_optionedit;
              Gtk::Button tolerancer_option_tmp1;
              Gtk::Button tolerancer_option_tmp2;
              Gtk::Button tolerancer_option_tmp3;
        Gtk::Button results;
      Gtk::Button analysis;


};

#endif 
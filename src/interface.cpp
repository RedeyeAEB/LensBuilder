#include "interface.h"
#include <iostream> 

Interface::Interface() 
  : designer_viewport_sidebar_tmpbutton1( "Option 1" ), // Begin object widgets
    designer_viewport_sidebar_tmpbutton2( "Option 2" ),
    designer_viewport_sidebar_tmpbutton3( "Option 3" ),
    designer_viewport_sidebar_tmpbutton4( "Option 4" ),
    designer_viewport_sidebar_tmpbutton5( "Option 5" ),
    spreadsheet_tmpbutton1( "Optic 1" ),
    spreadsheet_tmpbutton2( "Optic 2" ),
    spreadsheet_tmpbutton3( "Optic 3" ),
    spreadsheet_tmpbutton4( "Optic 4" ),
    spreadsheet_tmpbutton5( "Optic 5" ),
    spreadconfig_tmpbutton1( "Config 1" ),
    spreadconfig_tmpbutton2( "Config 2" ),
    spreadconfig_tmpbutton3( "Config 3" ),
    spreadconfig_tmpbutton4( "Config 4" ),
    config_tmpbutton1("Optic 1"),
    config_tmpbutton2("Optic 2"),
    config_tmpbutton3("Optic 3"),
    config_tmpbutton4("Optic 4"),
    config_tmpbutton5("Optic 5"),
    config_options_tmpbutton1("[WIP] Configuration Panel"),
    tolerancer_object_tmpbutton1("Optic 1"),
    tolerancer_object_tmpbutton2("Optic 2"),
    tolerancer_object_tmpbutton3("Optic 3"),
    tolerancer_object_tmpbutton4("Optic 4"),
    tolerancer_object_tmpbutton5("Optic 5"),
    tolerancer_objconfig_tmpbutton("Object Setup"),
    tolerancer_config_tmpbutton("Tolerancer Setup"),
    broad_option_tmp1("Category 1"),
    broad_option_tmp2("Category 2"),
    broad_option_tmp3("Category 3"),
    broad_option_tmp4("Category 4"),
    broad_option_tmp5("Category 5"),
    focused_option_tmp1("Detail 1"),
    focused_option_tmp2("Detail 2"),
    focused_option_tmp3("Detail 3"),
    tolerancer_option_tmp1("Config 1"),
    tolerancer_option_tmp2("Config 2"),
    tolerancer_option_tmp3("Config 3")
{
  // Window setup
  set_title( "LensBuilder" );
  set_default_size( 1280, 720 );  // Remember: all starting positions are relative to this.

  // Signal handlers
  tolerancer_object_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(1) Not implemented!"));
  tolerancer_object_tmpbutton2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(2) Not implemented!"));
  tolerancer_object_tmpbutton3.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(3) Not implemented!"));
  tolerancer_object_tmpbutton4.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(4) Not implemented!"));
  tolerancer_object_tmpbutton5.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(5) Not implemented!"));
  tolerancer_objconfig_tmpbutton.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "Objconfig"));
  tolerancer_config_tmpbutton.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "Tolconfig"));
  config_options_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(cot) Not implemented!"));
  config_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(1) Not implemented!"));
  config_tmpbutton2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(2) Not implemented!"));
  config_tmpbutton3.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(3) Not implemented!"));
  config_tmpbutton4.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(4) Not implemented!"));
  config_tmpbutton5.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "(5) Not implemented!"));
  designer_viewport_sidebar_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "d1"));
  designer_viewport_sidebar_tmpbutton2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "d2"));
  designer_viewport_sidebar_tmpbutton3.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "d3"));
  designer_viewport_sidebar_tmpbutton4.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "d4"));
  designer_viewport_sidebar_tmpbutton5.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "d5"));
  spreadsheet_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "s1"));
  spreadsheet_tmpbutton2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "s2"));
  spreadsheet_tmpbutton3.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "s3"));
  spreadsheet_tmpbutton4.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "s4"));
  spreadsheet_tmpbutton5.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "s5"));
  spreadconfig_tmpbutton1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "r1"));
  spreadconfig_tmpbutton2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "r2"));
  spreadconfig_tmpbutton3.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "r3"));
  spreadconfig_tmpbutton4.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &Interface::on_button_clicked), "r4"));

  // Start creating GUI structure
  add(headbox); // Add head
  headbox.pack1(selector); // Then start building structure
    headbox.set_position(720*9.5/10);
    headbox.set_wide_handle();
    selector.append_page(designer_vsplit, "Layout");
      designer_vsplit.set_wide_handle();
      designer_vsplit.set_position(720*9.5/10*3/5);  // Top is 3/5 of vertical area by default
      designer_vsplit.pack1(designer_viewport_hsplit);
        designer_viewport_hsplit.set_wide_handle();
        designer_viewport_hsplit.set_position(1280*7/10); // Right is 3/10 of horizontal area by default
        designer_viewport_hsplit.pack1(designer_viewport);
        designer_viewport_hsplit.pack2(designer_viewport_sidebar);
          designer_viewport_sidebar.set_overlay_scrolling(true);
          designer_viewport_sidebar.add(designer_viewport_sidebar_splitter);
            designer_viewport_sidebar_splitter.add(designer_viewport_sidebar_tmpbutton1);
            designer_viewport_sidebar_splitter.add(designer_viewport_sidebar_tmpbutton2);
            designer_viewport_sidebar_splitter.add(designer_viewport_sidebar_tmpbutton3);
            designer_viewport_sidebar_splitter.add(designer_viewport_sidebar_tmpbutton4);
            designer_viewport_sidebar_splitter.add(designer_viewport_sidebar_tmpbutton5);
      designer_vsplit.pack2(spreadsheet_config_hsplit);
        spreadsheet_config_hsplit.set_wide_handle();
        spreadsheet_config_hsplit.set_position(1280*8/10);
        spreadsheet_config_hsplit.pack1(spreadsheet_scroll);
          spreadsheet_scroll.set_overlay_scrolling(true);
          spreadsheet_scroll.add(spreadsheet_v);
            spreadsheet_v.add(spreadsheet_tmpbutton1);
            spreadsheet_v.add(spreadsheet_tmpbutton2);
            spreadsheet_v.add(spreadsheet_tmpbutton3);
            spreadsheet_v.add(spreadsheet_tmpbutton4);
            spreadsheet_v.add(spreadsheet_tmpbutton5);
        spreadsheet_config_hsplit.pack2(spreadconfig_scroll);    
          spreadconfig_scroll.set_overlay_scrolling(true);
          spreadconfig_scroll.add(spreadconfig_v);
            spreadconfig_v.add(spreadconfig_tmpbutton1);
            spreadconfig_v.add(spreadconfig_tmpbutton2);
            spreadconfig_v.add(spreadconfig_tmpbutton3);
            spreadconfig_v.add(spreadconfig_tmpbutton4);          
    selector.append_page(config_hsplit, "Config");
      config_hsplit.set_wide_handle();
      config_hsplit.set_position(1280*1.5/10);
      config_hsplit.pack1(config_objects_scroll);
        config_objects_scroll.set_overlay_scrolling(true);
        config_objects_scroll.add(config_objects);
          config_objects.add(config_tmpbutton1);
          config_objects.add(config_tmpbutton2);
          config_objects.add(config_tmpbutton3);
          config_objects.add(config_tmpbutton4);
          config_objects.add(config_tmpbutton5);
      config_hsplit.pack2(config_options_scroll);
        config_options_scroll.set_overlay_scrolling(true);
        config_options_scroll.add(config_options_tmpbutton1);
    selector.append_page(tolerancer_tabs, "Tolerancer");
      tolerancer_tabs.append_page(tolerancer_objects_split, "Objects");
        tolerancer_objects_split.set_wide_handle();
        tolerancer_objects_split.set_position(1280*1.5/10);
        tolerancer_objects_split.pack1(tolerancer_objects_scroll);
          tolerancer_objects_scroll.set_overlay_scrolling(true);
          tolerancer_objects_scroll.add(tolerancer_objects);
            tolerancer_objects.add(tolerancer_object_tmpbutton1);
            tolerancer_objects.add(tolerancer_object_tmpbutton2);
            tolerancer_objects.add(tolerancer_object_tmpbutton3);
            tolerancer_objects.add(tolerancer_object_tmpbutton4);
            tolerancer_objects.add(tolerancer_object_tmpbutton5);
        tolerancer_objects_split.pack2(tolerancer_config_split);
          tolerancer_config_split.set_wide_handle();
          tolerancer_config_split.pack1(tolerancer_objconfig_scroll);
            tolerancer_objconfig_scroll.set_overlay_scrolling(true);
            tolerancer_objconfig_scroll.add(tolerancer_objconfig_tmpbutton);
          tolerancer_config_split.pack2(tolerancer_config_scroll);
            tolerancer_config_scroll.set_overlay_scrolling(true);
            tolerancer_config_scroll.add(tolerancer_config_tmpbutton);
      //Controls page
      tolerancer_tabs.append_page(tolerancer_controls, "Controls");
        tolerancer_controls.set_wide_handle();
        tolerancer_controls.set_position(1280*3/10);
        tolerancer_controls.pack1(tolerancer_controls_option_split);
          tolerancer_controls_option_split.set_wide_handle();
          tolerancer_controls_option_split.pack1(tolerancer_controls_broad);
            tolerancer_controls_broad.add(tolerancer_broad_options_vert);
              tolerancer_broad_options_vert.add(broad_option_tmp1);
              tolerancer_broad_options_vert.add(broad_option_tmp2);
              tolerancer_broad_options_vert.add(broad_option_tmp3);
              tolerancer_broad_options_vert.add(broad_option_tmp4);
              tolerancer_broad_options_vert.add(broad_option_tmp5);
          tolerancer_controls_option_split.pack2(tolerancer_controls_focused);
            tolerancer_controls_focused.add(tolerancer_focused_options_vert);
              tolerancer_focused_options_vert.add(focused_option_tmp1);
              tolerancer_focused_options_vert.add(focused_option_tmp2);
              tolerancer_focused_options_vert.add(focused_option_tmp3);
        tolerancer_controls.pack2(tolerancer_optionedit_scroll);
          tolerancer_optionedit_scroll.add(tolerancer_optionedit);
            tolerancer_optionedit.add(tolerancer_option_tmp1);
            tolerancer_optionedit.add(tolerancer_option_tmp2);
            tolerancer_optionedit.add(tolerancer_option_tmp3);
      // Results page
      tolerancer_tabs.append_page(results, "Results");
    selector.append_page(analysis, "Analysis");

  // Then show everything, from the furthest out structures to eventually headbox
  analysis.show();
  results.show();
  // Controls page
  tolerancer_option_tmp1.show();
  tolerancer_option_tmp2.show();
  tolerancer_option_tmp3.show();
  tolerancer_optionedit.show();
  tolerancer_optionedit_scroll.show();
  focused_option_tmp1.show();
  focused_option_tmp2.show();
  focused_option_tmp3.show();
  tolerancer_focused_options_vert.show();
  tolerancer_controls_focused.show();
  broad_option_tmp1.show();
  broad_option_tmp2.show();
  broad_option_tmp3.show();
  broad_option_tmp4.show();
  broad_option_tmp5.show();
  tolerancer_broad_options_vert.show();
  tolerancer_controls_broad.show();
  tolerancer_controls_option_split.show();
  tolerancer_controls.show();
  // Objects page
  tolerancer_config_tmpbutton.show();
  tolerancer_config_scroll.show();
  tolerancer_objconfig_tmpbutton.show();
  tolerancer_objconfig_scroll.show();
  tolerancer_config_split.show();
  tolerancer_object_tmpbutton1.show();
  tolerancer_object_tmpbutton2.show();
  tolerancer_object_tmpbutton3.show();
  tolerancer_object_tmpbutton4.show();
  tolerancer_object_tmpbutton5.show();
  tolerancer_objects.show();
  tolerancer_objects_scroll.show();
  tolerancer_objects_split.show();
  tolerancer_tabs.show();
  // Config tab stuff
  config_options_tmpbutton1.show();
  config_options_scroll.show();
  config_tmpbutton1.show();
  config_tmpbutton2.show();
  config_tmpbutton3.show();
  config_tmpbutton4.show();
  config_tmpbutton5.show();
  config_objects.show();
  config_objects_scroll.show();
  config_hsplit.show();
  // Layout control things
  config_options_tmpbutton1.show();
  config_hsplit.show();
  designer_viewport_sidebar_tmpbutton1.show();
  designer_viewport_sidebar_tmpbutton2.show();
  designer_viewport_sidebar_tmpbutton3.show();
  designer_viewport_sidebar_tmpbutton4.show();
  designer_viewport_sidebar_tmpbutton5.show();
  designer_viewport_sidebar_splitter.show();
  spreadconfig_tmpbutton1.show();
  spreadconfig_tmpbutton2.show();
  spreadconfig_tmpbutton3.show();
  spreadconfig_tmpbutton4.show();
  spreadconfig_v.show();
  spreadconfig_scroll.show();
  spreadsheet_tmpbutton1.show();
  spreadsheet_tmpbutton2.show();
  spreadsheet_tmpbutton3.show();
  spreadsheet_tmpbutton4.show();
  spreadsheet_tmpbutton5.show();
  spreadsheet_v.show();
  spreadsheet_scroll.show();
  designer_viewport_sidebar.show();
  designer_viewport.show();
  spreadsheet_config_hsplit.show();
  designer_viewport_hsplit.show();
  designer_vsplit.show();
  // Primary control things
  selector.show();
  headbox.show();
}

Interface::~Interface()
{
}

void Interface::on_button_clicked(Glib::ustring data)
{
  std::cout << data << std::endl;
}

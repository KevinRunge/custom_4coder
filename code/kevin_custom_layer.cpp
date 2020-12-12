/*
4coder kevin_custom_layer.cpp - Supplies the custom layer bindings 
*/

// TOP

#if !defined(FCODER_DEFAULT_BINDINGS_CPP)
#define FCODER_DEFAULT_BINDINGS_CPP

// NOTE(Kevin): use the customized version :)
#include "kevin_custom_include.cpp"
#include "kevin_custom_primitive_highlight.cpp"
#include "kevin_custom_scope_highlight.cpp"

// NOTE(allen): Users can declare their own managed IDs here.

#if !defined(META_PASS)
#include "generated/managed_id_metadata.cpp"
#endif

void
custom_layer_init(Application_Links *app){
    Thread_Context *tctx = get_thread_context(app);
    
    // NOTE(allen): setup for default framework
    default_framework_init(app);
    
    // NOTE(allen): default hooks and command maps
    set_all_default_hooks(app);
    mapping_init(tctx, &framework_mapping);
#if OS_MAC
    setup_mac_mapping(&framework_mapping, mapid_global, mapid_file, mapid_code);
#else
    setup_default_mapping(&framework_mapping, mapid_global, mapid_file, mapid_code);
#endif
    
    // NOTE(Kevin): custom bindings
    MappingScope();
    SelectMapping(&framework_mapping);
    
    SelectMap(mapid_global);
    Bind(open_panel_hsplit, KeyCode_Minus, KeyCode_Control);
    Bind(open_panel_vsplit, KeyCode_BackwardSlash, KeyCode_Control);
    Bind(close_panel, KeyCode_Tick, KeyCode_Control);
    Bind(open_all_code_recursive, KeyCode_Equal, KeyCode_Shift, KeyCode_Control);
    Bind(close_all_code, KeyCode_Minus, KeyCode_Shift, KeyCode_Control);
}

#endif //FCODER_DEFAULT_BINDINGS

// BOTTOM


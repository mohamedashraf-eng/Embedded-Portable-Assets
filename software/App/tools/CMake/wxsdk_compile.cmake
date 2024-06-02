set(
    wxsdk_sources_list

    ${app_sw}/core/main.c
    ${linkedlist_sw}/core/Wx_Static_LinkedList.c
    ${stack_sw}/core/Wx_Static_Stack.c
    ${queue_sw}/core/Wx_Static_Queue.c
)

set(
    wxsdk_includes

    ${app_sw}/core
    ${common_platform_includes}
    ${linkedlist_sw}/core
    ${queue_sw}/core
    ${stack_sw}/core
    ${tree_sw}/core
    ${graph_sw}/core
)

set(
    wxsdk_compile_options
)

set(
    wxsdk_defines
)

set(
    wxsdk_swc_libs
    
    "wxsdk_linkedlist"
    "wxsdk_queue"
    "wxsdk_stack"
)
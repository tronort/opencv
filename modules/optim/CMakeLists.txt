if (WINRT)
  ocv_module_disable(optim)
endif()

set(the_description "Generic optimization")
ocv_define_module(optim opencv_core)

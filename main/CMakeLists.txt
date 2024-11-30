set(srcs
main.c
connection.c
../specific_modules/adc_tools.c
)

idf_component_register(SRCS "main.c" "connection.c" "${srcs}"
                    INCLUDE_DIRS ".")

target_compile_options(${COMPONENT_LIB} PRIVATE  -Wno-format)

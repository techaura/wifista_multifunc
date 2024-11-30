set(srcs
main.c
connection.c
)

idf_component_register(SRCS "main.c" "connection.c" "${srcs}"
                    INCLUDE_DIRS ".")

target_compile_options(${COMPONENT_LIB} PRIVATE  -Wno-format)

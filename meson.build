# C project MTX v0.1.0.
project('mtx', 'c',
    version: '0.1.0'
)

# C source files to compile.
srcFiles = [
    'src/complex.c',
    'src/main.c'
]

# Actual C compiler used.
compiler = meson.get_compiler('c')

# Creates the mtx executable compiling all
# the source files with additional dependencies.
executable('mtx', srcFiles, dependencies: [
    compiler.find_library('m', required: true)
])

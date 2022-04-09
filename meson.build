# C project MTX v0.1.0.
project('mtx', 'c',
    version: '0.1.0'
)

# C source files to compile.
srcFiles = [
    'src/matrix.c',
    'src/complex.c',
    'src/main.c'
]

# Actual C compiler being used.
compiler = meson.get_compiler('c')

# Creates the executable compiling all the
# source files and libraries.
executable('mtx', srcFiles, dependencies: [
    compiler.find_library('m', required: true)
])

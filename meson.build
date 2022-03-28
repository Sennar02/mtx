project('mtx', 'c',
    version: '0.1.0'
)

cpr = meson.get_compiler('c')
src = ['src/matrix.c', 'src/complex.c', 'src/main.c']

executable('mtx', src, dependencies: [
    cpr.find_library('m', required: true)
])

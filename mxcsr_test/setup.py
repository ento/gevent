from setuptools import Extension, setup

setup(
    ext_modules = [Extension(
        "mxcsr", ["mxcsr.c"],
        extra_compile_args=["-O0"],
    )],
)

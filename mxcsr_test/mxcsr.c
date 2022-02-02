#include <Python.h>
#include <xmmintrin.h>

static PyObject* daz_enabled(void) {
  unsigned int mxcsr = _mm_getcsr();
  if (mxcsr & (1<<6)) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

static PyObject* ftz_enabled(void) {
  unsigned int mxcsr = _mm_getcsr();
  if (mxcsr & _MM_FLUSH_ZERO_MASK) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

static PyMethodDef methods[] = {
  {"ftz_enabled", (PyCFunction)ftz_enabled, METH_NOARGS, 0},
  {"daz_enabled", (PyCFunction)daz_enabled, METH_NOARGS, 0},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "mxcsr",
  NULL,
  -1,
  methods,
  NULL,
  NULL,
  NULL
};

PyMODINIT_FUNC PyInit_mxcsr(void)
{
  return PyModule_Create(&module);
}

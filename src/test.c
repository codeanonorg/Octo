#define PY_SSIZE_T_CLEAN
#include <Python.h>

/**
 * @brief Numbers of python modules loaded
 *
 */
static int modules_loaded = 0;

/**
 * @brief Numbers of working python modules loaded
 *
 */
static int working_modules_loaded = 0;

/**
 * @brief Simply say Hello to Octo from a python module
 *
 */
static PyObject *octo_hello(PyObject *self, PyObject *args) {
  if (!PyArg_ParseTuple(args, ":hello"))
    return NULL;
  printf("a module says hello to octo !\n");
  Py_RETURN_NONE;
}

static PyMethodDef octo_methods[] = {
    {"hello", octo_hello, METH_VARARGS, "Simply say hello."},
    {NULL, NULL, 0, NULL}};

static PyModuleDef octo_module = {PyModuleDef_HEAD_INIT,
                                  "octo",
                                  NULL,
                                  -1,
                                  octo_methods,
                                  NULL,
                                  NULL,
                                  NULL,
                                  NULL};

static PyObject *PyInit_octo() { return PyModule_Create(&octo_module); }

/**
 * @brief Executing functions from a python module
 */

int main(int argc, char const *argv[]) {

  PyObject *pName, *pModule, *pInit, *pRet;

  if (argc < 1) {
    fprintf(stderr, "Usage: %s pythonfile\n", argv[0]);
    return 1;
  }

  PyImport_AppendInittab("octo", &PyInit_octo);
  Py_Initialize();

  for (int i = 1; i < argc; i++) {
    pName = PyUnicode_DecodeFSDefault(argv[i]);
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
      printf("Successfully loaded the module [%s]\n", argv[i]);
      modules_loaded++;
      pInit = PyObject_GetAttrString(pModule, "init");
      if (pInit && PyCallable_Check(pInit)) {
        pRet = PyObject_CallObject(pInit, NULL);
        if (pRet != NULL) {
          Py_DECREF(pRet);
        } else {
          Py_DECREF(pInit);
          Py_DECREF(pModule);
          PyErr_Print();
          fprintf(stderr, "Call to init failed\n");
        }
        working_modules_loaded++;
      } else {
        if (PyErr_Occurred())
          PyErr_Print();
        fprintf(stderr, "Cannot find function \"init\"\n");
      }
      Py_XDECREF(pInit);
      Py_DECREF(pModule);
    } else {
      PyErr_Print();
      fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
    }
  }

  // Shut down the python interp
  printf("[%d/%d] modules loaded\n", modules_loaded, argc - 1);
  printf("[%d/%d] working modules\n", working_modules_loaded, modules_loaded);
  if (Py_FinalizeEx() < 0) {
    return 120;
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_list - display basic funtions
 * @p: object
 */
void print_python_list(PyObject *p)
{
	int k;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n",
	       ((PyVarObject *)p)->ob_size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (k = 0; k < ((PyVarObject *)p)->ob_size; k++)
	{
		printf("Element %d: %s\n", k,
		       ((PyListObject *)p)->ob_item[k]->ob_type->tp_name);
		if (!strcmp(((PyListObject *)p)->ob_item[k]->ob_type->tp_name,
			    "bytes"))
			print_python_bytes(((PyListObject *)p)->ob_item[k]);

	}
}

/**
 * print_python_bytes - python bytes
 * @p: object details
 */
void print_python_bytes(PyObject *p)
{
	size_t k, stre, cap;
	char *gp;

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes"))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	cap = ((PyVarObject *)p)->ob_size;
	gp = ((PyBytesObject *)p)->ob_sval;
	stre =  cap + 1 > 10 ? 10 : cap + 1;
	printf("  size: %lu\n", cap);
	printf("  trying string: %s\n", gp);
	printf("  first %lu bytes: ", stre);
	for (k = 0; k < stre; k++)
		printf("%02hhx%s", gp[k], k + 1 < stre ? " " : "");
	printf("\n");
}

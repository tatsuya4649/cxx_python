#include <iostream>
#include <stdio.h>
#include <Python.h>
#include <string>

int main(){
	PyObject *pName,*pModule,*pTmp,*pFunc;
	PyObject *pArgs,*pValue;
	double result;
	Py_Initialize();//must code this at first
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys,"path");
	PyList_Append(path,PyUnicode_DecodeFSDefault("../../python/"));
	//std::cout << "test" << std::endl;
	pName = PyUnicode_DecodeFSDefault("sample");
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);
	
	if(pModule != NULL){
		pFunc = PyObject_GetAttrString(pModule,"test");//setting pFunt to call function nam
		pTmp = PyObject_CallObject(pFunc,NULL);
		PyArg_Parse(pTmp,"d",&result);
	}
	Py_Finalize();//must code this at last
}

#pragma once
#include "mgl.hpp"

struct MGLContext;
struct MGLFramebuffer;
struct MGLSampler;
struct MGLBuffer;

struct MGLScopeSamplerBinding {
    union {
        PyObject * object;
        MGLSampler * sampler;
    };
    int binding;
};

struct MGLScopeBufferBinding {
    union {
        PyObject * object;
        MGLBuffer * buffer;
    };
    int target;
    int binding;
    Py_ssize_t offset;
    Py_ssize_t size;
};

struct MGLScope {
    PyObject_HEAD
    PyObject * wrapper;
    MGLContext * context;
    MGLFramebuffer * framebuffer;
    MGLFramebuffer * old_framebuffer;
    MGLScopeSamplerBinding * samplers;
    MGLScopeBufferBinding * buffers;
    MGLScope * old_scope;
    int num_samplers;
    int num_buffers;
    int enable_only;
    int old_enable_only;
};

extern PyType_Spec MGLScope_spec;
PyObject * MGLContext_meth_scope(MGLContext * self, PyObject * const * args, Py_ssize_t nargs);
void MGLScope_begin_core(MGLScope * self);
void MGLScope_end_core(MGLScope * self);

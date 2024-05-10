#include<pybind11/pybind11.h>
#include "LRUCache.h"

namespace py = pybind11;

PYBIND11_MODULE(lru, m) {
    py::class_<LRUCache<int, int>>(m, "LRUCache")
        .def(py::init<int>())
        .def("set", &LRUCache<int, int>::set)
        .def("get", &LRUCache<int, int>::get);
}
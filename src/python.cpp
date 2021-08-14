#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "remwave/remwave.h"

PYBIND11_MODULE(remwave, m) {
    py::class_<remwave::Scene>(m, "Scene")
        .def(py::init<>())
    ;
    py::class_<remwave::Camera>(m, "Camera")
        .def(py::init<>())
    ;
    py::class_<remwave::Target>(m, "Target")
        .def(py::init<>())
    ;
    py::class_<remwave::Renderer>(m, "Renderer")
        .def(py::init<>())
    ;
}


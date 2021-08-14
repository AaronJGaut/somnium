#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "somnium/somnium.h"

PYBIND11_MODULE(somnium, m) {
    py::class_<somnium::Scene>(m, "Scene")
        .def(py::init<>())
    ;
    py::class_<somnium::Camera>(m, "Camera")
        .def(py::init<>())
    ;
    py::class_<somnium::Target>(m, "Target")
        .def(py::init<>())
    ;
    py::class_<somnium::Renderer>(m, "Renderer")
        .def(py::init<>())
    ;
}


TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        estacionservicio.cpp \
        main.cpp \
        precioscombustible.cpp \
        surtidor.cpp \
        transaccion.cpp

HEADERS += \
    estacionservicio.h \
    precioscombustible.h \
    surtidor.h \
    transaccion.h

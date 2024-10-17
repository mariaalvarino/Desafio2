TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        estacionservicio.cpp \
        main.cpp \
        redestacion.cpp \
        surtidor.cpp \
        tanque.cpp \
        transaccion.cpp

HEADERS += \
    estacionservicio.h \
    preciocombustible.h \
    redestacion.h \
    surtidor.h \
    tanque.h \
    transaccion.h

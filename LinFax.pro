QT += widgets
TEMPLATE = app
TARGET = LinFax
INCLUDEPATH += .

LIBS += -laudiofile -lasound

# Input
HEADERS += src/config.h \
           src/Config.hpp \
           src/CorrectDialog.hpp \
           src/DisplayLevel.hpp \
           src/Error.hpp \
           src/FaxDemodulator.hpp \
           src/FaxImage.hpp \
           src/FaxModulator.hpp \
           src/FaxReceiver.hpp \
           src/FaxTransmitter.hpp \
           src/FaxWindow.hpp \
           src/File.hpp \
           src/FirFilter.hpp \
           src/HelpDialog.hpp \
           src/ImageWidget.hpp \
           src/LookUpTable.hpp \
           src/OptionsDialog.hpp \
           src/PTC.hpp \
           src/PTT.hpp \
           src/ReceiveDialog.hpp \
           src/Sound.hpp \
           src/Spectrum.hpp \
           src/ToolTipFilter.hpp \
           src/TransmitDialog.hpp
SOURCES += src/Config.cpp \
           src/CorrectDialog.cpp \
           src/DisplayLevel.cpp \
           src/Error.cpp \
           src/FaxDemodulator.cpp \
           src/FaxImage.cpp \
           src/FaxModulator.cpp \
           src/FaxReceiver.cpp \
           src/FaxTransmitter.cpp \
           src/FaxWindow.cpp \
           src/File.cpp \
           src/hamfax.cpp \
           src/HelpDialog.cpp \
           src/ImageWidget.cpp \
           src/OptionsDialog.cpp \
           src/PTC.cpp \
           src/PTT.cpp \
           src/ReceiveDialog.cpp \
           src/Sound.cpp \
           src/Spectrum.cpp \
           src/ToolTipFilter.cpp \
           src/TransmitDialog.cpp
TRANSLATIONS += po/hamfax_de.ts po/hamfax_fr.ts

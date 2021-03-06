
SOURCES += \
    wombatcombat/main.cpp \
    wombatcombat/Terrain.cpp \
    wombatcombat/GameContainer.cpp \
    wombatcombat/SensorData.cpp \
    wombatcombat/Player.cpp \
    wombatcombat/CreatureData.cpp \
    wombatcombat/Creature.cpp \
    wombatcombat/ControlHandler.cpp \
    wombatcombat/Camera.cpp \
    wombatcombat/BaseGame.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lBox2D

HEADERS += \
    wombatcombat/Terrain.h \
    wombatcombat/GameContainer.h \
    wombatcombat/SensorData.h \
    wombatcombat/Player.h \
    wombatcombat/enums.h \
    wombatcombat/CreatureData.h \
    wombatcombat/Creature.h \
    wombatcombat/ControlHandler.h \
    wombatcombat/ContactListener.h \
    wombatcombat/Camera.h \
    wombatcombat/BaseGame.h

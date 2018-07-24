CONFIG += debug_and_release
CONFIG(debug, debug|release){
    MOC_DIR       = ./debug/moc
    RCC_DIR       = ./debug/rcc
    UI_DIR        = ./debug/ui
    OBJECTS_DIR   = ./debug/obj
    DESTDIR       = ./debug/bin
}else{
    MOC_DIR       = ./release/moc
    RCC_DIR       = ./release/rcc
    UI_DIR        = ./release/ui
    OBJECTS_DIR   = ./release/obj
    DESTDIR       = ./release/bin
}

RC_FILE += config/app.rc

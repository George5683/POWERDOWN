#include "remote.hpp"
#include <IRProtocol.h>
#include <IRremoteInt.h>
// _____________________________Remote Class_______________________________________________
remote::remote(std::string brandname, int IR_PIN) : Brand(brandname) {
    IrSender.begin(IR_PIN);
}

remote::~remote() {
    // Destructor 
}

std::string remote::getBrand() const {
    return Brand;
}

// _____________________________Samsung Class_______________________________________________
Samsung::Samsung(int IR_PIN) : remote("Samsung", IR_PIN) {
    
}

Samsung::~Samsung() {
    // Destructor implementation
}

void Samsung::TV_ON() {
    IrSender.sendSamsung(address, 0x02, 0);
}

void Samsung::TV_OFF() {
    IrSender.sendSamsung(address, 0x02, 0); 
}

void Samsung::TV_VOL_UP() {
    IrSender.sendSamsung(address, 0x07, 0);
}

void Samsung::TV_VOL_DOWN() {
    IrSender.sendSamsung(address, 0xB, 0);
}

void Samsung::TV_CH_UP() {
    IrSender.sendSamsung(address, 0x12, 0);
}

void Samsung::TV_CH_DOWN() {
    IrSender.sendSamsung(address, 0x10, 0);
}

void Samsung::TV_MUTE() {
    IrSender.sendSamsung(address, 0xF, 0);
}

void Samsung::TV_0() {
    IrSender.sendSamsung(address, 0x11, 0);
}

void Samsung::TV_1() {
    IrSender.sendSamsung(address, 0x4, 0);
}

void Samsung::TV_2() {
    IrSender.sendSamsung(address, 0x5, 0);
}

void Samsung::TV_3() {
    IrSender.sendSamsung(address, 0x6, 0);
}

void Samsung::TV_4() {
    IrSender.sendSamsung(address, 0x7, 0);
}

void Samsung::TV_5() {
    IrSender.sendSamsung(address, 0x8, 0);
}

void Samsung::TV_6() {
    IrSender.sendSamsung(address, 0x9, 0);
}

void Samsung::TV_7() {
    IrSender.sendSamsung(address, 0xC, 0);
}

void Samsung::TV_8() {
    IrSender.sendSamsung(address, 0xD, 0);
}

void Samsung::TV_9() {
    IrSender.sendSamsung(address, 0xE, 0);
}

void Samsung::TV_SMART_MENU() {
    IrSender.sendSamsung(address, 0x1A, 0);
}

void Samsung::TV_UP() {
    IrSender.sendSamsung(address, 0x1E, 0);
}

void Samsung::TV_DOWN() {
    IrSender.sendSamsung(address, 0x1F, 0);
}   

void Samsung::TV_LEFT() {
    IrSender.sendSamsung(address, 0x1D, 0);
}

void Samsung::TV_RIGHT() {
    IrSender.sendSamsung(address, 0x1C, 0);
}

void Samsung::TV_SELECT() {
    IrSender.sendSamsung(address, 0x1B, 0);
}

void Samsung::TV_EXIT() {
    IrSender.sendSamsung(address, 0x1A, 0);
}

void Samsung::TV_RETURN() {
    IrSender.sendSamsung(address, 0x1A, 0);
}

void Samsung::TV_SOURCE() {
    IrSender.sendSamsung(address, 0x1A, 0);
}

// _____________________________LG Class_______________________________________________
LG::LG(int IR_PIN) : remote("LG", IR_PIN) {
    // Constructor
}

LG::~LG() {
    // Destructor implementation
}
void LG::TV_ON() {
    // 0x20DF10EF becomes address: 0x20DF, command: 0x10
    IrSender.sendLG(address, 0x10, 0); 
}

void LG::TV_OFF() {
    // 0x20DF906F becomes address: 0x20DF, command: 0x90
    IrSender.sendLG(address, 0x90, 0); 
}

void LG::TV_VOL_UP() {
    IrSender.sendLG(address, 0x40, 0); 
}

void LG::TV_VOL_DOWN() {
    IrSender.sendLG(address, 0xC0, 0); 
}

void LG::TV_CH_UP() {
    IrSender.sendLG(address, 0x80, 0); 
}

void LG::TV_CH_DOWN() {
    IrSender.sendLG(address, 0x20, 0); 
}

void LG::TV_MUTE() {
    IrSender.sendLG(address, 0xF0, 0); 
}

void LG::TV_0() {
    IrSender.sendLG(address, 0x60, 0);
}

void LG::TV_1() {
    IrSender.sendLG(address, 0x00, 0);
}

void LG::TV_2() {
    IrSender.sendLG(address, 0x20, 0);
}

void LG::TV_3() {
    IrSender.sendLG(address, 0xA0, 0);
}

void LG::TV_4() {
    IrSender.sendLG(address, 0x60, 0);
}

void LG::TV_5() {
    IrSender.sendLG(address, 0xE0, 0);
}

void LG::TV_6() {
    IrSender.sendLG(address, 0x10, 0);
}

void LG::TV_7() {
    IrSender.sendLG(address, 0x90, 0);
}

void LG::TV_8() {
    IrSender.sendLG(address, 0x48, 0);
}

void LG::TV_9() {
    IrSender.sendLG(address, 0xC8, 0);
}

void LG::TV_SMART_MENU() {
    IrSender.sendLG(address, 0x88, 0);
}

void LG::TV_UP() {
    IrSender.sendLG(address, 0x08, 0);
}

void LG::TV_DOWN() {
    IrSender.sendLG(address, 0x88, 0);
}

void LG::TV_LEFT() {
    IrSender.sendLG(address, 0x04, 0);
}

void LG::TV_RIGHT() {
    IrSender.sendLG(address, 0x84, 0);
}

void LG::TV_SELECT() {
    IrSender.sendLG(address, 0x44, 0);
}

void LG::TV_EXIT() {
    IrSender.sendLG(address, 0x88, 0);
}

void LG::TV_RETURN() {
    IrSender.sendLG(address, 0x88, 0);
}

void LG::TV_SOURCE() {
    IrSender.sendLG(address, 0x88, 0);
}

#include "remote.hpp"
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

// _____________________________LG Class_______________________________________________
LG::LG(int IR_PIN) : remote("LG", IR_PIN) {
    // Constructor
}

LG::~LG() {
    // Destructor implementation
}
void LG::TV_ON() {
    IrSender.sendLG(address, 0x20DF10EF, 0);
}

void LG::TV_OFF() {
    IrSender.sendLG(address, 0x20DF906F, 0);
}

void LG::TV_VOL_UP() {
    IrSender.sendLG(address, 0x20DF40BF, 0);
}

void LG::TV_VOL_DOWN() {
    IrSender.sendLG(address, 0x20DFC03F, 0);
}

void LG::TV_CH_UP() {
    IrSender.sendLG(address, 0x20DF807F, 0);
}

void LG::TV_CH_DOWN() {
    IrSender.sendLG(address, 0x20DF20DF, 0);
}

void LG::TV_MUTE() {
    IrSender.sendLG(address, 0x20DFF00F, 0);
}

void LG::TV_0() {
    IrSender.sendLG(address, 0x20DF609F, 0);
}

void LG::TV_1() {
    IrSender.sendLG(address, 0x20DF00FF, 0);
}

void LG::TV_2() {
    IrSender.sendLG(address, 0x20DF20DF, 0);
}

void LG::TV_3() {
    IrSender.sendLG(address, 0x20DFA05F, 0);
}

void LG::TV_4() {
    IrSender.sendLG(address, 0x20DF609F, 0);
}

void LG::TV_5() {
    IrSender.sendLG(address, 0x20DFE01F, 0);
}

void LG::TV_6() {
    IrSender.sendLG(address, 0x20DF10EF, 0);
}

void LG::TV_7() {
    IrSender.sendLG(address, 0x20DF906F, 0);
}

void LG::TV_8() {
    IrSender.sendLG(address, 0x20DF48B7, 0);
}

void LG::TV_9() {
    IrSender.sendLG(address, 0x20DFC837, 0);
}

#include "remote.hpp"
// _____________________________Remote Class_______________________________________________
remote::remote(std::string brandname) : Brand(brandname) {
    // Constructor 
}

remote::~remote() {
    // Destructor 
}

std::string remote::getBrand() const {
    return Brand;
}

// _____________________________Samsung Class_______________________________________________
Samsung::Samsung() : remote("Samsung") {
    
}

Samsung::~Samsung() {
    // Destructor implementation
}

// _____________________________LG Class_______________________________________________
LG::LG() : remote("LG") {
    // Constructor
}

LG::~LG() {
    // Destructor implementation
}

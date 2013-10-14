#ifndef FURNITURE
#define FURNITURE
#include "primative.h"

class floor {
};

class chair {
};

class table {
};

class fileCabinet {
};

class lamp {
};

class furniture : public floor, public chair, public table, public fileCabinet, public lamp {
};


#endif
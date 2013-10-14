#ifndef FURNITURE
#define FURNITURE
#include "primative.h"

class chair {
};

class table {
};

class fileCabinet {
};

class lamp {
};

class furniture : public chair, public table, public fileCabinet, public lamp {
};


#endif